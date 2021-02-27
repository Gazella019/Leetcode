


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
    	
    	vector<int> v(nums.size(), 0);
    	vector<vector<int>> res;
    	vector<int> used(nums.size(), 0);
    	sort(nums.begin(), nums.end());

    	dfs(res, nums, used, v, 0);
    	return res;
    }

    void dfs(vector<vector<int>>& res, vector<int>& nums, vector<int>& used, vector<int>& v, int n){

    	if(n == nums.size()){
    		res.push_back(v);
    		return;
    	}
    	for(int i=0;i<nums.size();i++){
    		if(used[i] == 1)
    			continue;
    		if(i > 0 && nums[i-1] == nums[i] && used[i-1] == 0){
    			continue;
    		}
    		v[n] = nums[i];
    		used[i] = 1; 
    		dfs(res, nums, used, v, n+1);
    		used[i] = 0;	
    	}
    }
};



class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
    	
    	vector<int> v(nums.size(), 0);
    	vector<vector<int>> res;
    	vector<int> used(nums.size(), 0);
    	//sort(nums.begin(), nums.end());

    	dfs(res, nums, used, v, 0);
    	return res;
    }

    void dfs(vector<vector<int>>& res, vector<int>& nums, vector<int>& used, vector<int>& v, int n){

    	if(n == nums.size()){
    		res.push_back(v);
    		return;
    	}
    	unordered_map<int, int> hash;
    	for(int i=0;i<nums.size();i++){
    		if(used[i] == 1 || hash.find(nums[i]) != hash.end())
    			continue;
    		hash[nums[i]] = 1;
    		v[n] = nums[i];
    		used[i] = 1; 
    		dfs(res, nums, used, v, n+1);
    		used[i] = 0;	
    	}
    }
};