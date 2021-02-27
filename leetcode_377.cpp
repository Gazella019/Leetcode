

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
    	
    	int res;
    	vector<int> dp(target+1, -1);
    	dp[0] = 1;
    	res = backtrack(dp, nums, target);

    	return res;
    }
    int backtrack(vector<int>& dp, vector<int> nums, int n){
    	if(dp[n] != -1)
    		return dp[n];
    	dp[n] = 0;
    	for(int i=0;i<nums.size();i++){
    		if(n-nums[i] >= 0){
    			dp[n] = dp[n] + backtrack(dp, nums, n-nums[i]);
    		}
    	}
    	return dp[n];
    }.
    
};

// can be solved by backtracking
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
    	
    	int i, j;
    	vector<int> dp(target+1, 0);
    	dp[0] = 1;

    	for(i=1;i<=target;i++){
    		for(j=0;j<nums.size();j++){
    			if(i-nums[j] >= 0){
    				dp[i] = dp[i] + dp[i-nums[j]];
    			}
    		}
    	}
    	for(i=1;i<dp.size();i++){
    		cout << dp[i] << " ";
    	}
    	return dp[target];   
    }
};