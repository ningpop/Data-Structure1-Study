/*
	�ۼ���: 2019.05.27
	�ۼ���: 20154015 �̳���
	���α׷���: ���Ḯ��Ʈ �ǽ�1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char node_team[5]; // �� �̸� ���� ���ڹ迭
	char node_name[5]; // �̸� ���� ���ڹ迭
	int node_score; // ����
} element;

typedef struct ListNode{ // ����ü�� ������ ��� ���Ḯ��Ʈ
	element data;
	struct ListNode *link;
} ListNode;

void error(char *message) // error �޽��� �Լ�
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// phead: ����Ʈ�� ��� �������� ������, p: ���� ���, new_node: ���Ե� ���
void insert_node(ListNode **phead, ListNode *p, ListNode *new_node) // node ���� �Լ�
{
	if(*phead == NULL) // ���� ����Ʈ�� ���0
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

void display(ListNode *head) // ����Ʈ �湮
{
	ListNode *p = head;
	while(p != NULL)
	{
		if(p->link == NULL) // ������ node��� ȭ��ǥ �����
			printf("�̸�:%s ����:%d", p->data.node_name, p->data.node_score);
		else // node�� default ���
			printf("�̸�:%s ����:%d->", p->data.node_name, p->data.node_score);
		p = p->link; // ���� node�� �̵�
	}
	printf("\n");
}

int total(ListNode *head) // ���Ḯ��Ʈ�� data�� �� �� ���ϴ� �Լ�
{
	ListNode *p = head;
	int total = 0;

	while (p != NULL)
	{
		total += p->data.node_score; // node�� �������� total�� ��� ����
		p = p->link; // ���� node�� �̵�
	}
	return total;
}

ListNode *reverse(ListNode *head) // ���Ḯ��Ʈ �������� �ٲٴ� �Լ�
{
	ListNode *p, *q, *r; // �������� �ٲٱ� ���� 3���� node ����
	p = head; // �������� �ٲ� ���Ḯ��Ʈ
	q = NULL; // node p�� ���󰡸鼭 �������� �ٲ��� node
	while (p != NULL)
	{
		r = q; // node q�� ���󰡸鼭 node q�� link�� �޴´�
		q = p; // p�� link�� �޾� ������� node q
		p = p->link; // p�� ���� node�� �̵�
		q->link = r; // node r�� q�� link�� ����Ǿ� �������� ����Ʈ ����
	}
	return q; // ������ �����۾� �� head�κ����� ����ǰ� �Ǵ� q�� ��ȯ
}

ListNode *create_node(element data, ListNode *link) // ���ο� node ����
{
	ListNode *new_node;
	new_node = (ListNode *)malloc(sizeof(ListNode)); // ListNode��ŭ ũ���� ���ο� node ����
	if (new_node == NULL)
		error("�޸� �Ҵ� ����");
	new_node->data = data; // data ����
	new_node->link = link; // link ����
	return (new_node);
}

int main(void)
{
	FILE *fp = NULL; // ���� ������ ����
	element temp; // ���Ͽ��� data�� �����鼭 ������ �ӽ� ����ü
	ListNode *list1 = NULL, *list2 = NULL; // û��, ������ ������ ���Ḯ��Ʈ
	int total1 = 0, total2 = 0; // û��, ������ ������ ������ ����

	fp = fopen("data.txt", "r"); // ���������͸� �̿��� data.txt������ �б���� ����.
	if (fp == NULL) // ���������Ͱ� NULL�̶��
	{
		printf("���� ���� ����\n"); // ��� ����ϰ�
		exit(1); // ���α׷� ����
	}

	while (!feof(fp)) // ������ ������ �ݺ�
	{
		fscanf(fp, "%s %s %d", temp.node_team, temp.node_name, &temp.node_score); // �� �̸�, �̸�, ������ �о� �ӽñ���ü�� ����
		if (!strcmp(temp.node_team, "û��")) // ���� data�� û���̶��
			insert_node(&list1, NULL, create_node(temp, NULL)); // û�� ���Ḯ��Ʈ�� node�� �̾���δ�.(head����)
		else // ���� data�� �����̶��
			insert_node(&list2, NULL, create_node(temp, NULL)); // ���� ���Ḯ��Ʈ�� node�� �̾���δ�.(head����)
	}

	fclose(fp); // fclose�� ���� ����

	printf("List1 : \n");
	list1 = reverse(list1); // insert_node�Լ��� �����ϸ鼭 head�� ��� node�� �̾�ٿ����Ƿ� ������ȯó��
	display(list1); // list1 ���

	printf("\n\n");

	printf("List2 : \n");
	list2 = reverse(list2); // insert_node�Լ��� �����ϸ鼭 head�� ��� node�� �̾�ٿ����Ƿ� ������ȯó��
	display(list2); // list2 ���

	total1 = total(list1); // û���� ���� ������ ���
	total2 = total(list2); // ������ ���� ������ ���
	printf("\n\n���� %d�� vs %d��\n\n", total1, total2);

	if(total1 > total2)
		printf("û�� �¸�\n");
	else
		printf("���� �¸�\n");

	return 0;
}