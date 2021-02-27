


// Yesssssssssssss !!!!

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int i, k;
        if(prices.size() == 0)
        	return 0;

        vector<vector<int>> buy(2, vector<int> (prices.size(), 0));
        vector<vector<int>> sell(2, vector<int> (prices.size(), 0));
        
        buy[0][0] = -prices[0];
        sell[0][0] = 0;

        // buy[1][0] = 0; // The Trick is here 
        buy[1][0] = -prices[0];
        sell[1][0] = 0;
        for(i=1;i<prices.size();i++){
        	buy[0][i] = max(buy[0][i-1], -prices[i]);
        	sell[0][i] = max(sell[0][i-1], buy[0][i-1]+prices[i]);
        	buy[1][i] = max(buy[1][i-1], sell[0][i-1]-prices[i]);
        	sell[1][i] = max(sell[1][i-1], buy[1][i-1]+prices[i]);
        }

        cout << "buy[0]: ";
        for(i=0;i<prices.size();i++){
        	cout << buy[0][i] << " ";
        }
        cout << endl;
        cout << "sell[0]: ";
        for(i=0;i<prices.size();i++){
        	cout << sell[1][i] << " ";
        }

        return sell[1][prices.size()-1];
    }
};


// TLE 199/200

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if(prices.size() == 0)
        	return 0;

        int i, j, k, profit, minPrice, res = 0, n;

        for(i=1;i<prices.size();i++){
        	res = max(res, intervalMaxProfit(prices, 0, i-1) + intervalMaxProfit(prices, i, prices.size()-1));
        }
        res = max(res, intervalMaxProfit(prices, 0, prices.size()-1));
        return res;
    }


    int intervalMaxProfit(vector<int>& prices, int l, int r){
    	int profit = 0, minPrice = INT_MAX;
    	for(int i=l;i<=r;i++){
    		minPrice = min(minPrice, prices[i]);
    		profit = max(profit, prices[i] - minPrice);
    	}
    	return profit;
    }
};