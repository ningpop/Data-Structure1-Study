/*
	작성일: 2019.03.12
	작성자: 20154015 이남준
	프로그램명: 자료구조1 실습 2번 파일입출력을 이용한 행렬 덧셈연산 프로그램
*/

#include <stdio.h>

void print_array(char array_name, int arr[3][3]);

int main(void)
{
	FILE *fp = NULL;
	int arr1[3][3], arr2[3][3]; // 3*3의 2차원 배열 두개를 선언한다.
	char arr1_name, arr2_name; // 배열 이름을 저장할 문자형 변수도 선언한다.
	int x=0, y=0, i, j;

	fp = fopen("data2.txt", "r"); // fopen으로 data2.txt 파일을 읽기 모드로 연다.

	fscanf(fp, "%c %d %d", &arr1_name, &i, &j);
		// data2.txt 파일 안의 행렬 이름, 행렬 크기를 읽어들여 변수에 저장한다.

	for(x = 0 ; x < i ; x++)
		for(y = 0 ; y < j ; y++)
			fscanf(fp, "%d", &arr1[x][y]);
			// 첫번째 A 행렬의 원소들을 중첩 for문으로 읽어들이고 2차원 배열에 저장한다.
			// 이때, i와 j로 2차원배열 index에 접근한다.

	print_array(arr1_name, arr1);

	fscanf(fp, "%c", &arr2_name); // 문자를 하나 읽어들여 파일포인터를 하나 이동한다.

	fscanf(fp, "%c %d %d", &arr2_name, &i, &j);
		// 다시 fscanf를 사용해 두번째 행렬의 이름, 크기를 읽어 변수에 저장한다.

	for(x = 0 ; x < i ; x++)
		for(y = 0 ; y < j ; y++)
			fscanf(fp, "%d", &arr2[x][y]);
			// 이번에도 두번째 B 행렬의 원소들을 중첩 for문으로 읽어들이고 배열에 저장한다.

	print_array(arr2_name, arr2);

	printf("%c + %c 배열 = \n", arr1_name, arr2_name);
		// 더한 행렬을 출력하기 전에 제목부분을 출력한다.

	for(x = 0 ; x < i ; x++)
	{
		for(y = 0 ; y < j ; y++)
			printf("%5d", arr1[x][y]+arr2[x][y]);
		printf("\n");
	} // A 행렬과 B행렬을 더한 행렬을 중첩 for문으로 출력한다.
	
	fclose(fp); // fclose를 사용하여 파일을 닫는다.
	return 0;
}


void print_array(char array_name, int arr[3][3])
{
	int x, y;

	printf("%c배열 = \n", array_name); // 행렬을 출력 전에 행렬 이름을 출력한다.
	for(x = 0 ; x < 3 ; x++)
	{
		for(y = 0 ; y < 3 ; y++)
			printf("%5d", arr[x][y]);
		printf("\n");
	} // 중첩 for문으로 2차원 배열에 저장된 숫자들을 3*3 행렬 형식으로 출력한다.
}