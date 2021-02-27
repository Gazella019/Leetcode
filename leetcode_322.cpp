


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int i, j;
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;

        for(i=1;i<=amount;i++){
        	for(j=0;j<coins.size();j++){
        		if(i-coins[j] >= 0 && dp[i-coins[j]] != INT_MAX){
        			dp[i] = min(dp[i], dp[i-coins[j]]+1);
        		}
        	}
        }

        for(i=0;i<=amount;i++){
        	cout << dp[i] << " ";
        }

        if(dp[amount] == INT_MAX)
        	return -1;
        return dp[amount];
    }
};