/*
	작성일: 2019.03.14
	작성자: 20154015 이남준
	프로그램명: 파일입출력을 이용한 정수 최대/최소값 출력 프로그램
*/

#include <stdio.h>

int max_compare(int num1, int num2); // 최대값 비교 함수
int min_compare(int num1, int num2); // 최소값 비교 함수

int main(void)
{
	FILE *fp = NULL;
	int i, j, max, min, eon, temp, value;
	/* 변수 설명-
	i, j: 반복문 및 배열 index 접근변수
	max, min: 최대/최소값 저장변수
	eon: end of number의 약자로 10000개의 배열중 입력된 숫자 목록의 끝(숫자 갯수)
	temp: 한줄씩 숫자 출력 후 각 줄의 처음 숫자 index를 저장해둘 변수
	value: switch문 사용시 숫자의 최대/최소/일반값을 나타내는 변수 */
	int number[10000] = { NULL };

	fp = fopen("data.txt", "r"); // data.txt file open

	if (fp == NULL)
	{
		printf("오류: 파일이 열리지 않습니다.\n"); // 파일 open시 예외처리
		return 0;
	}

	i = 0;
	while(!feof(fp))
	{
		if(i >= 10000)
		{
			printf("숫자가 10000개가 넘습니다.\ndata.txt 파일을 확인하세요.\n");
					// 숫자의 갯수는 50 ~ 10000개이므로 10000개 이상일 경우 프로그램 종료
			return 0;
		}

		fscanf(fp, "%d", &number[i]); // data.txt 숫자를 number배열에 저장
		i++;
	}
	
	eon = i - 1; // 추후 반복하여 숫자를 출력시키기 위해 eon 값 생성

	if (i - 1 < 49)
	{
		printf("정수가 50개 미만입니다.\ndata.txt에 정수를 더 입력하세요\n");
					// 숫자의 갯수는 50 ~ 10000개이므로 50개 이하일 경우 프로그램 종료
		return 0;
	}

	max = number[0]; // 초기값을 최대값으로 지정
	min = number[0]; // 초기값을 최소값으로 지정
	for (i = 1; i < eon ; i++)
	{
		max = max_compare(max, number[i]); // 숫자 목록 중 최대값 저장
		min = min_compare(min, number[i]); // 숫자 목록 중 최소값 저장
	}

	for (i = 0; i <= eon/10; i++)
		// 변수 eon을 이용해 출력 줄 갯수까지 반복 ex) 숫자 갯수 53개 -> 숫자줄, 최대/최소줄 1set로 총 6줄 출력
	{
		temp = i*10; // 각 숫자출력 줄의 첫번째 index값 임시 저장
		if(i == eon/10)
			for (j = 0; j < eon % 10; j++)
				printf("%d\t", number[i * 10 + j]);
					// 10개씩 출력하고 남은 나머지 숫자들의 반복 출력문 ex) 53개 -> 마지막줄에 나머지 3개 출력
		else
			for (j = 0; j < 10; j++)
				printf("%d\t", number[i * 10 + j]);
					// 10개씩 출력할 줄의 숫자 반복 출력문 ex) 53개 -> 50개까지 출력
		printf("\n"); // 한줄 출력 후 개행
		
		if (i == eon / 10)
			for (j = 0; j < eon % 10; j++) // 마지막줄 나머지 숫자 출력줄에 대한 최대/최소값 출력 반복문
			{
				if (max == number[temp])
					value = 'M'; // 최대값일경우 value값은 Max를 뜻함
				else if (min == number[temp])
					value = 'm'; // 최소값일경우 value값은 min을 뜻함
				else
					value = 'c'; // 일반값일경우 value값은 common을 뜻함

				switch (value)
				{
				case 'M':
					printf("최대값\t", number[temp]); // '최대값' 출력
					temp++;
					break;
				case 'm':
					printf("최소값\t", number[temp]); // '최소값' 출력
					temp++;
					break;
				default:
					printf("\t", number[temp]); // 일반값이므로 \t으로 넘어감
					temp++;
					break;
				}
			}
		else
			for (j = 0; j < 10; j++) // 숫자 10개씩 출력줄에 대한 최대/최소값 출력 반복문
			{
				if (max == number[temp])
					value = 'M'; // 최대값일경우 value값은 Max를 뜻함
				else if (min == number[temp])
					value = 'm'; // 최소값일경우 value값은 min을 뜻함
				else
					value = 'c'; // 일반값일경우 value값은 common을 뜻함

				switch (value)
				{
				case 'M':
					printf("최대값\t", number[temp]); // '최대값' 출력
					temp++;
					break;
				case 'm':
					printf("최소값\t", number[temp]); // '최소값' 출력
					temp++;
					break;
				default:
					printf("\t", number[temp]); // 일반값이므로 \t으로 넘어감
					temp++;
					break;
				}
			}
		printf("\n"); // 최대/최소값 출력 or 해당줄이 모두 일반값일경우 개행
	}

	fclose(fp); // data.txt file close
	return 0; // 프로그램 종료
}

int max_compare(int num1, int num2) // 최대값 비교 함수
{
	if (num1 > num2)
		return num1;
	else
		return num2;
}

int min_compare(int num1, int num2) // 최소값 비교 함수
{
	if (num1 < num2)
		return num1;
	else
		return num2;
}