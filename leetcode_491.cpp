


class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
    	    vector<vector<int>> res;
    	    if(nums.size() == 0)
    	    	return res;
    	    vector<int> v(2, 0);
    	    int i, j, k, start;
    	    bool isSame;

    	    for(start=0;start<nums.size()-1;start++){
    	    	v[0] = nums[start];
	    	    for(i=start+1;i<nums.size();i++){
	    	    	if(nums[i] >= nums[start]){
	    	    		v[1] = nums[i];
	    	    		isSame = false;
	    	    		for(k=res.size()-1;k>=0;k--){
	    	    			if(res[k] == v){
	    	    				isSame = true;
	    	    				break;
	    	    			}
	    	    		}
	    	    		if(isSame == false){
	    	    			res.push_back(v);
	    	    			dfs(res, v, nums, i);
	    	    		}
	    	    	}
	    	    }
    		}
    		return res;
    }

    void dfs(vector<vector<int>>& res, vector<int> v, vector<int>& nums, int n){
    	vector<int> p;
    	unordered_set<int> hash;
    	for(int i=n+1;i<nums.size();i++){
    		if(nums[i] >= v[v.size()-1] && hash.count(nums[i]) == 0){
    			p = v;
    			p.push_back(nums[i]);
    			hash.insert(nums[i]);
    			res.push_back(p);   			
    			dfs(res, p, nums, i);
    		}
    	}
    }
};


class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> out;
        helper(nums, 0, out, res);
        return res;
    }
    void helper(vector<int>& nums, int start, vector<int>& out, vector<vector<int>>& res) {
        if (out.size() >= 2) 
        	res.push_back(out);
        unordered_set<int> st;
        for (int i = start; i < nums.size(); ++i) {
            if ((!out.empty() && out.back() > nums[i]) || st.count(nums[i])) 
            	continue;
            out.push_back(nums[i]);
            st.insert(nums[i]);
            helper(nums, i + 1, out, res);
            out.pop_back();
        }
    }
};




class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
    	    vector<vector<int>> res;
    	    if(nums.size() == 0)
    	    	return res;
    	    vector<int> v(2, 0);
    	    int i, j, k, start;
    	    bool isSame;

    	    for(start=0;start<nums.size()-1;start++){
    	    	v[0] = nums[start];
	    	    for(i=start+1;i<nums.size();i++){
	    	    	if(nums[i] >= nums[start]){
	    	    		v[1] = nums[i];
	    	    		isSame = false;
	    	    		for(k=res.size()-1;k>=0;k--){
	    	    			if(res[k] == v){
	    	    				isSame = true;
	    	    				break;
	    	    			}
	    	    		}
	    	    		if(isSame == false){
	    	    			res.push_back(v);
	    	    			dfs(res, v, nums, i);
	    	    		}
	    	    	}
	    	    }
    		}
    		return res;
    }

    void dfs(vector<vector<int>>& res, vector<int> v, vector<int>& nums, int n){
    	bool isSame;
    	vector<int> p;
    	for(int i=n+1;i<nums.size();i++){
    		if(nums[i] >= v[v.size()-1]){
    			p = v;
    			p.push_back(nums[i]);
    			isSame = false;
    			if(nums[i] == nums[i-1]){
    				for(int k=res.size()-1;k>=0;k--){
    					if(res[k] == p){
    						isSame = true;
    						break;
    					}
    				}
    			}
    			if(isSame == false){
    				res.push_back(p);   			
    				dfs(res, p, nums, i);
    			}
    		}
    	}
    }
};

