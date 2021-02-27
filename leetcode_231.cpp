


class Solution {
public:
    bool isPowerOfTwo(int n) {
    	int num = 1;
        while(num <= n){
        	if(num == n)
        		return true;
        	if(num == 1073741824)
        		return false;
        	num = num * 2;
        }
        return false;
    }
};