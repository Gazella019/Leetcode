
// Runtime: 0 ms, faster than 100.00% of C++
// Memory Usage: 8.5 MB, less than 100.00% of C++

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;

        for(int i=digits.size()-1;i>=0;i--){
        	if(carry + digits[i] >= 10){
        		digits[i] = 0;
        		carry = 1;
        	}
        	else{
        		digits[i] = carry + digits[i];
        		carry = 0;
        	}
        }
        if(carry == 1)
        	digits.insert(digits.begin(), 1);

        return digits;
    }
};