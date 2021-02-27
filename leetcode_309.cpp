


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if(prices.size() == 0 || prices.size() == 1)
            return 0;
        vector<int> sell(prices.size(), 0);
        vector<int> buy(prices.size(), 0);
        vector<int> rest(prices.size(), 0);
        int i, res;
        sell[0] = -prices[0];
        buy[0] = -prices[0]; 
        rest[0] = 0; 
        for(i=1;i<prices.size();i++){
            buy[i] = max(buy[i-1], rest[i-1]-prices[i]);
            sell[i] = max(sell[i-1], buy[i-1]+prices[i]);
            rest[i] = max(rest[i-1], sell[i-1]);
        }

        return max(rest[prices.size()-1], sell[prices.size()-1]);
    }
};



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if(prices.size() == 0 || prices.size() == 1)
            return 0;

        vector<int> sell(prices.size(), 0);
        vector<int> buy(prices.size(), 0);
        int i, res;
        buy[0] = -prices[0];
        buy[1] = max(buy[0], -prices[1]);
        sell[0] = 0;
        sell[1] = max(0, prices[1]-prices[0]);

        for(i=2;i<prices.size();i++){
            buy[i] = max(buy[i-1], sell[i-2] - prices[i]);
            sell[i] = max(sell[i-1], buy[i-1] + prices[i]);
        }

        return sell[prices.size()-1];
    }
};



class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	
    	if(prices.size() == 0 || prices.size() == 1)
    		return 0;
    	vector<int> sell(prices.size(), 0);
    	vector<int> buy(prices.size(), 0);
    	int i, res;
    	buy[0] = -prices[0];
    	buy[1] = buy[0] + prices[0] - prices[1];
    	sell[0] = 0;
    	sell[1] = max(0, prices[1]-prices[0]);
    	res = sell[1];
    	for(i=2;i<prices.size();i++){
    		sell[i] = max(buy[i-1] + prices[i], sell[i-1]-prices[i-1]+prices[i]);
    		if(sell[i] > res)
    			res = sell[i];
    		buy[i] = max(sell[i-2] - prices[i], buy[i-1]+prices[i-1]-prices[i]);
    	}

    	return res;
  	}
};




class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if(prices.size() == 0 || prices.size() == 1)
    		return 0;
    	int dp[prices.size()][prices.size()] = {0};
    	int i, j, l, end;
    	for(i=0;i<prices.size();i++){
    		dp[i][i] = 0;
    	}

    	for(i=0;i+1<prices.size();i++){
    		dp[i][i+1] = max(0, prices[i+1] - prices[i]);
    	}

    	for(l=3;l<=prices.size();l++){
    		for(i=0;i+l-1<prices.size();i++){
    			end = i+l-1;
    			dp[i][end] = max(0, prices[end] - prices[i]);
    			dp[i][end] = max(dp[i][end], dp[i+1][end]);
    			dp[i][end] = max(dp[i][end], dp[i][end-1]);
    			for(j=i+1;j<end;j++){
    				dp[i][end] = max(dp[i][end], dp[i][j-1] + dp[j+1][end]);
    			}
    		}
    	}

    	for(i=0;i<prices.size();i++){
    		for(j=0;j<prices.size();j++){
    			cout << dp[i][j] << " ";
    		}
    		cout << endl;
    	}

    	return dp[0][prices.size()-1];
    }
};

