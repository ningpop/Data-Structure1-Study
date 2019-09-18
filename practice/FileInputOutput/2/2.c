/* 20154015 이남준
   2019.03.05
   파일입출력 실습2 */

#include <stdio.h>

int main(void)
{
	int i, number[10];

	FILE* fp = NULL;
	fp = fopen("data.txt", "r");

	for(i = 0 ; i < 10 ; i++)
	{
		fscanf(fp, "%d", &number[i]);
		printf("%d = %d\n", i, number[i]);
	}

	fclose(fp);

	return 0;
}