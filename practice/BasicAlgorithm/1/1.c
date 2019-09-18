/*
	작성일: 2019.03.24
	작성자: 20154015 이남준
	프로그램명: 입력받은 숫자 줄만큼 모래시계 별 짓기 프로그램
*/

#include <stdio.h>

int main(void)
{
	int i, j, num;

	printf("크기를 입력하세요 : ");
	scanf("%d", &num);

	for(i = 0 ; i < num ; i++) // 위쪽 역삼각형 출력 반복문
	{
		for(j = 0 ; j < i ; j++) // 공백이 하나씩 늘어나면서 출력
			printf(" ");
		for(j = 0 ; j < 2*num-1-2*i ; j++) // 별모양이 공백 이후에 2개씩 증가하며 출력
			printf("*");
		printf("\n"); // 한줄 출력 이후 개행
	}

	for(i = 0 ; i < num ; i++) // 아래쪽 삼각형 출력 반복문
	{
		for(j = 0 ; j < num-i-1 ; j++) // 공백이 하나씩 줄어들면서 출력
			printf(" ");
		for(j = 0 ; j < 2*i+1 ; j++) // 별모양이 공백 이후에 2개씩 증가하며 출력
			printf("*");
		printf("\n"); // 한줄 출력 이후 개행
	}

	return 0;
}