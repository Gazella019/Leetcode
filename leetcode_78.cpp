




// sol1 backtracking 
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    	vector<vector<int>> res;
    	vector<int> v;
    	traversal(res, nums, v, 0);
    	return res;
    }

    void traversal(vector<vector<int>>& res, vector<int>& nums, vector<int>& v, int n){
    	res.push_back(v);
        for(int i=n;i<nums.size();i++){
            v.push_back(nums[i]);
            traversal(res, nums, v, i+1);
            v.pop_back();
        }
    	
    }
};


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> v;
        traversal(res, nums, v, 0);
        return res;
    }

    void traversal(vector<vector<int>>& res, vector<int>& nums, vector<int> temp, int n){
        
        if(n == nums.size()){
            res.push_back(temp);
            return;
        }
        int i;
        traversal(res, nums, temp, n+1);
        temp.push_back(nums[n]);
        traversal(res, nums, temp, n+1);
        temp.pop_back();
    }
};



// sol2 iterative

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    	vector<vector<int>> res;
    	vector<int> v;
    	res.push_back(v);
    	int i, j, size;
    	for(i=0;i<nums.size();i++){
    		size = res.size();
    		for(j=0;j<size;j++){
    			cout << i << j << endl;
    			v = res[j];
    			v.push_back(nums[i]);
    			res.push_back(v);
    		}
    	}
    	return res;
    }
};


