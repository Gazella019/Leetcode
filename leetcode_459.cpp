



class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int i, j, size, bias, count;
        bool tf = true;
        size = s.size();
        for(i=0;i<size-1;i++){
        	if(size%(i+1) == 0){
        		// bias is the length of substring
        		tf = true;
        		bias = i+1;
        		j = i+1;
        		count = 1;
        		while(j<size && tf){
        			if(s[j] != s[j-bias])
        				tf = false;
        			if(count == bias){
        				count = 0;
        				bias = bias*2;
        			}
        			count++;
        			j++;
        		}
        		if(tf)
        			return true;
        	}
        }
        return false;
    }
};



