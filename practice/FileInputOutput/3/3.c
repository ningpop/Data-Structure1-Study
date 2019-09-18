/*
	작성일: 2019.03.12
	작성자: 20154015 이남준
	프로그램명: 자료구조1 실습 1번 파일입출력을 이용한 구구단 출력 프로그램
*/

#include <stdio.h>

int main(void)
{
	FILE *fp = NULL;
	int i=0, j=0, result;
	char c;

	fp = fopen("data.txt", "w"); // fopen으로 data.txt 파일을 쓰기모드로 연다.
	if(fp == NULL)
	{
		printf("파일 열기 실패\n"); // fp가 NULL이면 오류 메시지 출력하고 종료.
		return 0;
	}

	
	// data.txt 파일에 구구단을 작성하는 반복문.
	for(i = 1 ; i <= 9 ; i++)
	{
		for(j = 1 ; j <= 9 ; j++)
			fprintf(fp, "%d * %d = %d\n", i, j, i*j);
		if(i != 9)
			fprintf(fp, "\n"); // 9단까지 각 단 사이에 개행문자 작성
	}
	
	fclose(fp); // fclose로 파일포인터 닫음.
	
	fp = fopen("data.txt", "r"); // fopen으로 data.txt 파일을 읽기모드로 연다.
	if(fp == NULL)
	{
		printf("파일 열기 실패\n"); // fp가 NULL이면 오류 메시지 출력하고 종료.
		return 0;
	}
	
	// data.txt파일 속 내용이 끝날때까지(파일포인터 fp가 끝까지 갈때까지) 반복.
	while(!feof(fp))
	{
		if(i == 9 && j == 9)
			break; // 9 * 9 = 81까지 출력하고 난 뒤에는 반복문 탈출.
		fscanf(fp, "%d %c %d %c %d", &i, &c, &j, &c, &result);
				// fscanf로 data.txt파일에서 구구단 숫자 정보 읽음. 곱셈기호와 등호는 읽기만 함.
		
		if(j==1)
			printf("<< %d단입니다 >>\n", i); // 단의 시작부분 출력.
		printf("%d * %d = %d\n", i, j, result); // 구구단 출력.
		if(j == 9)
			printf("\n"); // 구구단의 끝부분 개행문자 삽입.
	}
	
	fclose(fp); // 파일포인터 닫음.
		
	return 0;
}