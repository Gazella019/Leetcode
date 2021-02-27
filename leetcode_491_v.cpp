


class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
    	vector<vector<int>> res;
    	
    	vector<int> v;

    	dfs(res, nums, v, 0, -101);

    	return res;
    }

    void dfs( vector<vector<int>> &res, vector<int>& nums, vector<int>& v, int n, int prev){
    	if(n == nums.size())
    		return;
    	unordered_map<int, int> hash;
    	for(int i=n;i<nums.size();i++){
    		if(nums[i] >= prev && hash.find(nums[i]) == hash.end()){
    			hash[nums[i]] = 1;
    			v.push_back(nums[i]);
    			if(v.size() >= 2)
    				res.push_back(v);
    			dfs(res, nums, v, i+1, nums[i]);
    			v.pop_back();
    		}
    	}
    }
};