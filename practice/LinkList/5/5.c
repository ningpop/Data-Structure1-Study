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

// 초기화 함수
void init(LinkedStackType *s)
{
	s->top = NULL;
}

// 공백 상태 검출 함수
int is_empty(LinkedStackType *s)
{
	return (s->top == NULL);
}

// 포화 상태 검출 함수
int is_full(LinkedStackType *s)
{
	return 0;
}

// 삽입 함수
void push(LinkedStackType *s, element item)
{
	StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
	temp->data = item;
	temp->link = s->top;
	s->top = temp;
}

// 삭제 함수
element pop(LinkedStackType *s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "스택이 비어있음\n");
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
		printf("│ %c│\n", temp->data);
	}
	printf("└──┘\n\n");
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

	printf("괄호 검사 수식 입력 : ");
	scanf("%s", string);

	if(check_matching(string) == 1)
		printf("괄호검사 성공\n");
	else
		printf("괄호검사 실패\n");

	free(string);

	return 0;
}