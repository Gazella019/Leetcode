

// Runtime: 0 ms, faster than 100.00% of C++
// Memory Usage: 8 MB, less than 100.00% of C++ 

class Solution {
public:
    bool detectCapitalUse(string word) {
    	if(word.size() == 0)
    		return true;
        int type = 0, count = 0, i;
        for(i=1;i<word.size();i++){
        	if(word[i] >= 'A' && word[i] <= 'Z'){
        		if(type == 0)
        			type = 1;
        		if(type == 2)
        			return false;
        	}
        	else if(word[i] >= 'a' && word[i] <= 'z'){
        		if(type == 0)
        			type = 2;
        		if(type == 1)
        			return false;
        	}
        	else
        		return false;
        }
        if(type == 1 && (word[0] >= 'a' && word[0] <= 'z'))
        	return false;
        return true;
    }
};