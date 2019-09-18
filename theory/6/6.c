/*
	�ۼ���: 2019.05.30
	�ۼ���: 20154015 �̳���
	���α׷���: ���Ḯ��Ʈ�� �̿��� 2���� ���׽� ���� ���� ���α׷�
*/

#include <stdio.h>
#include <stdlib.h>

// ��� Ÿ��
typedef struct ListNode {
	int coef; // ���
	int expon; // ����
	struct ListNode *link;
} ListNode;

// ���Ḯ��Ʈ ���
typedef struct ListType {
	ListNode *head;
	ListNode *tail;
} ListType;

//���� �Լ�
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// ����Ʈ ��� ����
ListType* create()
{
	ListType *plist = (ListType *)malloc(sizeof(ListType));
	plist->head = plist->tail = NULL;
	return plist;
}

//plist�� ���� ����Ʈ�� ����� ����Ű�� ������, coef�� ���, expon�� ����
void insert_last(ListType* plist, int coef, int expon)
{
	ListNode* temp = (ListNode *)malloc(sizeof(ListNode)); // ����Ʈ�� ������ �ӽ� ���
	if (temp == NULL)
		error("�޸� �Ҵ� ����");
	temp->coef = coef; // ����� �ӽ� ��忡 ����
	temp->expon = expon; // ������ �ӽ� ��忡 ����
	temp->link = NULL; // link�� NULL�� ����
	if (plist->tail == NULL) // ����Ʈ�� ����ִٸ�
		plist->head = plist->tail = temp; // ����Ʈ�� �ӽó�带 �����ϰ� head�� tail ��� ��带 ����Ű�� ����
	else // ����Ʈ�� ������� �ʴٸ�
	{
		plist->tail->link = temp; // ����Ʈ�� ������ ����� link�� �ӽ� ��带 ����Ŵ
		plist->tail = temp; // ����Ʈ�� ���� ���� �ӽ� ��带 tail�� ����
	}
}

//list3 = list1 * list2
ListType* poly_multiple(ListType* plist1, ListType* plist2)
{
	ListNode* a = plist1->head; // ���׽� 1 ����Ʈ�� ���� ���
	ListNode* b = plist2->head; // ���׽� 2 ����Ʈ�� ���� ���
	ListType* multi = create(); // ���׽� �ܼ� ���� ����Ʈ
	ListType* result = create(); // ���ĵ� ���� ���� ���׽� ����Ʈ 
	ListNode* temp; // ���Ľ� multi ����Ʈ�� ���󰡸� ����� �ӽ� ���
	int ResultExpon; // ����Ʈ ���Ŀ� ����� �ְ����� ����
	int SumCoef; // ��� ��
	
	// ���׽� 1, 2 ����Ʈ�� �ܼ� ���� �����ϱ� ���� �ݺ���
	while (a != NULL) // ���׽� 1�� �� ���� �����Ҷ����� �ݺ�
	{
		while (b != NULL) // ���׽� 2�� �� ���� �����Ҷ����� �ݺ�
		{
			insert_last(multi, a->coef * b->coef, a->expon + b->expon); // ���׽� 1, 2�� �ش� ��带 �ܼ� �����Ͽ� multi ����Ʈ�� ����
			b = b->link; // ���׽� 2 ����Ʈ�� ��� ��ĭ ����
		}
		a = a->link; // ���׽� 1 ����Ʈ�� ��� ��ĭ ����
		b = plist2->head; // ���׽� 2 ����Ʈ �� �� head�� �ʱ�ȭ
	}

	// ���׽� ����Ʈ�� �����ϱ� ���� �ݺ���
	// �ְ������� ������ �ܼ����� ����Ʈ�� ù ���� ������ �����ϰ� -1�� �ɶ����� 1�� ����
	for (ResultExpon = multi->head->expon; ResultExpon != -1; ResultExpon--)
	{
		SumCoef = 0; // ���� ���� ����� ���� ������ ������ 0���� �ʱ�ȭ
		temp = multi->head; // �ܼ� ���� ����Ʈ�� �� ó�� ��ġ�� �ӽ� ��带 ����
		while (temp != NULL) // ��尡 �ܼ� ���� ����Ʈ�� ���� �����Ҷ�����
		{
			if (ResultExpon == temp->expon) // �ְ������� ������ �ӽó�尡 ����Ű�� ������ ���ٸ�
				SumCoef += temp->coef; // ���� ������ ���̹Ƿ� ������� ����
			temp = temp->link; // ��� ��ĭ ����
		}
		if(SumCoef != 0) // ����� ���� 0�� �ƴ϶��(�ش� ������ ���� �ִٸ�)
			insert_last(result, SumCoef, ResultExpon); // ����� �հ� ���� ������ result ����Ʈ�� ����
	}

	return result;
}

