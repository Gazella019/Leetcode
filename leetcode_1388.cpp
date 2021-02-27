



class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        
        int i, j, res, n, k;
        n = slices.size();
        k = (n/3) + 1;
        vector<vector<int>> dp(slices.size(), vector<int>(k, 0));

        dp[0][1] = slices[0];
        dp[1][1] = max(slices[0], slices[1]);

        for(i=2;i<n-1;i++){
        	for(j=1;j<k;j++){
        		dp[i][j] = max(dp[i-2][j-1] + slices[i], dp[i-1][j]);
        	}
        }
        res = dp[n-2][k-1];

        dp[0][1] = 0;
        dp[1][1] = slices[1];

        for(i=2;i<n;i++){
        	for(j=1;j<k;j++){
        		dp[i][j] = max(dp[i-2][j-1] + slices[i], dp[i-1][j]);
        	}
        }

        for(i=0;i<k;i++){
        	for(j=0;j<n;j++){
        		cout << dp[j][i] << " ";
        	}
        	cout << endl;
        }
        res = max(res, dp[n-1][k-1]);
        return res;
    }
};