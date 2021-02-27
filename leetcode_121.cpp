



class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	
    	int i, j, size, max, now;
    	vector<int> s, result;
    	size = prices.size();
    	if(size == 0)
    		return 0;
    	if(size == 1)
    		return 0;


    	for(i=1;i<size;i++){
    		s.push_back(prices[i]-prices[i-1]);
    	}

    	now = s[0];
    	max = now;
    	for(i=1;i<size-1;i++){
    		if(now + s[i] > s[i]){
    			now = now + s[i];
    			if(now > max)
    				max = now;
    		}
    		else{
    			now = s[i];
    			if(now > max)
    				max = now;
    		}
    	}
    	
    	if(max<0)
    		max = 0;
    	return max;
    }
};