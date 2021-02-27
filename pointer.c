#include<stdio.h>
#include<stdlib.h>


void main(){

	int p = 0, num =2;
	int **b;
	int **arr = (int**)malloc(num * sizeof(int*));
	for (int i = 0; i < num; i++) 
		arr[i] = (int*)malloc(num * sizeof(int));

	arr[0][0] = 2;
	arr[1][1] = 4;

	int arrr[2][2] = {
		{1,2},
		{5,6}
	};

	//ptr = &val;
	*b = arrr[0];

	//printf("%d\n", b[1]);
	printf("%d\n", b[0][0]);
	/* 
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			printf("%d %d %d\n",i, j, arr[i][j]);
		}
	} */

}
