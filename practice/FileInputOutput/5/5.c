/*
	작성일: 2019.03.24
	작성자: 20154015 이남준
	프로그램명: 파일안에 있는 내용을 출력하고 소문자, 대문자, 숫자, 공백의 갯수를 출력하는 문자 카운팅 프로그램
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE *fp = NULL; // 파일포인터 선언
	char string[50], full_string[100], file_name[10];
	int i = 0, small_count = 0, big_count = 0, number = 0, blank = 0, other = 0;


	printf("파일 이름: ");
	scanf("%s", file_name); // 파일 이름 입력받기

	fp = fopen(file_name, "r"); // fopen으로 파일 열기

	if(fp == NULL)
	{
		printf("파일 열기 실패\n");
		return 0; // 파일포인터 fp가 NULL일경우 오류메시지와 함께 프로그램 종료
	}

	fgets(string, 50, fp); // 파일에서 문자열 한줄 읽어 string에 저장
	string[strlen(string)-1] = '\0'; // 문자열 끝의 개행문자부분을 NULL문자로 대체
	puts(string); // 문자열 출력 후 개행
	strcpy(full_string, string); // 전체 문자열에 읽은 문자열 복사

	while(!feof(fp)) // 파일의 끝이 아니면 계속 반복
	{
		fgets(string, 50, fp); // 파일에서 문자열 한줄 읽어 string에 저장
		if(string[strlen(string)-1] == '\n') // 문자열의 끝부분이 개행문자일때
			string[strlen(string)-1] = '\0'; // 개행문자 대신 NULL문자 삽입
		puts(string); // 문자열 출력 후 개행
		strcat(full_string, string); // 전체 문자열 뒤에 읽은 문자열 붙이기
	}

	for(i = 0 ; i < 100 ; i++) // 전체 문자열까지
	{
		if(full_string[i] >= 97 && full_string[i] <= 122) // ASCII코드값 중 소문자일때
			small_count++; // 소문자 갯수 증가
		else if(full_string[i] >= 65 && full_string[i] <= 90) // ASCII코드값 중 대문자일때
			big_count++; // 대문자 갯수 증가
		else if(full_string[i] >= 48 && full_string[i] <= 57) // ASCII코드값 중 숫자일때
			number++; // 숫자 갯수 증가
		else if(full_string[i] == 32) // ASCII코드값 중 공백문자일때
			blank++; // 공백 갯수 증가
		else
			other++; // 그밖의 문자 갯수 증가. but, 사용하지 않음
	}

	printf("\n==%s 내용==\n", file_name);
	printf("\t소문자: %d 개\n", small_count);
	printf("\t대문자: %d 개\n", big_count);
	printf("\t숫자: %d 개\n", number);
	printf("\t공백: %d 개\n", blank);
	
	fclose(fp);
	return 0;
}