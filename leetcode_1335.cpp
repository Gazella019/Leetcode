


class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        

    	int i, n, k, length, val, start, end;
    	n = jobDifficulty.size();
        vector<vector<int>> dp(n, vector<int> (d+1, 0));

        if(n < d)
        	return -1;

        dp[0][1] = jobDifficulty[0]; 

        for(i=1;i<n;i++){
        	dp[i][1] = max(dp[i-1][1], jobDifficulty[i]);
        }


        for(k=2;k<=d;k++){
        	for(end=k-1;end<n;end++){
        		dp[end][k] = dp[end-1][k-1] + jobDifficulty[end];
        		val = 0;
        		for(start=end;start>=k-1;start--){
        			val = max(val, jobDifficulty[start]);
        			dp[end][k] = min(dp[end][k], dp[start-1][k-1] + val); 
        		}
        	}
        }
        
        for(k=1;k<=d;k++){
        	cout << "d=" << k << " ";
        	for(i=0;i<n;i++){
        		cout << dp[i][k] << " ";
        	}
        	cout << endl;
        }

        return dp[n-1][d];
    }
};