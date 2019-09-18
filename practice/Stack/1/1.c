/*
	�ۼ���: 2019.05.01
	�ۼ���: 20154015 �̳���
	���α׷���: ������ Ȱ���� �л� ���� ���α׷�
*/

#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 100 // ���� �ִ� ũ�⸦ 100���� ����
#define MAX_STRING 100 // ���ڿ� �ִ� ũ�⸦ 100���� ����

typedef struct {
	int student_no;
	char name[MAX_STRING];
	char address[MAX_STRING];
}element; // �л� ������ ���� ����ü ����
element stack[MAX_STACK_SIZE]; // ����ü�� �ڷ������� ����� ���ù迭�� ����. ���� �ִ�ũ��� 100

int top = -1; // ������ ���� ��ġ�� �˷��ִ� top ����. �ʱⰪ�� -1�� �ʱ�ȭ

int is_empty(); // ������ ������� �˷��ִ� �Լ�
int is_full(); // ������ �� á���� �˷��ִ� �Լ�
void push(element item); // ���ÿ� �����͸� �����ϴ� �Լ�
element pop(); // ������ �� �� �����͸� �����ϴ� �Լ�
element peek(); // ������ ���� �ֽ� �����͸� ��ȯ�ϴ� �Լ�

int main(void)
{
	FILE *fp = NULL; // ���������� ����
	char order[10]; // ���Ͽ��� ��ɾ �о� ������ ���ڿ� �迭
	element temp; // ���Ͽ��� ���ÿ� ����� ��ɾ�� ���� ���� �ӽ� ����ü

	fp = fopen("data.txt", "r"); // fopen���� data.txt������ �б���� ����.
	if (fp == NULL) // ���������Ͱ� NULL�϶�
	{
		printf("���� ���� ����\n"); // ��� ��� �� ���α׷� ����.
		return 0;
	}

	while (!feof(fp)) // ���������Ͱ� ������ ���� ���������� �ݺ�
	{
		fscanf(fp, "%s", order); // �� ���� ���ۺκ��� ��ɾ� �д� �ڵ�

		if (!strcmp(order, "push")) // ���� ��ɾ push�̸�
		{
			fscanf(fp, "%d %s %s", &temp.student_no, temp.name, temp.address); // push ���� �л������� �о� �ӽ� ����ü�� ����
			printf("PUSH : %d %s %s\n\n", temp.student_no, temp.name, temp.address); // ����� �ӽ� ����ü�� ���
			push(temp); // �ӽñ���ü�� ���ÿ� push�Լ��� ����
		}
		else if (!strcmp(order, "pop")) // ���� ��ɾ pop�̸�
		{
			temp = pop(); // pop�Լ��� �����ϰ� ���� ��ȯ���� �ӽ� ����ü�� ����
			printf("POP : %d %s %s\n\n", temp.student_no, temp.name, temp.address); // �ӽ� ����ü�� ������ ���
		}
		else if (!strcmp(order, "peek")) // ���� ��ɾ peek�̸�
		{
			temp = peek(); // peek�Լ��� �����ϰ� ��ȯ�� ����ü�� temp �ӽñ���ü�� ����
			printf("PEEK : %d %s %s\n\n", temp.student_no, temp.name, temp.address); // peek�Լ��� ����� �ӽñ���ü ����� ���
		}
		else if (!strcmp(order, "print")) // ���� ��ɾ print�̸�
			while (!is_empty()) // ������ �� �����������
			{
				temp = pop(); // pop�� �����ϸ� �ϳ��� ����Ѵ�.
				printf("PRINT : %d %s %s\n", temp.student_no, temp.name, temp.address);
			}
		else
			continue;
	}

	fclose(fp);

	return 0;
}

int is_empty() // ������ ����ִ��� Ȯ���ϴ� �Լ�
{
	return (top == -1);
}

int is_full() // ������ �� ���ִ��� Ȯ���ϴ� �Լ�
{
	return (top == (MAX_STACK_SIZE - 1));
}

void push(element item) // ���ÿ� �����͸� �ִ� �Լ�
{
	if (is_full()) // ������ �� ���ִٸ�
	{
		fprintf(stderr, "���� ��ȭ ����\n"); // �������� ���
		return;
	}
	else
		stack[++top] = item;
}

element pop() // ������ �����͸� �ֽ� �����ͺ��� �ϳ��� �����ϸ� ��ȯ�ϴ� �Լ�
{
	if (is_empty()) // ������ ����ִٸ�
	{
		fprintf(stderr, "���� ���� ����\n"); // �������� ���
 		exit(1);
	}
	else
		return stack[top--];
}

element peek() // ������ �ֽ� �����͸� ����ϴ� �Լ�
{
	if (is_empty()) // ������ ����ִٸ�
	{
		fprintf(stderr, "���� ���� ����\n"); // �������� ���
		exit(1);
	}
	else
		return stack[top];
}