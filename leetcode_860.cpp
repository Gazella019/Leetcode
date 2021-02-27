





class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int i, c10 = 0, c5 = 0;
        for(i=0;i<bills.size();i++){
        	if(bills[i] == 5)
        		c5 ++;
        	else if(bills[i] == 10){
        		c5 --;
        		c10 ++;
        		if(c5 < 0)
        			return false;
        	}
        	else if(bills[i] == 20){
        		if(c5 > 0 && c10 > 0){
        			c5 --;
        			c10 --;
        		}
        		else
        			c5 = c5 -3;
        		if(c5 < 0 || c10 < 0)
        			return false;
        	}
        }
        return true;
    }
};