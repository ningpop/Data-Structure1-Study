/*
	작성일: 2019.04.06
	작성자: 20154015 이남준
	프로그램명: n값을 입력받아 n만큼의 피보나치수열을 출력하는 프로그램
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int num, i; // 사용자에게 입력받을 num변수와 배열 index에 사용할 i를 선언한다.
	int *arr;

	printf("피보나치수열 반복 횟수를 입력하세요 : ");
	scanf("%d", &num); // 사용자에게 피보나치 수열을 몇항까지 출력할 지 num값을 입력받는다.

	arr = (int *)malloc((num)*sizeof(int)); // 입력받은 num값만큼 동적 할당 배열을 만든다.

	arr[0] = 0; // 피보나치 수열의 초항을 초기화한다.
	arr[1] = 1; // 피보나치 수열의 둘째 항을 초기화한다.

	for(i = 2 ; i < num ; i++) // 피보나치 수열의 2항부터 입력받은 num항까지 반복
		arr[i] = arr[i-2] + arr[i-1]; // i항의 배열에 전전항과 전항의 값을 더하여 대입한다.

	printf("피보나치 수열 : ");
	for(i = 0 ; i < num ; i++)
		printf("%d ", arr[i]); // 동적할당한 배열의 피보나치 수열을 차례로 출력해준다.
	printf("\n");

	free(arr); // 동적할당 배열을 메모리에서 수거한다.

	return 0;
}