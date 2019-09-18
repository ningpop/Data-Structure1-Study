/*
	작성일: 2019.05.27
	작성자: 20154015 이남준
	프로그램명: 연결리스트 실습1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char node_team[5]; // 팀 이름 저장 문자배열
	char node_name[5]; // 이름 저장 문자배열
	int node_score; // 점수
} element;

typedef struct ListNode{ // 구조체로 정의한 노드 연결리스트
	element data;
	struct ListNode *link;
} ListNode;

void error(char *message) // error 메시지 함수
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// phead: 리스트의 헤드 포인터의 포인터, p: 선행 노드, new_node: 삽입될 노드
void insert_node(ListNode **phead, ListNode *p, ListNode *new_node) // node 삽입 함수
{
	if(*phead == NULL) // 공백 리스트인 경우0
	{
		new_node->link = NULL;
		*phead = new_node;
	}
	else if(p == NULL) // p가 NULL이면 첫 번째 노드로 삽입
	{
		new_node->link = *phead;
		*phead = new_node;
	}
	else // p 다음에 삽입
	{
		new_node->link = p->link;
		p->link = new_node;
	}
}

void display(ListNode *head) // 리스트 방문
{
	ListNode *p = head;
	while(p != NULL)
	{
		if(p->link == NULL) // 마지막 node라면 화살표 미출력
			printf("이름:%s 점수:%d", p->data.node_name, p->data.node_score);
		else // node의 default 출력
			printf("이름:%s 점수:%d->", p->data.node_name, p->data.node_score);
		p = p->link; // 다음 node로 이동
	}
	printf("\n");
}

int total(ListNode *head) // 연결리스트의 data값 총 합 구하는 함수
{
	ListNode *p = head;
	int total = 0;

	while (p != NULL)
	{
		total += p->data.node_score; // node의 점수값을 total에 계속 더함
		p = p->link; // 다음 node로 이동
	}
	return total;
}

ListNode *reverse(ListNode *head) // 연결리스트 역순으로 바꾸는 함수
{
	ListNode *p, *q, *r; // 역순으로 바꾸기 위한 3개의 node 선언
	p = head; // 역순으로 바꿀 연결리스트
	q = NULL; // node p를 따라가면서 역순으로 바꿔줄 node
	while (p != NULL)
	{
		r = q; // node q를 따라가면서 node q의 link를 받는다
		q = p; // p의 link를 받아 따라오는 node q
		p = p->link; // p는 다음 node로 이동
		q->link = r; // node r은 q의 link로 연결되어 역순으로 리스트 연결
	}
	return q; // 끝까지 역순작업 후 head부분으로 변경되게 되는 q를 반환
}

ListNode *create_node(element data, ListNode *link) // 새로운 node 생성
{
	ListNode *new_node;
	new_node = (ListNode *)malloc(sizeof(ListNode)); // ListNode만큼 크기의 새로운 node 생성
	if (new_node == NULL)
		error("메모리 할당 에러");
	new_node->data = data; // data 삽입
	new_node->link = link; // link 삽입
	return (new_node);
}

int main(void)
{
	FILE *fp = NULL; // 파일 포인터 선언
	element temp; // 파일에서 data를 읽으면서 저장할 임시 구조체
	ListNode *list1 = NULL, *list2 = NULL; // 청팀, 백팀을 저장할 연결리스트
	int total1 = 0, total2 = 0; // 청팀, 백팀의 총점을 저장할 변수

	fp = fopen("data.txt", "r"); // 파일포인터를 이용해 data.txt파일을 읽기모드로 연다.
	if (fp == NULL) // 파일포인터가 NULL이라면
	{
		printf("파일 열기 실패\n"); // 경고문 출력하고
		exit(1); // 프로그램 종료
	}

	while (!feof(fp)) // 파일의 끝까지 반복
	{
		fscanf(fp, "%s %s %d", temp.node_team, temp.node_name, &temp.node_score); // 팀 이름, 이름, 점수를 읽어 임시구조체에 저장
		if (!strcmp(temp.node_team, "청팀")) // 읽은 data가 청팀이라면
			insert_node(&list1, NULL, create_node(temp, NULL)); // 청팀 연결리스트에 node를 이어붙인다.(head부터)
		else // 읽은 data가 백팀이라면
			insert_node(&list2, NULL, create_node(temp, NULL)); // 백팀 연결리스트에 node를 이어붙인다.(head부터)
	}

	fclose(fp); // fclose로 파일 닫음

	printf("List1 : \n");
	list1 = reverse(list1); // insert_node함수를 실행하면서 head에 계속 node를 이어붙였으므로 역순변환처리
	display(list1); // list1 출력

	printf("\n\n");

	printf("List2 : \n");
	list2 = reverse(list2); // insert_node함수를 실행하면서 head에 계속 node를 이어붙였으므로 역순변환처리
	display(list2); // list2 출력

	total1 = total(list1); // 청팀의 점수 총합을 계산
	total2 = total(list2); // 백팀의 점수 총합을 계산
	printf("\n\n총점 %d점 vs %d점\n\n", total1, total2);

	if(total1 > total2)
		printf("청팀 승리\n");
	else
		printf("백팀 승리\n");

	return 0;
}