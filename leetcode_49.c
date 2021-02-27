#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printList(int *list){
	int len, i;
	len = 5;
	for(i=0;i<len;i++)
		printf("%d",list[i]);
}


void main(){

	int len, i, j, k , g, num;

	char input[10][10] = {
		{'e','a','t'},
		{'t','e','a'},
		{'t','a','n'},
		{'a','t','e'},
		{'n','a','t'},
		{'b','a','t'},
	};
	int list[5] = {0,0,0,0,0};

	len = strlen(input[0]);
	printf("%d\n", len);

	// 字串長度還沒調整好,先用固定的
	for(i=0;i<=3;i++){
		num = input[0][i];
		// 固定一個字母
		for(j=1;j<=5;j++){
			for(k=1;k<=2;k++){
				if(num == input[j][k]){
					list[j] = 1;
				}
			}
		}

	}

	printList(list);

}