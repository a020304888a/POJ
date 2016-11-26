/* Name: POJ_1050.c
   Purpose: To the max.
   Auther: T. W. Chang 
   Key Point: Using DP and Compress 2-D Array into 1-D 
   Descripition: Practice template method and dynamic programming. */

#include<stdio.h>

/* Min of this question is -127 */
#define d_MIN			-128
#define d_MAX_INPUT_ARRAY	100

typedef void (* input)(int *, int *);
typedef void (* output)(int);
typedef int  (* calculate)(int, int *);

struct Interface {
	input Input;
	calculate Calculate;
	output Output;
};


/* get max sum of sequence in 1D array */
int max_sub_1D_array(int subArray[], int size)
{
        int DP[size];
        int max;
        max = DP[0] = subArray[0];

        /* DP */
        for(int i = 1;i < size;i ++){
                if(DP[i - 1] > 0) DP[i] = DP[i - 1] + subArray[i];
                else DP[i] = subArray[i];

                if(max < DP[i]) max = DP[i];
        }

        return max;
}

void POJ_1050_Input(int *N, int *InputData)
{
	int i, j;
	int n;
	scanf("%d", &n);
        for(i = 0;i < n;i ++){
                for(j = 0;j < n;j ++){
                        scanf("%d", (InputData + (i*n+j)));
                }
        }

	*N = n;
	return ;
}

int POJ_1050_Calculate(int N, int *Data)
{
	int max = d_MIN;
	int temp;
	int sum;

	 //DP & add row[x] (from row[x+1] to row[n-1]) & x is for 0 to n - 1
        for(int i = 0;i < N;i ++){
                temp = max_sub_1D_array(Data + (i*N),N);
                if(temp > max) max = temp;
                for(int j = i+1;j < N;j ++){
                        for(int k = 0;k < N;k ++) *(Data + (i*N+k)) += *(Data + (j*N+k));
                        temp = max_sub_1D_array(Data + (i*N), N);
                        if(temp > max) max = temp;
                }
        }

	return max;
}

void POJ_1050_Output(int OutputData)
{
	printf("%d", OutputData);
	return ;
}

void Run_POJ(struct Interface POJ)
{
	int N;
	int InputData[d_MAX_INPUT_ARRAY][d_MAX_INPUT_ARRAY] = {0};
	int OutputData;
	
	POJ.Input(&N, InputData[0]);
	OutputData = POJ.Calculate(N, InputData[0]);
	POJ.Output(OutputData);

	return ;
}

int main()
{
	struct Interface POJ_1050;
	POJ_1050.Input = POJ_1050_Input;
	POJ_1050.Calculate = POJ_1050_Calculate;
	POJ_1050.Output = POJ_1050_Output;
	Run_POJ(POJ_1050);

	return 0;
}
