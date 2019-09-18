/*
	�ۼ���: 2019.05.28
	�ۼ���: 20154015 �̳���
	���α׷���: ���Ḯ��Ʈ�� �̿��� �ؼ��� ���� �ŵ����� ��� ���α׷�
*/

#include <stdio.h>
#include <stdlib.h>

// ��� ����ü ����
typedef struct{
	int down; // �ؼ�
	int up; // ����
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

// �ؼ��� ���� �ŵ����� ���� �Լ�
int mulResult(ListNode *p)
{
	int i, total = 1;

	for(i = 0; i < p->data.up; i++) // ������ ũ�⸸ŭ �ݺ�
	{
		total *= p->data.down; // total�� �ؼ��� �����Ͽ� ����
	}
	return total;
}

// ����Ʈ �湮
void display(ListNode *head)
{
	ListNode *p = head;
	int total = 0;
	while(p != NULL)
	{
		total += mulResult(p); // ���Ḯ��Ʈ�� ��带 �ϳ��� �ŵ����� ���� �Լ��� �̿��� ���� ����
		printf("%d %d -> ���� ��� ��� = %d\n", p->data.down, p->data.up, total);
		p = p->link; // ���� ���� ����
	}
	printf("����� %d�Դϴ�.\n", total); // ���� ���
}

// ����Ʈ ���� ����
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
	element temp; // �ӽó�� ����
	ListNode *list = NULL; // �ؼ��� ������ ����ִ� ���Ḯ��Ʈ ����
	int i = 5;

	for(i = 0; i < 5; i++)
	{
		printf("�ؼ��� ������ �Է��Ͻÿ� : ");
		scanf("%d %d", &temp.down, &temp.up); // �Է¹��� ������ �ӽó�忡 ����
		insert_node(&list, NULL, create_node(temp, NULL)); // �ӽó�带 ���Ḯ��Ʈ�� ����
	}

	list = reverse(list); // �Ųٷ� �����߱⿡ ��������
	display(list); // �ؼ��� ������ ���� �Բ� ���Ḯ��Ʈ ���

	return 0;
}