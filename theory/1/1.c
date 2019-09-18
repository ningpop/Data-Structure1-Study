/*
	�ۼ���: 2019.03.14
	�ۼ���: 20154015 �̳���
	���α׷���: ����������� �̿��� ���� �ִ�/�ּҰ� ��� ���α׷�
*/

#include <stdio.h>

int max_compare(int num1, int num2); // �ִ밪 �� �Լ�
int min_compare(int num1, int num2); // �ּҰ� �� �Լ�

int main(void)
{
	FILE *fp = NULL;
	int i, j, max, min, eon, temp, value;
	/* ���� ����-
	i, j: �ݺ��� �� �迭 index ���ٺ���
	max, min: �ִ�/�ּҰ� ���庯��
	eon: end of number�� ���ڷ� 10000���� �迭�� �Էµ� ���� ����� ��(���� ����)
	temp: ���پ� ���� ��� �� �� ���� ó�� ���� index�� �����ص� ����
	value: switch�� ���� ������ �ִ�/�ּ�/�Ϲݰ��� ��Ÿ���� ���� */
	int number[10000] = { NULL };

	fp = fopen("data.txt", "r"); // data.txt file open

	if (fp == NULL)
	{
		printf("����: ������ ������ �ʽ��ϴ�.\n"); // ���� open�� ����ó��
		return 0;
	}

	i = 0;
	while(!feof(fp))
	{
		if(i >= 10000)
		{
			printf("���ڰ� 10000���� �ѽ��ϴ�.\ndata.txt ������ Ȯ���ϼ���.\n");
					// ������ ������ 50 ~ 10000���̹Ƿ� 10000�� �̻��� ��� ���α׷� ����
			return 0;
		}

		fscanf(fp, "%d", &number[i]); // data.txt ���ڸ� number�迭�� ����
		i++;
	}
	
	eon = i - 1; // ���� �ݺ��Ͽ� ���ڸ� ��½�Ű�� ���� eon �� ����

	if (i - 1 < 49)
	{
		printf("������ 50�� �̸��Դϴ�.\ndata.txt�� ������ �� �Է��ϼ���\n");
					// ������ ������ 50 ~ 10000���̹Ƿ� 50�� ������ ��� ���α׷� ����
		return 0;
	}

	max = number[0]; // �ʱⰪ�� �ִ밪���� ����
	min = number[0]; // �ʱⰪ�� �ּҰ����� ����
	for (i = 1; i < eon ; i++)
	{
		max = max_compare(max, number[i]); // ���� ��� �� �ִ밪 ����
		min = min_compare(min, number[i]); // ���� ��� �� �ּҰ� ����
	}

	for (i = 0; i <= eon/10; i++)
		// ���� eon�� �̿��� ��� �� �������� �ݺ� ex) ���� ���� 53�� -> ������, �ִ�/�ּ��� 1set�� �� 6�� ���
	{
		temp = i*10; // �� ������� ���� ù��° index�� �ӽ� ����
		if(i == eon/10)
			for (j = 0; j < eon % 10; j++)
				printf("%d\t", number[i * 10 + j]);
					// 10���� ����ϰ� ���� ������ ���ڵ��� �ݺ� ��¹� ex) 53�� -> �������ٿ� ������ 3�� ���
		else
			for (j = 0; j < 10; j++)
				printf("%d\t", number[i * 10 + j]);
					// 10���� ����� ���� ���� �ݺ� ��¹� ex) 53�� -> 50������ ���
		printf("\n"); // ���� ��� �� ����
		
		if (i == eon / 10)
			for (j = 0; j < eon % 10; j++) // �������� ������ ���� ����ٿ� ���� �ִ�/�ּҰ� ��� �ݺ���
			{
				if (max == number[temp])
					value = 'M'; // �ִ밪�ϰ�� value���� Max�� ����
				else if (min == number[temp])
					value = 'm'; // �ּҰ��ϰ�� value���� min�� ����
				else
					value = 'c'; // �Ϲݰ��ϰ�� value���� common�� ����

				switch (value)
				{
				case 'M':
					printf("�ִ밪\t", number[temp]); // '�ִ밪' ���
					temp++;
					break;
				case 'm':
					printf("�ּҰ�\t", number[temp]); // '�ּҰ�' ���
					temp++;
					break;
				default:
					printf("\t", number[temp]); // �Ϲݰ��̹Ƿ� \t���� �Ѿ
					temp++;
					break;
				}
			}
		else
			for (j = 0; j < 10; j++) // ���� 10���� ����ٿ� ���� �ִ�/�ּҰ� ��� �ݺ���
			{
				if (max == number[temp])
					value = 'M'; // �ִ밪�ϰ�� value���� Max�� ����
				else if (min == number[temp])
					value = 'm'; // �ּҰ��ϰ�� value���� min�� ����
				else
					value = 'c'; // �Ϲݰ��ϰ�� value���� common�� ����

				switch (value)
				{
				case 'M':
					printf("�ִ밪\t", number[temp]); // '�ִ밪' ���
					temp++;
					break;
				case 'm':
					printf("�ּҰ�\t", number[temp]); // '�ּҰ�' ���
					temp++;
					break;
				default:
					printf("\t", number[temp]); // �Ϲݰ��̹Ƿ� \t���� �Ѿ
					temp++;
					break;
				}
			}
		printf("\n"); // �ִ�/�ּҰ� ��� or �ش����� ��� �Ϲݰ��ϰ�� ����
	}

	fclose(fp); // data.txt file close
	return 0; // ���α׷� ����
}

int max_compare(int num1, int num2) // �ִ밪 �� �Լ�
{
	if (num1 > num2)
		return num1;
	else
		return num2;
}

int min_compare(int num1, int num2) // �ּҰ� �� �Լ�
{
	if (num1 < num2)
		return num1;
	else
		return num2;
}