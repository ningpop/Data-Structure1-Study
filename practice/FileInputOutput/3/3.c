/*
	�ۼ���: 2019.03.12
	�ۼ���: 20154015 �̳���
	���α׷���: �ڷᱸ��1 �ǽ� 1�� ����������� �̿��� ������ ��� ���α׷�
*/

#include <stdio.h>

int main(void)
{
	FILE *fp = NULL;
	int i=0, j=0, result;
	char c;

	fp = fopen("data.txt", "w"); // fopen���� data.txt ������ ������� ����.
	if(fp == NULL)
	{
		printf("���� ���� ����\n"); // fp�� NULL�̸� ���� �޽��� ����ϰ� ����.
		return 0;
	}

	
	// data.txt ���Ͽ� �������� �ۼ��ϴ� �ݺ���.
	for(i = 1 ; i <= 9 ; i++)
	{
		for(j = 1 ; j <= 9 ; j++)
			fprintf(fp, "%d * %d = %d\n", i, j, i*j);
		if(i != 9)
			fprintf(fp, "\n"); // 9�ܱ��� �� �� ���̿� ���๮�� �ۼ�
	}
	
	fclose(fp); // fclose�� ���������� ����.
	
	fp = fopen("data.txt", "r"); // fopen���� data.txt ������ �б���� ����.
	if(fp == NULL)
	{
		printf("���� ���� ����\n"); // fp�� NULL�̸� ���� �޽��� ����ϰ� ����.
		return 0;
	}
	
	// data.txt���� �� ������ ����������(���������� fp�� ������ ��������) �ݺ�.
	while(!feof(fp))
	{
		if(i == 9 && j == 9)
			break; // 9 * 9 = 81���� ����ϰ� �� �ڿ��� �ݺ��� Ż��.
		fscanf(fp, "%d %c %d %c %d", &i, &c, &j, &c, &result);
				// fscanf�� data.txt���Ͽ��� ������ ���� ���� ����. ������ȣ�� ��ȣ�� �б⸸ ��.
		
		if(j==1)
			printf("<< %d���Դϴ� >>\n", i); // ���� ���ۺκ� ���.
		printf("%d * %d = %d\n", i, j, result); // ������ ���.
		if(j == 9)
			printf("\n"); // �������� ���κ� ���๮�� ����.
	}
	
	fclose(fp); // ���������� ����.
		
	return 0;
}