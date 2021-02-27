




class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        
    	int i, mx, res = 0, end, sum = 0, mul = 1, index = -1;
    	sort(satisfaction.begin(), satisfaction.end());

    	for(i=0;i<satisfaction.size();i++){
    		if(satisfaction[i] >= 0){
    			if(index < 0)
    				index = i;
    			res = res + satisfaction[i] * mul;
    			sum = sum + satisfaction[i];
    			mul ++;
    		}
    	}
    	mx = res;

    	for(i=index-1;i>=0;i--){
    		res = res + sum + satisfaction[i];
    		sum = sum + satisfaction[i];
    		mx = max(mx, res);
    	}

    	return mx;
    }
};