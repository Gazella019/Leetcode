#include<stdio.h>
#include<stdlib.h>


int mySqrt(int x){

    int i, half, ans;
	half = x / 2;
	if(x == 1){
		ans = 1;
	}
	else{
		for(i=1; i <= half; i++){
			if(i == 46340){
				ans = i;
	            break;
			}
			else{
				if(i*i <= x){
					if((i+1) * (i+1) > x){
						ans = i;
						break;
					}
				}
			}
		}
	}
	return ans;
}

// 注意int 的上限 2,147,483,647
// 46341 * 46341 > 2,147,483,647

void main(){

	int out, x = 1;
	out = mySqrt(x);
	printf("%d\n", out);

}