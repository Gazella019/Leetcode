#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int canConstruct(char * ransomNote, char * magazine){

	int rlsit[26] = {0};
	int mlist[26] = {0};
	int rlen, mlen, i, index, toogle=1;

	rlen = strlen(ransomNote);
	mlen = strlen(magazine);

	for(i=0;i<rlen;i++){

		index = ransomNote[i] - 97;
		rlsit[index] += 1;

	}

	for(i=0;i<mlen;i++){

		index = magazine[i] - 97;
		mlist[index] += 1;
		
	}

	for(i=0;i<26;i++){

		if(rlsit[i]){
			if(rlsit[i] > mlist[i]){
				toogle = 0;
				break;
			}
		}
		
	}
	return toogle;
}


void main(){

	char ransomNote[10] = {'a'}; 
	char magazine[10] = {'b'}; 
	int toogle;
	
	toogle = canConstruct(ransomNote, magazine);

	if(toogle){
		printf("true");
	}
	else{
		printf("false");
	}

}