


class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        
        if(costs.size() == 0 || costs[0].size() == 0)
        	return 0;
        int i, j, k, res = INT_MAX;
       	vector<vector<int>> dp(costs.size(), vector<int>(3, INT_MAX));

       	for(i=0;i<3;i++){
       		dp[0][i] = costs[0][i];
       	}

       	for(i=1;i<costs.size();i++){
       		for(j=0;j<3;j++){
       			for(k=0;k<3;k++){
       				if(j != k){
       					dp[i][j] = min(dp[i][j], dp[i-1][k] + costs[i][j]);
       				}
       			}
       		}
       	}
       	
       	for(i=0;i<3;i++){
       		res = min(res, dp[costs.size()-1][i]);
       	}

       	for(i=0;i<costs.size();i++){
       		for(j=0;j<3;j++){
       			cout << dp[i][j] << " ";
       		}
       		cout << endl;
       	}

       	return res;
    }
};