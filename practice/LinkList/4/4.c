/*
	�ۼ���: 2019.06.04
	�ۼ���: 20154015 �̳���
	���α׷���: ���Ḯ��Ʈ�� �̿��� ����� ������ ����/���� ���α׷�
*/

#include <stdio.h>
#include <stdlib.h>

// ��� ����ü ����
typedef struct{
	int number;
} element;

// ���Ḯ��Ʈ ����ü ����
typedef struct ListNode{
	element data;
	struct ListNode *link;
} ListNode;

// ���� �޽��� ��� �Լ�
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// phead: ����Ʈ�� ��� �������� ������, p: ���� ���, new_node: ���Ե� ���
void insert_node(ListNode **phead, ListNode *p, ListNode *new_node)
{
	if(*phead == NULL) // ���� ����Ʈ�� ���
	{
		new_node->link = NULL;
		*phead = new_node;
	}
	else if(p == NULL) // p�� NULL�̸� ù ��° ���� ����
	{
		new_node->link = *phead;
		*phead = new_node;
	}
	else // p ������ ����
	{
		new_node->link = p->link;
		p->link = new_node;
	}
}

// ¦���� ���� �Լ�
// phead: ����Ʈ�� ��� �������� ������
void remove_node(ListNode **phead)
{
	ListNode *p = *phead; // ���� ����Ʈ�� ���
	ListNode *removed; // ������ ���

	while (p->link != NULL) // p�� ���� ��尡 NULL�϶����� �ݺ�
	{
		removed = p->link; // p�� ������带 ������ ���� ����
		if (removed->link == NULL) // ������ ��尡 ������ ����϶�
		{
			p->link = NULL; // p�� ������ ���� ����
			free(removed); // removed ��� �޸� �Ҵ� ����
		}
		else // ������ ��尡 ������ ��尡 �ƴҶ�
		{
			p->link = removed->link; // ������ ����� ���� ��带 p�� link�� ����
			free(removed); // removed ��� �޸� �Ҵ� ����
			p = p->link; // p�� ���� ���� ����
		}
	}
}

// ����Ʈ �湮
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

// �ű� ��� ����
ListNode *create_node(element data, ListNode *link)
{
	ListNode *new_node;
	new_node = (ListNode *)malloc(sizeof(ListNode));
	if(new_node == NULL)
		error("�޸� �Ҵ� ����");
	new_node->data = data;
	new_node->link = link;
	return (new_node);
}

int main(void)
{
	ListNode *list = NULL; // ���� ����Ʈ ����
	element temp; // �Է¹ް� ����Ʈ�� ������ �ӽ� ��� ����
	int order; // ��ɰ��� ���� ���� ����

	while(1)
	{
		printf("(1:����Ʈ�� �� �ֱ�, 2: ����Ʈ�� ¦����° �� ����, -1 ����): ");
		scanf("%d", &order);

		switch(order)
		{
		case 1:
			printf("����Ʈ�� ���� ���� �Է��ϼ��� : ");
			scanf("%d", &temp.number); // �ӽ� ��忡 ���� ����
			insert_node(&list, NULL, create_node(temp, NULL)); // ����Ʈ�� �ӽ� ��� ����
			display(list); // ����Ʈ �湮�ϸ鼭 ���
			break;
		case 2:
			printf("����Ʈ�� ¦����°�� �����մϴ�.\n");
			remove_node(&list); // ����Ʈ ¦���� ���� �Լ��� ����Ʈ �ּҸ� �Ű������� �ѱ�
			display(list); // ����Ʈ �湮�ϸ鼭 ���
			break;
		case -1:
			return 0;
		default:
			break;
		}
	}

	return 0;
}