/*
	작성일: 2019.06.04
	작성자: 20154015 이남준
	프로그램명: 연결리스트를 이용한 사용자 선택적 삽입/삭제 프로그램
*/

#include <stdio.h>
#include <stdlib.h>

// 노드 구조체 생성
typedef struct{
	int number;
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

// 짝수항 삭제 함수
// phead: 리스트의 헤드 포인터의 포인터
void remove_node(ListNode **phead)
{
	ListNode *p = *phead; // 원본 리스트의 헤드
	ListNode *removed; // 삭제될 노드

	while (p->link != NULL) // p의 다음 노드가 NULL일때까지 반복
	{
		removed = p->link; // p의 다음노드를 삭제될 노드로 지정
		if (removed->link == NULL) // 삭제될 노드가 마지막 노드일때
		{
			p->link = NULL; // p를 마지막 노드로 지정
			free(removed); // removed 노드 메모리 할당 해제
		}
		else // 삭제될 노드가 마지막 노드가 아닐때
		{
			p->link = removed->link; // 삭제될 노드의 다음 노드를 p의 link에 연결
			free(removed); // removed 노드 메모리 할당 해제
			p = p->link; // p는 다음 노드로 전진
		}
	}
}

// 리스트 방문
void display(ListNode *head)
{
	ListNode *p = head;
	while(p != NULL)
	{
		if(p->link == NULL)
			printf("%d", p->data.number);
		else
			printf("%d ->", p->data.number);
		p = p->link;
	}
	printf("\n");
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
	ListNode *list = NULL; // 메인 리스트 선언
	element temp; // 입력받고 리스트에 저장할 임시 노드 선언
	int order; // 명령값을 담을 변수 선언

	while(1)
	{
		printf("(1:리스트에 값 넣기, 2: 리스트에 짝수번째 항 삭제, -1 종료): ");
		scanf("%d", &order);

		switch(order)
		{
		case 1:
			printf("리스트에 넣을 값을 입력하세요 : ");
			scanf("%d", &temp.number); // 임시 노드에 값을 저장
			insert_node(&list, NULL, create_node(temp, NULL)); // 리스트에 임시 노드 삽입
			display(list); // 리스트 방문하면서 출력
			break;
		case 2:
			printf("리스트의 짝수번째를 삭제합니다.\n");
			remove_node(&list); // 리스트 짝수항 삭제 함수에 리스트 주소를 매개변수로 넘김
			display(list); // 리스트 방문하면서 출력
			break;
		case -1:
			return 0;
		default:
			break;
		}
	}

	return 0;
}