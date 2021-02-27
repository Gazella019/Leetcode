




class Solution {
public:

    bool isInterleave(string s1, string s2, string s3) {
		
		int i, j, m, n, cur;
		m = s1.size(), n = s2.size();
		if(m+n != s3.size())
			return false;
		vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
		dp[0][0] = 1;
		cur = 0;

		for(i=1;i<=n;i++){
			if(s2[i-1] == s3[cur])
				dp[0][i] = dp[0][i-1];
			else
				dp[0][i] = 0;
			cur ++;
		}

		for(i=1;i<=m;i++){
			cur = i-1;
			if(s1[i-1] == s3[cur])
				dp[i][0] = max(dp[i][0], dp[i-1][0]);
			cur ++;
			for(j=1;j<=n;j++){
				if(s1[i-1] == s3[cur])
					dp[i][j] = max(dp[i][j], dp[i-1][j]);
				if(s2[j-1] == s3[cur])
					dp[i][j] = max(dp[i][j], dp[i][j-1]);
				cur ++;
			}
		}

		for(i=0;i<=m;i++){
			for(j=0;j<=n;j++){
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}

		return dp[m][n];
    }

};