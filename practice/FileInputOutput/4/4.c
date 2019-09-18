/*
	�ۼ���: 2019.03.12
	�ۼ���: 20154015 �̳���
	���α׷���: �ڷᱸ��1 �ǽ� 2�� ����������� �̿��� ��� �������� ���α׷�
*/

#include <stdio.h>

void print_array(char array_name, int arr[3][3]);

int main(void)
{
	FILE *fp = NULL;
	int arr1[3][3], arr2[3][3]; // 3*3�� 2���� �迭 �ΰ��� �����Ѵ�.
	char arr1_name, arr2_name; // �迭 �̸��� ������ ������ ������ �����Ѵ�.
	int x=0, y=0, i, j;

	fp = fopen("data2.txt", "r"); // fopen���� data2.txt ������ �б� ���� ����.

	fscanf(fp, "%c %d %d", &arr1_name, &i, &j);
		// data2.txt ���� ���� ��� �̸�, ��� ũ�⸦ �о�鿩 ������ �����Ѵ�.

	for(x = 0 ; x < i ; x++)
		for(y = 0 ; y < j ; y++)
			fscanf(fp, "%d", &arr1[x][y]);
			// ù��° A ����� ���ҵ��� ��ø for������ �о���̰� 2���� �迭�� �����Ѵ�.
			// �̶�, i�� j�� 2�����迭 index�� �����Ѵ�.

	print_array(arr1_name, arr1);

	fscanf(fp, "%c", &arr2_name); // ���ڸ� �ϳ� �о�鿩 ���������͸� �ϳ� �̵��Ѵ�.

	fscanf(fp, "%c %d %d", &arr2_name, &i, &j);
		// �ٽ� fscanf�� ����� �ι�° ����� �̸�, ũ�⸦ �о� ������ �����Ѵ�.

	for(x = 0 ; x < i ; x++)
		for(y = 0 ; y < j ; y++)
			fscanf(fp, "%d", &arr2[x][y]);
			// �̹����� �ι�° B ����� ���ҵ��� ��ø for������ �о���̰� �迭�� �����Ѵ�.

	print_array(arr2_name, arr2);

	printf("%c + %c �迭 = \n", arr1_name, arr2_name);
		// ���� ����� ����ϱ� ���� ����κ��� ����Ѵ�.

	for(x = 0 ; x < i ; x++)
	{
		for(y = 0 ; y < j ; y++)
			printf("%5d", arr1[x][y]+arr2[x][y]);
		printf("\n");
	} // A ��İ� B����� ���� ����� ��ø for������ ����Ѵ�.
	
	fclose(fp); // fclose�� ����Ͽ� ������ �ݴ´�.
	return 0;
}


void print_array(char array_name, int arr[3][3])
{
	int x, y;

	printf("%c�迭 = \n", array_name); // ����� ��� ���� ��� �̸��� ����Ѵ�.
	for(x = 0 ; x < 3 ; x++)
	{
		for(y = 0 ; y < 3 ; y++)
			printf("%5d", arr[x][y]);
		printf("\n");
	} // ��ø for������ 2���� �迭�� ����� ���ڵ��� 3*3 ��� �������� ����Ѵ�.
}