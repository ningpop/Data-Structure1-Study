/*
	작성일: 2019.04.03
	작성자: 20154015 이남준
	프로그램명: 사칙연산 연속 실행시간 비교
*/

#include <stdio.h>
#include <time.h>

int main(void)
{
	int num, sum, i;
	char input; // 연산기호 저장할 변수
	clock_t start, finish; // 실행시간의 시작시간, 끝시간을 저장할 변수 선언
	double time; // 실행시간을 저장한 변수

	printf("연산을 선택하세요(+, -, *, /) : ");
	scanf("%c", &input); // 사용자로부터 연산자 입력

	printf("숫자를 입력하세요 : ");
	scanf("%d", &num); // 사용자로부터 숫자 입력

	switch(input) // 입력받은 연산기호에 맞춰 실행.
	{
	case '+':
		start = clock(); // 실행시작시간 측정
		for(i = 1; i <= num; i++)
			sum = 100000000 + i;
		finish = clock(); // 실행끝시간 측정
		break;
	case '-':
		start = clock(); // 실행시작시간 측정
		for(i = 1; i <= num; i++)
			sum = 100000000 - i;
		finish = clock(); // 실행끝시간 측정
		break;
	case '*':
		start = clock(); // 실행시작시간 측정
		for(i = 1; i <= num; i++)
			sum = 100000000 * i;
		finish = clock(); // 실행끝시간 측정
		break;
	case '/':
		start = clock(); // 실행시작시간 측정
		for(i = 1; i <= num; i++)
			sum = 100000000 / i;
		finish = clock(); // 실행끝시간 측정
		break;
	default:
		printf("연산자를 다시 입력하세요\n"); // 지정된 연산자가 아닐 경우 경고창 출력 후 프로그램 종료
		return 0;
	}

	time = (double)(finish - start) / CLOCKS_PER_SEC; // 실행시간 계산식

	printf("걸린 시간은 %.3f입니다.\n", time);

	return 0;
}