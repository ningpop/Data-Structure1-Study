/*
	작성일: 2019.05.30
	작성자: 20154015 이남준
	프로그램명: 연결리스트를 이용한 2개의 다항식 곱셈 연산 프로그램
*/

#include <stdio.h>
#include <stdlib.h>

// 노드 타입
typedef struct ListNode {
	int coef; // 계수
	int expon; // 지수
	struct ListNode *link;
} ListNode;

// 연결리스트 헤더
typedef struct ListType {
	ListNode *head;
	ListNode *tail;
} ListType;

//오류 함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 리스트 헤더 생성
ListType* create()
{
	ListType *plist = (ListType *)malloc(sizeof(ListType));
	plist->head = plist->tail = NULL;
	return plist;
}

//plist는 연결 리스트의 헤더를 가리키는 포인터, coef는 계수, expon는 지수
void insert_last(ListType* plist, int coef, int expon)
{
	ListNode* temp = (ListNode *)malloc(sizeof(ListNode)); // 리스트에 삽입할 임시 노드
	if (temp == NULL)
		error("메모리 할당 에러");
	temp->coef = coef; // 계수를 임시 노드에 저장
	temp->expon = expon; // 지수를 임시 노드에 저장
	temp->link = NULL; // link를 NULL로 지정
	if (plist->tail == NULL) // 리스트가 비어있다면
		plist->head = plist->tail = temp; // 리스트에 임시노드를 삽입하고 head와 tail 모두 노드를 가리키게 설정
	else // 리스트가 비어있지 않다면
	{
		plist->tail->link = temp; // 리스트의 마지막 노드의 link가 임시 노드를 가리킴
		plist->tail = temp; // 리스트에 새로 붙인 임시 노드를 tail로 지정
	}
}

//list3 = list1 * list2
ListType* poly_multiple(ListType* plist1, ListType* plist2)
{
	ListNode* a = plist1->head; // 다항식 1 리스트를 따라갈 노드
	ListNode* b = plist2->head; // 다항식 2 리스트를 따라갈 노드
	ListType* multi = create(); // 다항식 단순 곱셈 리스트
	ListType* result = create(); // 정렬된 최종 곱셈 다항식 리스트 
	ListNode* temp; // 정렬시 multi 리스트를 따라가며 사용할 임시 노드
	int ResultExpon; // 리스트 정렬에 사용할 최고차항 지수
	int SumCoef; // 계수 합
	
	// 다항식 1, 2 리스트를 단순 곱셈 연산하기 위한 반복문
	while (a != NULL) // 다항식 1의 맨 끝에 도달할때까지 반복
	{
		while (b != NULL) // 다항식 2의 맨 끝에 도달할때까지 반복
		{
			insert_last(multi, a->coef * b->coef, a->expon + b->expon); // 다항식 1, 2의 해당 노드를 단순 곱셈하여 multi 리스트에 저장
			b = b->link; // 다항식 2 리스트의 노드 한칸 전진
		}
		a = a->link; // 다항식 1 리스트의 노드 한칸 전진
		b = plist2->head; // 다항식 2 리스트 맨 앞 head로 초기화
	}

	// 다항식 리스트를 정렬하기 위한 반복문
	// 최고차항의 지수를 단순곱셈 리스트의 첫 항의 지수로 지정하고 -1이 될때까지 1씩 감소
	for (ResultExpon = multi->head->expon; ResultExpon != -1; ResultExpon--)
	{
		SumCoef = 0; // 같은 항의 계수를 더해 저장할 변수를 0으로 초기화
		temp = multi->head; // 단순 곱셈 리스트의 맨 처음 위치로 임시 노드를 지정
		while (temp != NULL) // 노드가 단순 곱셈 리스트의 끝에 도달할때까지
		{
			if (ResultExpon == temp->expon) // 최고차항의 지수와 임시노드가 가리키는 지수가 같다면
				SumCoef += temp->coef; // 같은 차수의 항이므로 계수들을 더함
			temp = temp->link; // 노드 한칸 전진
		}
		if(SumCoef != 0) // 계수의 합이 0이 아니라면(해당 차수의 항이 있다면)
			insert_last(result, SumCoef, ResultExpon); // 계수의 합과 현재 지수를 result 리스트에 저장
	}

	return result;
}

// 리스트 출력 함수
void poly_print(char polynomial[10], ListType* plist)
{
	ListNode* p = plist->head; // 리스트의 head를 가리키는 노드 하나 생성

	printf("%s =", polynomial); // 입력받은 다항식의 이름 출력
	for (; p; p = p->link) // 리스트의 head가 NULL일때까지 반복하며 노드 하나씩 전진
	{
		if (p->coef < 0) // 노드 p의 계수가 음수이면
			printf(" %dx^%d", p->coef, p->expon); // 부호 출력하지 않고 계수의 부호 그대로 사용
		else // 노드 p의 계수가 양수이면
		{
			if(p == plist->head) // 노드 p가 리스트의 head일때
				printf(" %dx^%d", p->coef, p->expon); // 계수가 양수인 초항은 부호 출력하지 않음
			else // 노드 p가 리스트의 중간이나 마지막일때
				printf(" + %dx^%d", p->coef, p->expon); // 계수가 양수이므로 항끼리 연결할 + 부호 출력
		}
	}
	printf("\n");
}

int main(void)
{
	FILE *fp = NULL;
	char polynomial[10]; // 다항식 이름을 받기 위한 문자열
	ListNode ReadTemp; // 파일에서 읽어 저장할 임시 노드
	ListType *list1, *list2, *list3; // list1: 다항식 1, list2: 다항식 2, list3: 다항식 3

	// 연결리스트 헤더 생성
	list1 = create();
	list2 = create();
	list3 = create();

	fp = fopen("data.txt", "r"); // data.txt파일을 읽기모드로 열기
	if (fp == NULL) // 파일포인터가 NULL이면
	{
		printf("파일 열기 실패\n"); // 오류 메시지 출력
		exit(1);
	}

	fscanf(fp, "%s", polynomial); // data.txt파일에서 처음으로 다항식 이름을 읽고 문자열에 저장
	while (fscanf(fp, "%d %d", &ReadTemp.coef, &ReadTemp.expon) == 2) // 정수 두개를 읽어 임시 노드에 저장하며 반환값이 2가 아닐때까지 반복
		insert_last(list1, ReadTemp.coef, ReadTemp.expon); // 읽은 정수 두개를 list1에 저장
	poly_print(polynomial, list1); // 다항식 이름과 함께 list1 출력

	fscanf(fp, "%s", polynomial); // data.txt파일에서 다항식 이름을 읽고 문자열에 저장
	while (fscanf(fp, "%d %d", &ReadTemp.coef, &ReadTemp.expon) == 2) // 정수 두개를 읽어 임시 노드에 저장하며 반환값이 2가 아닐때까지 반복
		insert_last(list2, ReadTemp.coef, ReadTemp.expon); // 읽은 정수 두개를 list2에 저장
	poly_print(polynomial, list2); // 다항식 이름과 함께 list2 출력

	fclose(fp); // 파일 닫기

	list3 = poly_multiple(list1, list2); // list1과 list2를 곱하여 list3에 저장

	poly_print("Result", list3); // list3 출력

	// 연결리스트 메모리 할당 해제
	free(list1);
	free(list2);
	free(list3);

	return 0;
}