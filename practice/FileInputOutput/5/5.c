/*
	�ۼ���: 2019.03.24
	�ۼ���: 20154015 �̳���
	���α׷���: ���Ͼȿ� �ִ� ������ ����ϰ� �ҹ���, �빮��, ����, ������ ������ ����ϴ� ���� ī���� ���α׷�
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE *fp = NULL; // ���������� ����
	char string[50], full_string[100], file_name[10];
	int i = 0, small_count = 0, big_count = 0, number = 0, blank = 0, other = 0;


	printf("���� �̸�: ");
	scanf("%s", file_name); // ���� �̸� �Է¹ޱ�

	fp = fopen(file_name, "r"); // fopen���� ���� ����

	if(fp == NULL)
	{
		printf("���� ���� ����\n");
		return 0; // ���������� fp�� NULL�ϰ�� �����޽����� �Բ� ���α׷� ����
	}

	fgets(string, 50, fp); // ���Ͽ��� ���ڿ� ���� �о� string�� ����
	string[strlen(string)-1] = '\0'; // ���ڿ� ���� ���๮�ںκ��� NULL���ڷ� ��ü
	puts(string); // ���ڿ� ��� �� ����
	strcpy(full_string, string); // ��ü ���ڿ��� ���� ���ڿ� ����

	while(!feof(fp)) // ������ ���� �ƴϸ� ��� �ݺ�
	{
		fgets(string, 50, fp); // ���Ͽ��� ���ڿ� ���� �о� string�� ����
		if(string[strlen(string)-1] == '\n') // ���ڿ��� ���κ��� ���๮���϶�
			string[strlen(string)-1] = '\0'; // ���๮�� ��� NULL���� ����
		puts(string); // ���ڿ� ��� �� ����
		strcat(full_string, string); // ��ü ���ڿ� �ڿ� ���� ���ڿ� ���̱�
	}

	for(i = 0 ; i < 100 ; i++) // ��ü ���ڿ�����
	{
		if(full_string[i] >= 97 && full_string[i] <= 122) // ASCII�ڵ尪 �� �ҹ����϶�
			small_count++; // �ҹ��� ���� ����
		else if(full_string[i] >= 65 && full_string[i] <= 90) // ASCII�ڵ尪 �� �빮���϶�
			big_count++; // �빮�� ���� ����
		else if(full_string[i] >= 48 && full_string[i] <= 57) // ASCII�ڵ尪 �� �����϶�
			number++; // ���� ���� ����
		else if(full_string[i] == 32) // ASCII�ڵ尪 �� ���鹮���϶�
			blank++; // ���� ���� ����
		else
			other++; // �׹��� ���� ���� ����. but, ������� ����
	}

	printf("\n==%s ����==\n", file_name);
	printf("\t�ҹ���: %d ��\n", small_count);
	printf("\t�빮��: %d ��\n", big_count);
	printf("\t����: %d ��\n", number);
	printf("\t����: %d ��\n", blank);
	
	fclose(fp);
	return 0;
}