// ����Ʈ ��� �Լ�
void poly_print(char polynomial[10], ListType* plist)
{
	ListNode* p = plist->head; // ����Ʈ�� head�� ����Ű�� ��� �ϳ� ����

	printf("%s =", polynomial); // �Է¹��� ���׽��� �̸� ���
	for (; p; p = p->link) // ����Ʈ�� head�� NULL�϶����� �ݺ��ϸ� ��� �ϳ��� ����
	{
		if (p->coef < 0) // ��� p�� ����� �����̸�
			printf(" %dx^%d", p->coef, p->expon); // ��ȣ ������� �ʰ� ����� ��ȣ �״�� ���
		else // ��� p�� ����� ����̸�
		{
			if(p == plist->head) // ��� p�� ����Ʈ�� head�϶�
				printf(" %dx^%d", p->coef, p->expon); // ����� ����� ������ ��ȣ ������� ����
			else // ��� p�� ����Ʈ�� �߰��̳� �������϶�
				printf(" + %dx^%d", p->coef, p->expon); // ����� ����̹Ƿ� �׳��� ������ + ��ȣ ���
		}
	}
	printf("\n");
}

int main(void)
{
	FILE *fp = NULL;
	char polynomial[10]; // ���׽� �̸��� �ޱ� ���� ���ڿ�
	ListNode ReadTemp; // ���Ͽ��� �о� ������ �ӽ� ���
	ListType *list1, *list2, *list3; // list1: ���׽� 1, list2: ���׽� 2, list3: ���׽� 3

	// ���Ḯ��Ʈ ��� ����
	list1 = create();
	list2 = create();
	list3 = create();

	fp = fopen("data.txt", "r"); // data.txt������ �б���� ����
	if (fp == NULL) // ���������Ͱ� NULL�̸�
	{
		printf("���� ���� ����\n"); // ���� �޽��� ���
		exit(1);
	}

	fscanf(fp, "%s", polynomial); // data.txt���Ͽ��� ó������ ���׽� �̸��� �а� ���ڿ��� ����
	while (fscanf(fp, "%d %d", &ReadTemp.coef, &ReadTemp.expon) == 2) // ���� �ΰ��� �о� �ӽ� ��忡 �����ϸ� ��ȯ���� 2�� �ƴҶ����� �ݺ�
		insert_last(list1, ReadTemp.coef, ReadTemp.expon); // ���� ���� �ΰ��� list1�� ����
	poly_print(polynomial, list1); // ���׽� �̸��� �Բ� list1 ���

	fscanf(fp, "%s", polynomial); // data.txt���Ͽ��� ���׽� �̸��� �а� ���ڿ��� ����
	while (fscanf(fp, "%d %d", &ReadTemp.coef, &ReadTemp.expon) == 2) // ���� �ΰ��� �о� �ӽ� ��忡 �����ϸ� ��ȯ���� 2�� �ƴҶ����� �ݺ�
		insert_last(list2, ReadTemp.coef, ReadTemp.expon); // ���� ���� �ΰ��� list2�� ����
	poly_print(polynomial, list2); // ���׽� �̸��� �Բ� list2 ���

	fclose(fp); // ���� �ݱ�

	list3 = poly_multiple(list1, list2); // list1�� list2�� ���Ͽ� list3�� ����

	poly_print("Result", list3); // list3 ���

	// ���Ḯ��Ʈ �޸� �Ҵ� ����
	free(list1);
	free(list2);
	free(list3);

	return 0;
}