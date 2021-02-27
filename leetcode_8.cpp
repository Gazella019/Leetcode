

// INT_MAX 2147483647
// Runtime: 4 ms, faster than 84.20% of C++
// Memory Usage: 8.5 MB, less than 52.24% of C++

class Solution {
public:
    int myAtoi(string str) {
    	int i, sign = 1, sum = 0, start, num;
        for(i=0;i<str.size();i++){
        	if(str[i] != ' '){
        		if(str[i] <= '9' && str[i] >= '0')
        			sum = str[i] - '0';
        		else if(str[i] == '+')
        			sign = 1;
        		else if(str[i] == '-')
        			sign = -1;
        		else
        			return 0;
        		start = i;
        		break;
        	}
        }

        for(i=start+1;i<str.size();i++){
            num = str[i] - '0';
        	if(num >= 0 && num <= 9){
        		if(sum >= 214748365){
        			if(sign == 1)
        				return INT_MAX;
        			else
        				return INT_MIN;
        		}
                else if(sum == 214748364){
                    if(sign == 1 && num >= 8)
                        return INT_MAX;
                    if(sign == -1 && num >= 8)
                        return INT_MIN;
                }
        		sum = sum * 10 + num;
        	}
        	else
        		break;
        }

        return sign * sum;
    }
};