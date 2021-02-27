#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	//code
	
	int t, i, k, j, n, val, len , T, minv;
	string s;
	cin >> T;
	for(t=1;t<=T;t++){
	    
	    cin >> len;
	    cin >> s;
	    int table[len][len] = {0};
	    for(i=0;i<len;i++){
        	table[i][i] = 1;
        }
        
        
        for(i=0;i<len-1;i++){
        	if(s[i] == s[i+1]){
        		table[i][i+1] = 1;
        	}
        	else
        		table[i][i+1] = 2;
        }
        
        
        for(k=3;k<=len;k++){
        	for(i=0;i+k-1<len;i++){
        		j = i+k-1;
        		if(s[i]==s[j])
                    table[i][j]=table[i+1][j-1];
                else
                    table[i][j]=len;
                    
        		for(n=i;n<j;n++){
        			val = table[i][n] + table[n+1][j];
        			if(val < table[i][j])
        			    table[i][j] = val;
        		}
        	}
        }
        cout << table[0][len-1] << endl;
	}
	return 1;
}