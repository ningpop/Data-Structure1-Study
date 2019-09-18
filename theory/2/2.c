/*
	�ۼ���: 2019.04.03
	�ۼ���: 20154015 �̳���
	���α׷���: �˰��� A, B, C�� ����ð� ��
*/

#include <stdio.h>
#include <time.h>

int main(void)
{
	unsigned int al, num, sum = 0, i, j; // ������ ������� �����Ƿ� unsigned int �ڷ��� ���
	clock_t start, finish; // ����ð��� ���۽ð�, ���ð��� ������ ���� ����
	double time;

	do
	{
		printf("�˰����� �����ϼ���(1, 2, 3) : "); // �˰��� ����
		scanf("%d", &al);

		if(al < 1 || al > 3)
			printf("�˰����� �ٽ� �����ϼ���\n"); // �Է¹��� ���ڰ� 1~3������ �ƴ� �ÿ� ���â
		else
			break;
	}while(1);

	printf("���ڸ� �Է��ϼ��� : ");
	scanf("%d", &num);

	switch (al) // ������ �˰����� switch���� �̿��� ��� ����
	{
	case 1: // �˰��� A
		start = clock(); // ������۽ð� ����
		sum = num * num;
		finish = clock(); // ���ೡ�ð� ����
		break;
	case 2: // �˰��� B
		start = clock(); // ������۽ð� ����
		for(i = 1; i <= num; i++)
			sum = sum + num;
		finish = clock(); // ���ೡ�ð� ����
		break;
	case 3: // �˰��� C
		start = clock(); // ������۽ð� ����
		for(i = 0; i <= num; i++)
			for(j = 1; j <= num; j++)
				sum = sum + 1;
		finish = clock(); // ���ೡ�ð� ����
		break;
	default:
		break;
	}

	time = (double)(finish - start) / CLOCKS_PER_SEC; // ����ð� ����

	printf("\n�ɸ��ð��� %f�Դϴ�.\n", time);

	return 0;
}