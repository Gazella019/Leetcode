




class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> v;
        sort(nums.begin(), nums.end());
        traversal(res, nums, v, 0);
        return res;
    }

    void traversal(vector<vector<int>>& res, vector<int>& nums, vector<int> v, int n){
        
        res.push_back(v);
        unordered_map<int,int> hash;
        for(int i=n;i<nums.size();i++){
            if(hash.find(nums[i]) == hash.end()){
                hash[nums[i]] = 1;
                v.push_back(nums[i]);
                traversal(res, nums, v, i+1);
                v.pop_back();
            }
        }

    }
};


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> v;
        sort(nums.begin(), nums.end());
        traversal(res, nums, v, 0);
        return res;
    }

    void traversal(vector<vector<int>>& res, vector<int>& nums, vector<int> v, int n){
    	res.push_back(v);
    	int i;
    	for(i=n;i<nums.size();i++){
    		if(i != n && nums[i-1] == nums[i])
    			continue;
    		v.push_back(nums[i]);
    		traversal(res, nums, v, i+1);
    		v.pop_back();
    	}

    }
};

