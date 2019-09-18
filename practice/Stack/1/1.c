/*
	작성일: 2019.05.01
	작성자: 20154015 이남준
	프로그램명: 스택을 활용한 학생 관리 프로그램
*/

#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 100 // 스택 최대 크기를 100으로 지정
#define MAX_STRING 100 // 문자열 최대 크기를 100으로 지정

typedef struct {
	int student_no;
	char name[MAX_STRING];
	char address[MAX_STRING];
}element; // 학생 정보를 담을 구조체 생성
element stack[MAX_STACK_SIZE]; // 구조체를 자료형으로 사용해 스택배열을 선언. 스택 최대크기는 100

int top = -1; // 스택의 현재 위치를 알려주는 top 변수. 초기값은 -1로 초기화

int is_empty(); // 스택이 비었는지 알려주는 함수
int is_full(); // 스택이 꽉 찼는지 알려주는 함수
void push(element item); // 스택에 데이터를 삽입하는 함수
element pop(); // 스택의 맨 위 데이터를 삭제하는 함수
element peek(); // 스택의 가장 최신 데이터를 반환하는 함수

int main(void)
{
	FILE *fp = NULL; // 파일포인터 선언
	char order[10]; // 파일에서 명령어를 읽어 저장할 문자열 배열
	element temp; // 파일에서 스택에 사용할 명령어와 같이 쓰일 임시 구조체

	fp = fopen("data.txt", "r"); // fopen으로 data.txt파일을 읽기모드로 연다.
	if (fp == NULL) // 파일포인터가 NULL일때
	{
		printf("파일 열기 실패\n"); // 경고문 출력 후 프로그램 종료.
		return 0;
	}

	while (!feof(fp)) // 파일포인터가 파일의 끝에 닿을때까지 반복
	{
		fscanf(fp, "%s", order); // 각 줄의 시작부분의 명령어 읽는 코드

		if (!strcmp(order, "push")) // 읽은 명령어가 push이면
		{
			fscanf(fp, "%d %s %s", &temp.student_no, temp.name, temp.address); // push 뒤의 학생정보를 읽어 임시 구조체에 저장
			printf("PUSH : %d %s %s\n\n", temp.student_no, temp.name, temp.address); // 저장된 임시 구조체를 출력
			push(temp); // 임시구조체를 스택에 push함수로 저장
		}
		else if (!strcmp(order, "pop")) // 읽은 명령어가 pop이면
		{
			temp = pop(); // pop함수를 실행하고 나온 반환형을 임시 구조체에 저장
			printf("POP : %d %s %s\n\n", temp.student_no, temp.name, temp.address); // 임시 구조체의 내용을 출력
		}
		else if (!strcmp(order, "peek")) // 읽은 명령어가 peek이면
		{
			temp = peek(); // peek함수를 실행하고 반환된 구조체를 temp 임시구조체에 저장
			printf("PEEK : %d %s %s\n\n", temp.student_no, temp.name, temp.address); // peek함수가 실행된 임시구조체 결과를 출력
		}
		else if (!strcmp(order, "print")) // 읽은 명령어가 print이면
			while (!is_empty()) // 스택이 다 비워질때까지
			{
				temp = pop(); // pop을 실행하며 하나씩 출력한다.
				printf("PRINT : %d %s %s\n", temp.student_no, temp.name, temp.address);
			}
		else
			continue;
	}

	fclose(fp);

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