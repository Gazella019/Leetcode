

// Runtime: 0 ms, faster than 100.00% of C++
// Memory Usage: 8.2 MB, less than 100.00% of C++

class Solution {
public:
    int addDigits(int num) {
    	if(num == 0)
    		return 0;
    	int sum = 0;
    	while(1){
    		sum = sum + (num % 10);
    		num = num / 10;
    		if(num == 0){
    			if((sum/10) == 0)
    				break;
    			num = sum;
    			sum = 0;
    		}
    	}    
    	return sum;
    }

};