/*
	작성일: 2019.04.22
	작성자: 20154015 이남준
	프로그램명: 성적 관리 프로그램
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Student{ // Student 구조체 생성
		int student_num;
		char name[10];
		int kor, math, eng;
} STUDENTS; // typedef를 사용하여 STUDENTS로 치환 (자료형처럼 사용 가능)

int main(void)
{
	FILE *fp = NULL;
	STUDENTS *students_info; // STUDENTS 형식으로 students_info 라는 구조체 생성
	char read_temp[50];
	int i = 0, limits;

	fp = fopen("data.txt", "r"); // fopen으로 data.txt파일을 읽기모드로 연다

	if(fp == NULL) // 파일포인터가 NULL일때 경고창 출력 후 프로그램 종료
	{
		printf("파일열기 실패\n");
		return 0;
	}

	while(!feof(fp)) // 파일포인터가 파일 내용의 끝까지 반복
	{
		fgets(read_temp, 50, fp); // 줄단위로 파일 내용을 읽음
		i++; // i값을 증가시켜 인원수 계산
	}

	students_info = (STUDENTS *)malloc(i * sizeof(STUDENTS)); // 읽은 인원수만큼 동적 할당

	rewind(fp); // 파일포인터 맨 앞으로 이동
	i = 0; // i값 0으로 다시 초기화
	while(!feof(fp)) // 파일포인터가 파일 내용의 끝까지 반복
	{
		// data.txt 파일 내용 형식에 맞춰 데이터 읽음
		fscanf(fp, "%d %s %d %d %d", &students_info[i].student_num, students_info[i].name, &students_info[i].kor, &students_info[i].math, &students_info[i].eng);
		i++; // 인원수만큼 i값을 증가시킴
	}

	limits = i; // i값을 출력갯수 제한으로 지정

	printf("====학번=======이름==국어==수학==영어===\n");
	for(i = 0; i < limits; i++) // 제한된 출력인원수만큼 반복
		//형식에 맞춰 출력(출력 공간을 설정하여 데이터들의 열을 맞춰 정렬)
		printf("%d%11s%6d%6d%6d\n", students_info[i].student_num, students_info[i].name, students_info[i].kor, students_info[i].math, students_info[i].eng);
	printf("========================================\n");

	free(students_info); // 동적 할당 메모리 반납
	fclose(fp); // fclose로 파일 닫기
	return 0;
}