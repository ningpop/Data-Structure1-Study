/*
	작성일: 2019.04.17
	작성자: 20154015 이남준
	프로그램명: 재귀함수를 사용한 소수 판별 프로그램
*/

#include <stdio.h>

int is_prime(int num, int i);

int main(void)
{
	int num, cnt = 0;

	printf("소수인지 판별할 정수를 입력하세요 : ");
	scanf("%d", &num);

	cnt = is_prime(num, num);
	// 소수 판별 함수에 입력받은 정수를 2개 전달하고 소수 판별 카운트값에 저장

	if (cnt == 2)
		printf("%d은(는) 소수입니다.\n", num); // 소수 판별 카운트가 2이면 소수 출력
	else
		printf("%d은(는) 소수가 아닙니다.\n", num); // 소수 판별 카운트가 2가 아닌 값이면 소수가 아니라고 출력

	return 0;
}

int is_prime(int num, int i) // 소수 판별 함수
{
	int result = 0; // 재귀를 돌면서 함수 내에서 소수 판별 카운트값이 저장되는 변수 result

	if (i <= 0) // i값이 0보다 작으면 0을 반환한다.
		return 0;

	if (num%i == 0) // 매개변수로 받은 두 수의 나머지값이 0인지 판단(약수 확인)
		result = 1; // 소수 판별 카운트값 1로 초기화
	else
		result = 0; // 소수 판별 카운트값 0으로 초기화

	result += is_prime(num, i - 1); // result값에 소수 판별 함수를 다시 재귀호출하여 반환값을 result값에 더해줌

	return result; // result값 반환
}