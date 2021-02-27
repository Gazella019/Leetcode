



class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {

    	if(costs.size() == 0 || costs[0].size() == 0)
        	return 0;
        
        int i, j, n, k, x, res;
        n = costs.size();
        k = costs[0].size();
        int dp[n][k];

        for(i=0;i<k;i++){
        	dp[0][i] = costs[0][i];
        }

        for(i=1;i<n;i++){
        	for(j=0;j<k;j++){
        		dp[i][j] = INT_MAX;
        		for(x=0;x<k;x++){
        			if(x != j){
        				dp[i][j] = min(dp[i][j], dp[i-1][x]+costs[i][j]);
        			}
        		}
        	}
        }
        res = INT_MAX;
        for(i=0;i<k;i++){
        	res = min(res, dp[n-1][i]);
        }

        return res;
    }
};