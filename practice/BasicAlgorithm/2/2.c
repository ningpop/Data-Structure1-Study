/*
	�ۼ���: 2019.04.06
	�ۼ���: 20154015 �̳���
	���α׷���: ������ 5�� ���� ��� ���α׷�
*/

#include <stdio.h>

void print_99dan(int a, int b); // ������ ��� �Լ�

int main(void)
{
	print_99dan(1, 5); // 1 ~ 5�� ���
	print_99dan(6, 9); // 6 ~ 9�� ���

	return 0;
}

void print_99dan(int a, int b) // ������ ��� �Լ�
{
	int i, j;

	for(i = 1 ; i <= 9 ; i++) // �� ���� �������� �� �ݺ�
	{
		for(j = a ; j <= b ; j++) // �Ű����� �Է¹��� ��ŭ ������ �ܼ� ���
			printf("%d * %d = %d\t", j, i, i*j);
		printf("\n");

		if(i == 9)
			printf("\n"); // �������� ���� 9���� �������� �� �� �ٲ� �ѹ� ��
	}
}