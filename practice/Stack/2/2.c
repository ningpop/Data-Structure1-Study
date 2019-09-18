/*
	작성일: 2019.05.21
	작성자: 20154015 이남준
	프로그램명: 스택 그래픽화 구현 프로그램
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 5 // 스택 최대 크기를 5로 지정

typedef struct {
	int number;
}element; // 숫자를 담을 구조체 생성
element stack[MAX_STACK_SIZE]; // 구조체를 자료형으로 사용해 스택배열을 선언. 스택 최대크기는 5

int top = -1; // 스택의 현재 위치를 알려주는 top 변수. 초기값은 -1로 초기화

int is_empty(); // 스택이 비었는지 알려주는 함수
int is_full(); // 스택이 꽉 찼는지 알려주는 함수
void push(element item); // 스택에 데이터를 삽입하는 함수
element pop(); // 스택의 맨 위 데이터를 삭제하는 함수
element peek(); // 스택의 가장 최신 데이터를 반환하는 함수

int main(void)
{
	element num, temp; // 입력받을 값에 대한 구조체와 출력을 위한 구조체 선언
	int op, i, top_temp;

	do
	{
		printf("연산을 입력하세요(1:PUSH, 2:POP, 3:PEEK, -1:종료) : ");
		scanf("%d", &op); 
		getchar();

		if(op == -1) // 명령이 -1이라면 프로그램 종료
			break;

		switch(op)
		{
		case 1: // PUSH 명령 입력시
			printf("값을 입력하세요(PUSH) : ");
			scanf("%d", &num);
			push(num); // 입력받은 값으로 스택의 PUSH연산
			break;
		case 2: // POP 명령 입력시
			temp = pop(); // POP한 값을 temp에 저장
			printf("POP한 값 : %d\n", temp);
			break;
		case 3: // PEEK 명령 입력시
			temp = peek(); // PEEK한 값을 temp에 저장
			printf("PEEK한 값 : %d\n", temp);
			break;
		default:
			break;
		}

		printf("\n\n");
		top_temp = top; // top변수를 함부로 건드리면 안되므로 top_temp에 복사
		for(i = 0; i < MAX_STACK_SIZE; i++) // MAX_STACK_SIZE만큼 스택 모형 출력
		{
			if(i < MAX_STACK_SIZE - top - 1) // 스택에 들어있는 데이터를 제외한 나머지 공간은 비어서 출력
				printf("|    |\n");
			else
			{
				if(stack[top_temp].number >= 0 && stack[top_temp].number < 10) // 스택에 있는 숫자가 한 자리수일 경우
					printf("|<0%d>|\n", stack[top_temp--]); // 앞에 0을 붙여서 출력
				else // 두 자리수라면
					printf("|<%d>|\n", stack[top_temp--]); // 그냥 출력
			}
		}
		printf("------\n");
	}while(1);

	return 0;
}

int is_empty() // 스택이 비어있는지 확인하는 함수
{
	return (top == -1);
}

int is_full() // 스택이 꽉 차있는지 확인하는 함수
{
	return (top == (MAX_STACK_SIZE - 1));
}

void push(element item) // 스택에 데이터를 넣는 함수
{
	if (is_full()) // 스택이 꽉 차있다면
	{
		fprintf(stderr, "스택 포화 에러\n"); // 에러문구 출력
		return;
	}
	else
		stack[++top] = item;
}

element pop() // 스택의 데이터를 최신 데이터부터 하나씩 삭제하며 반환하는 함수
{
	if (is_empty()) // 스택이 비어있다면
	{
		fprintf(stderr, "스택 공백 에러\n"); // 에러문구 출력
 		exit(1);
	}
	else
		return stack[top--];
}

element peek() // 스택의 최신 데이터를 출력하는 함수
{
	if (is_empty()) // 스택이 비어있다면
	{
		fprintf(stderr, "스택 공백 에러\n"); // 에러문구 출력
		exit(1);
	}
	else
		return stack[top];
}