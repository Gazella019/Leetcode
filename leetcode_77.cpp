

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> v;
        dfs(res, v, 1, n, k);
        return res;
    }

    void dfs(vector<vector<int>>& res, vector<int>& v, int val, int n, int k){
        if(v.size() == k){
            res.push_back(v);
            return;
        }
        for(int i=val;i<=n;i++){
            v.push_back(i);
            dfs(res, v, i+1, n, k);
            v.pop_back();
        }
    }
};




class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> v(k, 0);
        dfs(res, v, n, 1, 0);
        return res;
    }

    void dfs(vector<vector<int>>& res, vector<int>& v, int n, int val, int pos){
        if(pos == v.size()){
            res.push_back(v);
            return;
        }
        for(int i=val;i<=n;i++){
            v[pos] = i;
            dfs(res, v, n, i+1, pos+1);
        }
    }
};

// Runtime: 64 ms, faster than 89.46% of C++ 
// Memory Usage: 11.8 MB, less than 90.00% of C++


class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
    	vector<vector<int>> res;
    	vector<int> v(k, 0);
    	int i, count = 0;
    	dfs(res, v, 1, n, k, &count);
    	return res;
    }

    void dfs(vector<vector<int>>& res, vector<int>& v, int now, int n, int k, int* count){
    	if(*count == k){
    		res.push_back(v);
    		return;
    	}
    	for(int i=now;i<=n;i++){
    		//cout << "i " << i << " count " << *count << endl;
    		if(*count <= k-1){
    			v[*count] = i;
    			*count = *count + 1;
    			dfs(res, v, i+1, n, k, count);
    			*count = *count - 1;
    		}
    	}
    }
};