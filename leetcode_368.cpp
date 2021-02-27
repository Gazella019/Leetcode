


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
		
		if(nums.size() == 0)
			return {};
		int i, j, mx = 1, size;
		vector<vector<int>> dp(nums.size());
		vector<int> res;
		sort(nums.begin(), nums.end());

		for(i=0;i<nums.size();i++){
			for(j=i-1;j>=0;j--){
				if(nums[i]%nums[j] == 0 && dp[j].size() > dp[i].size()){
					dp[i] = dp[j];
				}
			}
			dp[i].push_back(nums[i]);
			size = dp[i].size();
			mx = max(mx, size);
		}

		for(i=0;i<dp.size();i++){
			if(dp[i].size() == mx)
				return dp[i];
		}
		
		return res;
    }
};



class Solution {
public:
	vector<int> res;
    vector<int> largestDivisibleSubset(vector<int>& nums) {
	
		vector<int> v;  
		vector<int> vis(nums.size(), 0);      
        sort(nums.begin(), nums.end());
        dfs(nums, v, 1, 0);
        return res;
    }

    void dfs(vector<int>& nums, vector<int>& v, vector<int>& vis, int prev, int n){
    	if(n == nums.size()){
    		if(v.size() > res.size())
    			res = v;
    		return;
    	}
    	for(int i=n;i<nums.size();i++){
    		if(nums[i]%prev == 0){
    			v.push_back(nums[i]);
    			dfs(nums, v, nums[i], i+1);
    			v.pop_back();
    		}
    		else{
    			dfs(nums, v, prev, i+1);
    		}
    	}
    }

};