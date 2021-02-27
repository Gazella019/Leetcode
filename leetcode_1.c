#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    
    int n1, n2;
    *returnSize = 0;
        
	for(int i = 0;i < numsSize; i++){
		for (int j = i+1; j < numsSize; j++){
			if(nums[i] + nums[j] == target){
				n1 = i;
				n2 = j;
				break;
			}	
		}
	}

    * returnSize = 2;
    int *arr = (int*)malloc(sizeof(int)*2);
    arr[0] = n1;
    arr[1] = n2;
    return arr;
}



void main(){

	int nums[] = {2, 7, 11, 15, 1};
	int i, j, numlen, n1, n2, target = 16;

	numlen = sizeof(nums) / sizeof(int);
	printf("length = %d\n", numlen);
	for(i = 0;i < numlen; i++){
		for (j = i+1; j < numlen; j++){
			if(nums[i] + nums[j] == target){
				n1 = i;
				n2 = j;
				break;
			}	
		}
	}

	
	printf("[%d, %d]\n",n1, n2); 

}