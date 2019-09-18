/*
	�ۼ���: 2019.04.03
	�ۼ���: 20154015 �̳���
	���α׷���: ��Ģ���� ���� ����ð� ��
*/

#include <stdio.h>
#include <time.h>

int main(void)
{
	int num, sum, i;
	char input; // �����ȣ ������ ����
	clock_t start, finish; // ����ð��� ���۽ð�, ���ð��� ������ ���� ����
	double time; // ����ð��� ������ ����

	printf("������ �����ϼ���(+, -, *, /) : ");
	scanf("%c", &input); // ����ڷκ��� ������ �Է�

	printf("���ڸ� �Է��ϼ��� : ");
	scanf("%d", &num); // ����ڷκ��� ���� �Է�

	switch(input) // �Է¹��� �����ȣ�� ���� ����.
	{
	case '+':
		start = clock(); // ������۽ð� ����
		for(i = 1; i <= num; i++)
			sum = 100000000 + i;
		finish = clock(); // ���ೡ�ð� ����
		break;
	case '-':
		start = clock(); // ������۽ð� ����
		for(i = 1; i <= num; i++)
			sum = 100000000 - i;
		finish = clock(); // ���ೡ�ð� ����
		break;
	case '*':
		start = clock(); // ������۽ð� ����
		for(i = 1; i <= num; i++)
			sum = 100000000 * i;
		finish = clock(); // ���ೡ�ð� ����
		break;
	case '/':
		start = clock(); // ������۽ð� ����
		for(i = 1; i <= num; i++)
			sum = 100000000 / i;
		finish = clock(); // ���ೡ�ð� ����
		break;
	default:
		printf("�����ڸ� �ٽ� �Է��ϼ���\n"); // ������ �����ڰ� �ƴ� ��� ���â ��� �� ���α׷� ����
		return 0;
	}

	time = (double)(finish - start) / CLOCKS_PER_SEC; // ����ð� ����

	printf("�ɸ� �ð��� %.3f�Դϴ�.\n", time);

	return 0;
}