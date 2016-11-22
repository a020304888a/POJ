/* File Name: POJ_1163.c
   Problem  : The Triangle.
   Auther   : T. W. Chang */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	d_MAX_INPUT_SIZE	100

int main()
{
	/* N is number of lines */
	int N = 0;

	/* Store Input Data */
	int Input[d_MAX_INPUT_SIZE][d_MAX_INPUT_SIZE] = {0};

	/* Just used for "loop" */
	int i = 0, j = 0;
	
	/* Get number of lines */
	scanf("%d", &N);

	/* POJ System Error */
	if(N <= 1 || N > 100)
	{
		printf("POJ Input Error\n");
		return -1;
	}

	/* Input data */
	for(i = 0;i < N;i ++)
	{
		for(j = 0;j <= i;j ++)
		{
			scanf("%d", &Input[i][j]);
		}
	}

	/* Calculate */
	for(i = N - 1;i > 0;i --)
	{
		for(j = 0;j < i;j ++)
		{
			if(Input[i][j] >= Input[i][j+1]) Input[i-1][j] += Input[i][j];
			else Input[i-1][j] += Input[i][j+1];
		}
	}

	printf("%d", Input[0][0]);



	return 0;
}
