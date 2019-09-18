/*
	�ۼ���: 2019.04.22
	�ۼ���: 20154015 �̳���
	���α׷���: ���� ���� ���α׷�
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Student{ // Student ����ü ����
		int student_num;
		char name[10];
		int kor, math, eng;
} STUDENTS; // typedef�� ����Ͽ� STUDENTS�� ġȯ (�ڷ���ó�� ��� ����)

int main(void)
{
	FILE *fp = NULL;
	STUDENTS *students_info; // STUDENTS �������� students_info ��� ����ü ����
	char read_temp[50];
	int i = 0, limits;

	fp = fopen("data.txt", "r"); // fopen���� data.txt������ �б���� ����

	if(fp == NULL) // ���������Ͱ� NULL�϶� ���â ��� �� ���α׷� ����
	{
		printf("���Ͽ��� ����\n");
		return 0;
	}

	while(!feof(fp)) // ���������Ͱ� ���� ������ ������ �ݺ�
	{
		fgets(read_temp, 50, fp); // �ٴ����� ���� ������ ����
		i++; // i���� �������� �ο��� ���
	}

	students_info = (STUDENTS *)malloc(i * sizeof(STUDENTS)); // ���� �ο�����ŭ ���� �Ҵ�

	rewind(fp); // ���������� �� ������ �̵�
	i = 0; // i�� 0���� �ٽ� �ʱ�ȭ
	while(!feof(fp)) // ���������Ͱ� ���� ������ ������ �ݺ�
	{
		// data.txt ���� ���� ���Ŀ� ���� ������ ����
		fscanf(fp, "%d %s %d %d %d", &students_info[i].student_num, students_info[i].name, &students_info[i].kor, &students_info[i].math, &students_info[i].eng);
		i++; // �ο�����ŭ i���� ������Ŵ
	}

	limits = i; // i���� ��°��� �������� ����

	printf("====�й�=======�̸�==����==����==����===\n");
	for(i = 0; i < limits; i++) // ���ѵ� ����ο�����ŭ �ݺ�
		//���Ŀ� ���� ���(��� ������ �����Ͽ� �����͵��� ���� ���� ����)
		printf("%d%11s%6d%6d%6d\n", students_info[i].student_num, students_info[i].name, students_info[i].kor, students_info[i].math, students_info[i].eng);
	printf("========================================\n");

	free(students_info); // ���� �Ҵ� �޸� �ݳ�
	fclose(fp); // fclose�� ���� �ݱ�
	return 0;
}