/*
	�ۼ���: 2019.05.21
	�ۼ���: 20154015 �̳���
	���α׷���: ���� �׷���ȭ ���� ���α׷�
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 5 // ���� �ִ� ũ�⸦ 5�� ����

typedef struct {
	int number;
}element; // ���ڸ� ���� ����ü ����
element stack[MAX_STACK_SIZE]; // ����ü�� �ڷ������� ����� ���ù迭�� ����. ���� �ִ�ũ��� 5

int top = -1; // ������ ���� ��ġ�� �˷��ִ� top ����. �ʱⰪ�� -1�� �ʱ�ȭ

int is_empty(); // ������ ������� �˷��ִ� �Լ�
int is_full(); // ������ �� á���� �˷��ִ� �Լ�
void push(element item); // ���ÿ� �����͸� �����ϴ� �Լ�
element pop(); // ������ �� �� �����͸� �����ϴ� �Լ�
element peek(); // ������ ���� �ֽ� �����͸� ��ȯ�ϴ� �Լ�

int main(void)
{
	element num, temp; // �Է¹��� ���� ���� ����ü�� ����� ���� ����ü ����
	int op, i, top_temp;

	do
	{
		printf("������ �Է��ϼ���(1:PUSH, 2:POP, 3:PEEK, -1:����) : ");
		scanf("%d", &op); 
		getchar();

		if(op == -1) // ����� -1�̶�� ���α׷� ����
			break;

		switch(op)
		{
		case 1: // PUSH ��� �Է½�
			printf("���� �Է��ϼ���(PUSH) : ");
			scanf("%d", &num);
			push(num); // �Է¹��� ������ ������ PUSH����
			break;
		case 2: // POP ��� �Է½�
			temp = pop(); // POP�� ���� temp�� ����
			printf("POP�� �� : %d\n", temp);
			break;
		case 3: // PEEK ��� �Է½�
			temp = peek(); // PEEK�� ���� temp�� ����
			printf("PEEK�� �� : %d\n", temp);
			break;
		default:
			break;
		}

		printf("\n\n");
		top_temp = top; // top������ �Ժη� �ǵ帮�� �ȵǹǷ� top_temp�� ����
		for(i = 0; i < MAX_STACK_SIZE; i++) // MAX_STACK_SIZE��ŭ ���� ���� ���
		{
			if(i < MAX_STACK_SIZE - top - 1) // ���ÿ� ����ִ� �����͸� ������ ������ ������ �� ���
				printf("|    |\n");
			else
			{
				if(stack[top_temp].number >= 0 && stack[top_temp].number < 10) // ���ÿ� �ִ� ���ڰ� �� �ڸ����� ���
					printf("|<0%d>|\n", stack[top_temp--]); // �տ� 0�� �ٿ��� ���
				else // �� �ڸ������
					printf("|<%d>|\n", stack[top_temp--]); // �׳� ���
			}
		}
		printf("------\n");
	}while(1);

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