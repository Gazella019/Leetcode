


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
    	vector<vector<int>> res;
    	vector<int> v(nums.size(), 0);
        vector<int> used(nums.size(), 0);
        vector<int> duplicate(nums.size(), 0);
        map<int, int> hash;
        for(int i=0;i<nums.size();i++){
        	if(hash.find(nums[i]) == hash.end())
        		hash[nums[i]] = 1;
        	else
        		duplicate[i] = 1;
        }
        permutation(res, nums, duplicate, v, used, 0);
        return res;
    }

    void permutation(vector<vector<int>>& res, vector<int>& nums, vector<int>& duplicate, vector<int>& v, vector<int>& used, int n){
    	if(n == nums.size()){
    		res.push_back(v);
    		return;
    	}
    	for(int i=0;i<nums.size();i++){
	    	if(used[i] == 0){
	    		used[i] = 1;
	    		v[n] = nums[i];
	    		permutation(res, nums, duplicate, v, used, n+1);
	    		used[i] = 0;
	    	}
    	}
    }
};



class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp(nums.size(), 0);
        vector<int> used(nums.size(), 0);
        traversal(res, nums, used, temp, 0);

        return res;
    }

    void traversal(vector<vector<int>>& res, vector<int>& nums, vector<int> used, vector<int> temp, int n){
        if(n == nums.size()){
            res.push_back(temp);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(used[i] == 0){
                temp[n] = nums[i];
                used[i] = 1;
                traversal(res, nums, used, temp, n+1);
                used[i] = 0;
            }
        }

    }
};