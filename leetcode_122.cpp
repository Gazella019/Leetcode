



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if(prices.size() == 0 || prices.size() == 1)
        	return 0;
        vector<int> v;
        int res = 0;

        for(int i=1;i<prices.size();i++){
        	v.push_back(prices[i]-prices[i-1]);
        }

        for(int i=0;i<v.size();i++){
        	if(v[i] > 0)
        		res = res + v[i];
        }
        return res;
    }
};