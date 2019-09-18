/*
	작성일: 2019.05.28
	작성자: 20154015 이남준
	프로그램명: 연결리스트를 이용한 밑수와 지수 거듭제곱 계산 프로그램
*/

#include <stdio.h>
#include <stdlib.h>

// 노드 구조체 생성
typedef struct{
	int down; // 밑수
	int up; // 지수
} element;

// 연결리스트 구조체 생성
typedef struct ListNode{
	element data;
	struct ListNode *link;
} ListNode;

// 에러 메시지 출력 함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// phead: 리스트의 헤드 포인터의 포인터, p: 선행 노드, new_node: 삽입될 노드
void insert_node(ListNode **phead, ListNode *p, ListNode *new_node)
{
	if(*phead == NULL) // 공백 리스트인 경우
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

// 밑수와 지수 거듭제곱 연산 함수
int mulResult(ListNode *p)
{
	int i, total = 1;

	for(i = 0; i < p->data.up; i++) // 지수의 크기만큼 반복
	{
		total *= p->data.down; // total에 밑수를 누적하여 곱셈
	}
	return total;
}

// 리스트 방문
void display(ListNode *head)
{
	ListNode *p = head;
	int total = 0;
	while(p != NULL)
	{
		total += mulResult(p); // 연결리스트의 노드를 하나씩 거듭제곱 연산 함수를 이용해 누적 덧셈
		printf("%d %d -> 까지 계산 결과 = %d\n", p->data.down, p->data.up, total);
		p = p->link; // 다음 노드로 전진
	}
	printf("결과는 %d입니다.\n", total); // 총합 출력
}

// 리스트 역순 정렬
ListNode *reverse(ListNode *head)
{
	ListNode *p, *q, *r;
	p = head;
	q = NULL;
	while(p != NULL)
	{
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	return q;
}

// 신규 노드 생성
ListNode *create_node(element data, ListNode *link)
{
	ListNode *new_node;
	new_node = (ListNode *)malloc(sizeof(ListNode));
	if(new_node == NULL)
		error("메모리 할당 에러");
	new_node->data = data;
	new_node->link = link;
	return (new_node);
}

int main(void)
{
	element temp; // 임시노드 선언
	ListNode *list = NULL; // 밑수와 지수를 담고있는 연결리스트 선언
	int i = 5;

	for(i = 0; i < 5; i++)
	{
		printf("밑수와 지수를 입력하시오 : ");
		scanf("%d %d", &temp.down, &temp.up); // 입력받은 정수를 임시노드에 저장
		insert_node(&list, NULL, create_node(temp, NULL)); // 임시노드를 연결리스트에 삽입
	}

	list = reverse(list); // 거꾸로 삽입했기에 역순정렬
	display(list); // 밑수와 지수의 계산과 함께 연결리스트 출력

	return 0;
}