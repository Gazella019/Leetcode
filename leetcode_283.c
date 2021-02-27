#include <stdio.h>
#include <stdlib.h>

void show(int* nums, int size){
	
	printf("\n");
	int k;
	for(k=0;k<size;k++){
		printf("%d ",nums[k]);
	}
	
}

void main(){

	int a[5] = {0,1,0,3,12};
	int num = 5;
	int i ;
	for(i=0;i<num;i++){
		if(a[i] == 0){
			int j = 1;
			while(i+j != num){
				
				if(a[i+j] != 0){
					int temp;
					temp = a[i];
					a[i] = a[i+j];
					a[i+j] = temp;
					break;
				}
				
				j = j + 1;
			}
		}
	}
	show(a, num);
}