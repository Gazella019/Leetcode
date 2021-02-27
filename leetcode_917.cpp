

// Runtime: 0 ms, faster than 100.00% of C++
// Memory Usage: 8.3 MB, less than 90.91% of C++

class Solution {
public:
    string reverseOnlyLetters(string S) {

        int left, right;
        char temp;
        left = 0;
        right = S.size()-1;
        while(left < right){
        	while(isLetter(S[left]) == false){
        		left ++;
        	}
        	while(isLetter(S[right]) == false){
        		right --;
        	}
        	if(left >= right)
        		break;
        	temp = S[left];
        	S[left] = S[right];
        	S[right] = temp;
        	left ++;
        	right --;
        }
        return S;
    }

    bool isLetter(char c){
    	if(c >= 'a' && c <= 'z')
    		return true;
    	if(c >= 'A' && c <= 'Z')
    		return true;
    	return false;
    }
};