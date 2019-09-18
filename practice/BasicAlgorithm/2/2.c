/*
	작성일: 2019.04.06
	작성자: 20154015 이남준
	프로그램명: 구구단 5열 정리 출력 프로그램
*/

#include <stdio.h>

void print_99dan(int a, int b); // 구구단 출력 함수

int main(void)
{
	print_99dan(1, 5); // 1 ~ 5단 출력
	print_99dan(6, 9); // 6 ~ 9단 출력

	return 0;
}

void print_99dan(int a, int b) // 구구단 출력 함수
{
	int i, j;

	for(i = 1 ; i <= 9 ; i++) // 단 수에 곱해지는 수 반복
	{
		for(j = a ; j <= b ; j++) // 매개변수 입력받은 만큼 구구단 단수 출력
			printf("%d * %d = %d\t", j, i, i*j);
		printf("\n");

		if(i == 9)
			printf("\n"); // 곱해지는 수가 9까지 곱해졌을 때 줄 바꿈 한번 더
	}
}