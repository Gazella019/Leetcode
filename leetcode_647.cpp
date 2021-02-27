




class Solution {
public:
    int countSubstrings(string s) {
    	int i, k, count = 0;
    	int table[s.size()][s.size()]= {0};
    	for(i=0;i<s.size();i++){
    		table[i][i] = 1;
    		count = count + 1;
    	}

    	for(i=0;i<s.size()-1;i++){
    		if(s[i] == s[i+1]){
    			table[i][i+1] = 2;
    			count = count + 1;
    		}
    	}

    	for(k=2;k<s.size();k++){
    		for(i=0;i<s.size();i++){
    			if(i+k<s.size()){
    				if(s[i] == s[i+k]){
    					if(table[i+1][i+k-1] > 0){
    						table[i][i+k] = table[i+1][i+k-1] + 2;
    						count = count + 1;
    					}
    				}
    				else
    					table[i][i+k] == 0;
    			}
    		}
    	}
    	return count;
    }
};