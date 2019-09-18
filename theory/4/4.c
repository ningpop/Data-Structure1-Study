/*
	�ۼ���: 2019.04.18
	�ۼ���: 20154015 �̳���
	���α׷���: ����������� �̿��� ��� ���� ���α׷�
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp = NULL; // ���������� ����
	int A_m, A_n, B_m, B_n, C_m, C_n; // ��ĵ��� ��/�� ��������
	int i, j, k; // �ݺ����� ����� �ݺ�����
	int **matrix_A, **matrix_B, **matrix_C; // ��ĵ��� �����Ҵ� 2���� �迭�� �����ϱ� ���� ����������

	fp = fopen("data.txt", "r"); // fopen�Լ��� ����Ͽ� data.txt������ �б���� ����.
	if(fp == NULL) // ���������Ͱ� NULL�̶�� ����� ����ϰ� ���α׷� ����
	{
		printf("���� ���� ����\n");
		return 0;
	}

	fscanf(fp, "%d %d", &A_m, &A_n); // A����� ũ�⸦ �Է¹���
	
	matrix_A = (int **)malloc(sizeof(int *) * A_m); // A����� �࿡ ���� �����Ҵ�
	for(i = 0; i < A_m; i++)
		matrix_A[i] = (int *)malloc(sizeof(int) * A_n); // A����� �� �ؿ� ���� ������ֱ����� �ݺ������Ҵ�

	for(i = 0; i < A_m; i++)
	{
		for(j = 0; j < A_n; j++)
			fscanf(fp, "%d", &matrix_A[i][j]); // 2��for���� ����Ͽ� data.txt���Ͽ��� A����� ���ҵ��� �Է¹���
	}

	fscanf(fp, "%d %d", &B_m, &B_n); // B����� ũ�⸦ �Է¹���
	
	matrix_B = (int **)malloc(sizeof(int *) * B_m); // B����� �࿡ ���� �����Ҵ�
	for(i = 0; i < B_m; i++)
		matrix_B[i] = (int *)malloc(sizeof(int) * B_n); // B����� �� �ؿ� ���� ������ֱ����� �ݺ������Ҵ�

	for(i = 0; i < B_m; i++)
	{
		for(j = 0; j < B_n; j++)
			fscanf(fp, "%d", &matrix_B[i][j]); // 2��for���� ����Ͽ� data.txt���Ͽ��� B����� ���ҵ��� �Է¹���
	}

	fclose(fp); // fclose�Լ��� ����Ͽ� ���� ����

	// A��� �⺻ ���
	printf("A ��� = %d by %d\n", A_m, A_n);
	for(i = 0; i < A_m; i++)
	{
		for(j = 0; j < A_n; j++)
			printf("%3d ", matrix_A[i][j]);
		printf("\n");
	}
	printf("\n");

	// B��� �⺻ ���
	printf("B ��� = %d by %d\n", B_m, B_n);
	for(i = 0; i < B_m; i++)
	{
		for(j = 0; j < B_n; j++)
			printf("%3d ", matrix_B[i][j]);
		printf("\n");
	}
	printf("\n");

	if(A_m == B_m && A_n == B_n) // ����� ���������� ���� �� ����� ������ ������ Ȯ��
	{
		printf("A �� B ����� ���� ���� ��� =\n");
		for(i = 0; i < A_m; i++)
		{
			for(j = 0; j < A_n; j++)
				printf("%3d ", matrix_A[i][j] + matrix_B[i][j]); // 2��for���� ����Ͽ� �� ����� �� ���� ���ҵ��� ������ ���
			printf("\n");
		}
		printf("\n");

		printf("A �� B ����� ���� ���� ��� =\n");
		for(i = 0; i < A_m; i++)
		{
			for(j = 0; j < A_n; j++)
				printf("%3d ", matrix_A[i][j] - matrix_B[i][j]); // 2��for���� ����Ͽ� �� ����� �� ���� ���ҵ��� ������ ���
			printf("\n");
		}
		printf("\n");
	}
	else
		printf("A��İ� B����� ������ ���� �޶� ����, ���������� ������ �� �����ϴ�.\n\n");
							// �� ����� ������ ���� �ʴٸ� ����, ������ �������� �ʰ� ��� ���
	
	if(A_n == B_m) // ����� �������������� �˻�(A����� �� ������ B����� �� ������ ������)
	{
		// A����� �� ������ B����� �� ������ ������ ���������� ����� ��/�������� ����� ���� ���Կ���
		C_m = A_m;
		C_n = B_n;

		matrix_C = (int **)malloc(sizeof(int *) * C_m); // ������ C����� �࿡ ���� �����Ҵ�
		for(i = 0; i < C_m; i++)
			matrix_C[i] = (int *)malloc(sizeof(int) * C_n); // C����� �� �ؿ� ���� ������ֱ����� �ݺ������Ҵ�

		printf("A �� B ����� ���� ���� ��� =\n");
		for(i = 0; i < A_m; i++) // A����� �� ���Ҹ� �ҷ����� ���� �ݺ���
			for(j = 0; j < B_n; j++) // B����� �� ���Ҹ� �ҷ����� ���� �ݺ���
			{
				matrix_C[i][j] = 0; // �� ����� ���ҵ��� ���� �����ؼ� ���ؾ� �ϹǷ� 0���� �ʱ�ȭ
				for(k = 0; k < A_n; k++)
					matrix_C[i][j] +=  matrix_A[i][k] * matrix_B[k][j];
									// A, B����� ��������� �����ؼ� ���ϰ� C����� ���ҷ� ����
			}

		for(i = 0; i < C_m; i++)
		{
			for(j = 0; j < C_n; j++)
				printf("%3d ", matrix_C[i][j]); // ����� C����� ���
			printf("\n");
		}

		for(i = 0; i < A_n; i++)
			free(matrix_A[i]);
		free(matrix_A); // A����� �����Ҵ� 2���� �迭�� �޸� �ݳ�

		for(i = 0; i < B_n; i++)
			free(matrix_B[i]);
		free(matrix_B); // B����� �����Ҵ� 2���� �迭�� �޸� �ݳ�

		for(i = 0; i < C_n; i++)
			free(matrix_C[i]);
		free(matrix_C); // C����� �����Ҵ� 2���� �迭�� �޸� �ݳ�
	}
	else
		printf("A����� n���� B����� m���� ���� �޶� ���������� ������ �� �����ϴ�.\n");
														// ����� �������������� false�ϰ�� ��� ���

	return 0;
}