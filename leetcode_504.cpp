



class Solution {
public:
    string convertToBase7(int num) {
        string str = "", temp = " ";
        int x = num;
        if(x == 0)
        	return "0";
        if(x < 0)
        	x = x * -1;
        while(x!=0){
        	temp[0] = (x % 7) + '0';
        	str = temp + str;
        	x = x / 7;
        }
        if(num < 0){
        	temp[0] = '-';
        	str = temp + str;
        }

        return str;
    }
};