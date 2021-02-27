

// Runtime: 4 ms, faster than 61.48% of C++ 
// Memory Usage: 8.5 MB, less than 100.00% of C++

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> v(k, 0);
        int sum = 0;
        combination(res, v, k, 0, sum, n, 0);
        return res;
    }

    void combination(vector<vector<int>>& res, vector<int>& v, int k, int n, int sum, int target, int num){

    	if(n == k){
    		if(sum == target)
    			res.push_back(v);
    		return;
    	}
    	int i, temp = sum;
    	for(i=num+1;i<=9;i++){
    		temp = sum + i;
    		v[n] = i;
    		combination(res, v, k, n+1, temp, target, i);
    	}

    }
};