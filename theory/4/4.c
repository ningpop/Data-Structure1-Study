/*
	작성일: 2019.04.18
	작성자: 20154015 이남준
	프로그램명: 파일입출력을 이용한 행렬 연산 프로그램
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp = NULL; // 파일포인터 선언
	int A_m, A_n, B_m, B_n, C_m, C_n; // 행렬들의 행/열 개수변수
	int i, j, k; // 반복문에 사용할 반복변수
	int **matrix_A, **matrix_B, **matrix_C; // 행렬들을 동적할당 2차원 배열로 선언하기 위한 이중포인터

	fp = fopen("data.txt", "r"); // fopen함수를 사용하여 data.txt파일을 읽기모드로 연다.
	if(fp == NULL) // 파일포인터가 NULL이라면 경고문을 출력하고 프로그램 종료
	{
		printf("파일 열기 실패\n");
		return 0;
	}

	fscanf(fp, "%d %d", &A_m, &A_n); // A행렬의 크기를 입력받음
	
	matrix_A = (int **)malloc(sizeof(int *) * A_m); // A행렬의 행에 대한 동적할당
	for(i = 0; i < A_m; i++)
		matrix_A[i] = (int *)malloc(sizeof(int) * A_n); // A행렬의 행 밑에 열을 만들어주기위한 반복동적할당

	for(i = 0; i < A_m; i++)
	{
		for(j = 0; j < A_n; j++)
			fscanf(fp, "%d", &matrix_A[i][j]); // 2중for문을 사용하여 data.txt파일에서 A행렬의 원소들을 입력받음
	}

	fscanf(fp, "%d %d", &B_m, &B_n); // B행렬의 크기를 입력받음
	
	matrix_B = (int **)malloc(sizeof(int *) * B_m); // B행렬의 행에 대한 동적할당
	for(i = 0; i < B_m; i++)
		matrix_B[i] = (int *)malloc(sizeof(int) * B_n); // B행렬의 행 밑에 열을 만들어주기위한 반복동적할당

	for(i = 0; i < B_m; i++)
	{
		for(j = 0; j < B_n; j++)
			fscanf(fp, "%d", &matrix_B[i][j]); // 2중for문을 사용하여 data.txt파일에서 B행렬의 원소들을 입력받음
	}

	fclose(fp); // fclose함수를 사용하여 파일 닫음

	// A행렬 기본 출력
	printf("A 행렬 = %d by %d\n", A_m, A_n);
	for(i = 0; i < A_m; i++)
	{
		for(j = 0; j < A_n; j++)
			printf("%3d ", matrix_A[i][j]);
		printf("\n");
	}
	printf("\n");

	// B행렬 기본 출력
	printf("B 행렬 = %d by %d\n", B_m, B_n);
	for(i = 0; i < B_m; i++)
	{
		for(j = 0; j < B_n; j++)
			printf("%3d ", matrix_B[i][j]);
		printf("\n");
	}
	printf("\n");

	if(A_m == B_m && A_n == B_n) // 행렬의 덧셈뺄셈을 위해 두 행렬의 차수가 같은지 확인
	{
		printf("A 와 B 행렬의 덧셈 연산 결과 =\n");
		for(i = 0; i < A_m; i++)
		{
			for(j = 0; j < A_n; j++)
				printf("%3d ", matrix_A[i][j] + matrix_B[i][j]); // 2중for문을 사용하여 두 행렬의 각 대응 원소들을 덧셈해 출력
			printf("\n");
		}
		printf("\n");

		printf("A 와 B 행렬의 뺄셈 연산 결과 =\n");
		for(i = 0; i < A_m; i++)
		{
			for(j = 0; j < A_n; j++)
				printf("%3d ", matrix_A[i][j] - matrix_B[i][j]); // 2중for문을 사용하여 두 행렬의 각 대응 원소들을 뺄셈해 출력
			printf("\n");
		}
		printf("\n");
	}
	else
		printf("A행렬과 B행렬의 차수가 서로 달라 덧셈, 뺄셈연산을 수행할 수 없습니다.\n\n");
							// 두 행렬의 차수가 같지 않다면 덧셈, 뺄셈을 수행하지 않고 경고문 출력
	
	if(A_n == B_m) // 행렬의 곱셈가능조건을 검사(A행렬의 열 개수와 B행렬의 행 개수가 같은지)
	{
		// A행렬의 행 개수와 B행렬의 열 개수를 가지고 곱셈연산한 행렬의 행/열개수를 만들기 위해 대입연산
		C_m = A_m;
		C_n = B_n;

		matrix_C = (int **)malloc(sizeof(int *) * C_m); // 곱셈한 C행렬의 행에 대한 동적할당
		for(i = 0; i < C_m; i++)
			matrix_C[i] = (int *)malloc(sizeof(int) * C_n); // C행렬의 행 밑에 열을 만들어주기위한 반복동적할당

		printf("A 와 B 행렬의 곱셈 연산 결과 =\n");
		for(i = 0; i < A_m; i++) // A행렬의 행 원소를 불러오기 위한 반복문
			for(j = 0; j < B_n; j++) // B행렬의 열 원소를 불러오기 위한 반복문
			{
				matrix_C[i][j] = 0; // 각 행렬의 원소들의 곱을 누적해서 더해야 하므로 0으로 초기화
				for(k = 0; k < A_n; k++)
					matrix_C[i][j] +=  matrix_A[i][k] * matrix_B[k][j];
									// A, B행렬의 곱셈결과를 누적해서 더하고 C행렬의 원소로 대입
			}

		for(i = 0; i < C_m; i++)
		{
			for(j = 0; j < C_n; j++)
				printf("%3d ", matrix_C[i][j]); // 저장된 C행렬을 출력
			printf("\n");
		}

		for(i = 0; i < A_n; i++)
			free(matrix_A[i]);
		free(matrix_A); // A행렬인 동적할당 2차원 배열의 메모리 반납

		for(i = 0; i < B_n; i++)
			free(matrix_B[i]);
		free(matrix_B); // B행렬인 동적할당 2차원 배열의 메모리 반납

		for(i = 0; i < C_n; i++)
			free(matrix_C[i]);
		free(matrix_C); // C행렬인 동적할당 2차원 배열의 메모리 반납
	}
	else
		printf("A행렬의 n값과 B행렬의 m값이 서로 달라 곱셈연산을 수행할 수 없습니다.\n");
														// 행렬의 곱셈가능조건이 false일경우 경고문 출력

	return 0;
}