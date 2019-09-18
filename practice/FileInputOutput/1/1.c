/* 20154015 이남준
   2019.03.05
   파일입출력 실습1 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int number[10], i;

	FILE* fp = NULL;
	fp = fopen("data.txt", "w");

	srand((unsigned)time(NULL));

	for(i = 0 ; i < 10 ; i++)
	{
		number[i] = rand()%100;
		printf("%d = %d\n", i, number[i]);
		fprintf(fp, "%d\n", number[i]);
	}

	fclose(fp);

	return 0;
}