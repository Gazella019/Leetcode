



class Solution {
public:
    int numOfWays(int n) {
        
        int i, res, mod = 1e9+7;

        vector<vector<long>> dp(n, vector<long>(2 , 0));
        dp[0][0] = 6, dp[0][1] = 6;

        for(i=1;i<n;i++){
        	dp[i][0] = dp[i-1][0] * 3 + dp[i-1][1] * 2;
        	dp[i][1] = dp[i-1][0] * 2 + dp[i-1][1] * 2;
        	dp[i][0] %= mod;
        	dp[i][1] %= mod;
        }

        res = (dp[n-1][0] + dp[n-1][1])%mod;
       	return res;
    }
};