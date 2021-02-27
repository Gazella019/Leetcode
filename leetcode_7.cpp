


class Solution {
public:
    int reverse(int x) {
        
        int res = 0;
        
        while(x != 0){
        	if(abs(res) > (INT_MAX/10))
        		return 0; 
        	res = res * 10;
        	res = res + x % 10;
        	x = x / 10;
        }

        return res;
    }
};


// 2147483647, -2147483648