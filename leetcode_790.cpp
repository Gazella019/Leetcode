



class Solution {
public:

	int mod = 1000000007;

    int numTilings(int N) {
        
        int i;
        vector<vector<long>> dp(N+2, vector<long>(3, 0));
        dp[1][0] = 1;
        dp[1][1] = 0;
        dp[1][1] = 0;

        for(i=2;i<=N+1;i++){
        	dp[i][0] = (dp[i-1][0] + dp[i-2][0] + dp[i-1][1] + dp[i-1][2])%mod;
        	dp[i][1] = (dp[i-2][0] + dp[i-1][2])%mod;
        	dp[i][2] = (dp[i-2][0] + dp[i-1][1])%mod;
        }

        for(i=1;i<dp.size();i++)
        	cout << dp[i][0] << " ";
        cout << endl;
        for(i=1;i<dp.size();i++)
        	cout << dp[i][1] << " ";
        cout << endl;
        for(i=1;i<dp.size();i++)
        	cout << dp[i][2] << " ";
        cout << endl;

        return dp[N+1][0];
    }
};