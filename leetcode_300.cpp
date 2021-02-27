



class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        if(nums.size() == 0)
        	return 0;
    	int i, j, res = 1;
    	vector<int> dp(nums.size(), 1);
    	for(i=1;i<nums.size();i++){
    		for(j=i-1;j>=0;j--){
    			if(nums[i] > nums[j]){
    				dp[i] = max(dp[i], dp[j]+1);
    			}
    		}
    		res = max(res, dp[i]);
    	}

    	return res;
    }
};