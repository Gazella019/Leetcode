



class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {

    	if(nums.size() <= 2)
    		return true;
    	// index 0 is 1, index 1 is 2
    	int l, i, n, end, sw;

        vector<vector<vector<int>>> dp(nums.size(), vector<vector<int>>(nums.size(), vector<int>(2, 0)));

        n = nums.size();
        if((n % 2) == 1)
        	sw = 0;
        else
        	sw = 1;

        for(i=0;i<n;i++){
        	dp[i][i][sw] = nums[i];
        }
        sw = (!sw);
        for(l=2;l<=n;l++){
        	for(i=0;i+l-1<n;i++){
        		end = i+l-1;
        		if(nums[i] + dp[i+1][end][sw] > nums[end] + dp[i][end-1][sw]){
        			dp[i][end][sw] = nums[i] + dp[i+1][end][sw];
        			dp[i][end][!sw] = dp[i+1][end][!sw];
        		}
        		else{
        			dp[i][end][sw] = nums[end] + dp[i][end-1][sw];
        			dp[i][end][!sw] = dp[i][end-1][!sw];
        		}
        	}
        	sw = (!sw);
        }
        
        if(dp[0][n-1][0] >= dp[0][n-1][1])
        	return true;
        return false;
    }
};


class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {

    	if(nums.size() <= 2)
    		return true;
    	// index 0 is 1, index 1 is 2
    	int l, i, n, end, sw;

    	vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));

    	for(i=0;i<nums.size();i++){
    		dp[i][i] = nums[i];
    	}


       	for(l=2;l<=nums.size();l++){
       		for(i=0;i+l-1<nums.size();i++){
       			end = i+l-1;
       			dp[i][end] = max(nums[i] - dp[i+1][end], nums[end] - dp[i][end-1]);
       		}
       	}
       	if(dp[0][nums.size()-1] >= 0)
       		return true;
       	return false;
    }
};