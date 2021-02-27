




class Solution {
public:
    string longestPalindrome(string s) {
    	if(s.size() == 0)
    		return "";

    	int table[s.size()][s.size()] = {0};
    	int i, j, max = 0, resi, resj;
    	string str;

    	for(i=0;i<s.size();i++){
    		table[i][i] = 1;
    		max = 1;
    		resi = i;
    		resj = i;
    	}
    	for(i=1;i<s.size();i++){
    		if(s[i-1] == s[i]){
    			table[i-1][i] = 2;
    			max = 2;
    			resi = i-1;
    			resj = i;
    		}
    	}    

    	for(i=3;i=<s.size();i++){
    		for(j=0;j<s.size();j++){
    			if(j+i-1 < s.size()){
    				cout << j << " " << j+i-1 << endl;
    				if(table[j+1][j+i-1-1] >0){
    					if(s[j] == s[j+i-1]){
    						table[j][j+i-1] = table[j+1][j+i-1-1] +2;
    						if(table[j][j+i-1] > max){
    							max = table[j][j+i-1];
    							resi = j;
    							resj = j+i-1;
    						}
    					}
					}
					else
    					table[j][j+i-1] = 0;
    			}
    			
    		}
    	}

    	for(i=0;i<s.size();i++){
    		for(j=0;j<s.size();j++){
    			cout << " " << table[i][j];
    		}
    		cout << endl;
    	}
    	for(i=resi;i<=resj;i++){
    		str.push_back(s[i]);
    	}
    	return str;
    }
};