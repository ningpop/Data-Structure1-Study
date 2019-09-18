/*
	작성일: 2019.04.03
	작성자: 20154015 이남준
	프로그램명: 알고리즘 A, B, C의 실행시간 비교
*/

#include <stdio.h>
#include <time.h>

int main(void)
{
	unsigned int al, num, sum = 0, i, j; // 음수는 사용하지 않으므로 unsigned int 자료형 사용
	clock_t start, finish; // 실행시간의 시작시간, 끝시간을 저장할 변수 선언
	double time;

	do
	{
		printf("알고리즘을 선택하세요(1, 2, 3) : "); // 알고리즘 선택
		scanf("%d", &al);

		if(al < 1 || al > 3)
			printf("알고리즘을 다시 선택하세요\n"); // 입력받은 숫자가 1~3범위가 아닐 시에 경고창
		else
			break;
	}while(1);

	printf("숫자를 입력하세요 : ");
	scanf("%d", &num);

	switch (al) // 선택한 알고리즘을 switch문을 이용해 골라서 실행
	{
	case 1: // 알고리즘 A
		start = clock(); // 실행시작시간 측정
		sum = num * num;
		finish = clock(); // 실행끝시간 측정
		break;
	case 2: // 알고리즘 B
		start = clock(); // 실행시작시간 측정
		for(i = 1; i <= num; i++)
			sum = sum + num;
		finish = clock(); // 실행끝시간 측정
		break;
	case 3: // 알고리즘 C
		start = clock(); // 실행시작시간 측정
		for(i = 0; i <= num; i++)
			for(j = 1; j <= num; j++)
				sum = sum + 1;
		finish = clock(); // 실행끝시간 측정
		break;
	default:
		break;
	}

	time = (double)(finish - start) / CLOCKS_PER_SEC; // 실행시간 계산식

	printf("\n걸린시간은 %f입니다.\n", time);

	return 0;
}