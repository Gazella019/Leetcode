



class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        
        int i, n;
        n = stoneValue.size();
        if(n == 1){
        	if(stoneValue[0] > 0)
        		return "Alice";
        	if(stoneValue[0] == 0)
        		return "Tie";
        	return "Bob";
        }
     	if(n == 2){
     		if(stoneValue[0] + stoneValue[1] > 0)
     			return "Alice";
     		if(stoneValue[0] > stoneValue[1])
     			return "Alice";
     		if(stoneValue[0] == stoneValue[1])
     			return "Tie";
     		return "Bob";
     	}
        vector<int> dp(n, 0);
        dp[n-1] = stoneValue[n-1];
        dp[n-2] = max(stoneValue[n-2]-dp[n-1], stoneValue[n-2]+stoneValue[n-1]);
        dp[n-3] = max(stoneValue[n-3]-dp[n-2], stoneValue[n-3]+stoneValue[n-2]-dp[n-1]);
        dp[n-3] = max(dp[n-3], stoneValue[n-3]+stoneValue[n-2]+stoneValue[n-1]);
        for(i=n-4;i>=0;i--){
        	dp[i] = max(stoneValue[i]-dp[i+1], stoneValue[i]+stoneValue[i+1]-dp[i+2]);
        	dp[i] = max(dp[i], stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-dp[i+3]);
        }

        for(int i=0;i<n;i++){
        	cout << dp[i] << " ";
        }

        if(dp[0] == 0)
        	return "Tie";
        if(dp[0] > 0)
        	return "Alice";
        return "Bob";
    }
};