#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef char element;

typedef struct StackNode {
	element data;
	struct StackNode *link;
} StackNode;

typedef struct {
	StackNode *top;
} LinkedStackType;

// �ʱ�ȭ �Լ�
void init(LinkedStackType *s)
{
	s->top = NULL;
}

// ���� ���� ���� �Լ�
int is_empty(LinkedStackType *s)
{
	return (s->top == NULL);
}

// ��ȭ ���� ���� �Լ�
int is_full(LinkedStackType *s)
{
	return 0;
}

// ���� �Լ�
void push(LinkedStackType *s, element item)
{
	StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
	temp->data = item;
	temp->link = s->top;
	s->top = temp;
}

// ���� �Լ�
element pop(LinkedStackType *s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "������ �������\n");
		exit(1);
	}
	else
	{
		StackNode *temp = s->top;
		int data = temp->data;
		s->top = s->top->link;
		free(temp);
		return data;
	}
}

void print_string(LinkedStackType *s)
{
	int i;
	StackNode *temp;
	
	for(temp = s->top; temp != NULL; temp = temp->link)
	{
		printf("�� %c��\n", temp->data);
	}
	printf("��������\n\n");
}

int check_matching(char *in)
{
	LinkedStackType s;
	char ch, open_ch;
	int i, n = strlen(in);
	init(&s);

	for(i = 0; i < n; i++)
	{
		ch = in[i];
		switch(ch)
		{
		case '(': case '[': case '{':
			push(&s, ch);
			print_string(&s);
			break;
		case ')': case ']': case '}':
			if(is_empty(&s))
				return 0;
			else
			{
				open_ch = pop(&s);
				print_string(&s);
				if((open_ch == '(' && ch != ')') || (open_ch == '[' && ch != ']') || (open_ch == '{' && ch != '}'))
					return 0;
				break;
			}
		}
	}
	if(!is_empty(&s))
		return 0;
	return 1;
}

int main(void)
{
	char *string;
	LinkedStackType temp;
	string = (char*)malloc(512);
	init(&temp);

	printf("��ȣ �˻� ���� �Է� : ");
	scanf("%s", string);

	if(check_matching(string) == 1)
		printf("��ȣ�˻� ����\n");
	else
		printf("��ȣ�˻� ����\n");

	free(string);

	return 0;
}