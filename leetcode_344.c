

void reverseString(char* s, int sSize){

	int i, half;
	char temp;
	half = sSize / 2; 
    if(sSize !=0){
        
        for(i=0;i<half;i++){
		    temp = s[i];
		    s[i] = s[sSize-i-1];
		    s[sSize-i-1] = temp;
            
	    }
    }
}

