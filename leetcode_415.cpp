



class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";
        int n1, n2, carry = 0, sum;
        n1 = num1.size()-1, n2 = num2.size()-1;

        while(n1 >= 0 || n2 >= 0){
        	if(n1 >= 0 && n2 >= 0)
        		sum = num1[n1] - '0' + num2[n2] - '0' + carry;
        	else if(n1 >= 0)
        		sum = num1[n1] - '0'+ carry;
        	else if(n2 >= 0)
        		sum = num2[n2] - '0'+ carry;

        	if(sum >= 10){
        		carry = 1;
        		res = to_string(sum-10) + res;
        	}
        	else{
        		carry = 0;
        		res = to_string(sum) + res;
        	}
        	n1 --, n2 --;
        }
        if(carry == 1)
        	res = "1" + res;
    	return res;
    }
};