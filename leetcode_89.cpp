


class Solution {
public:
    vector<int> grayCode(int n) {

    	int i, x = 1;
        vector<int> res;
        vector<int> vis(1<<n, 0);
        vector<int> v(n, 0);
        vector<int> table(n, 0);

        for(i=table.size()-1;i>=0;i--){
        	table[i] = x;
        	x = x * 2;
        }
        dfs(res, vis, v, table);
        return res;
    }

    void dfs(vector<int>& res, vector<int>& vis, vector<int>& v, vector<int>& table){
    	int num;
    	num = to_num(v, table);
    	if(vis[num] == 1)
    		return;
    	vis[num] = 1;
    	vector<int> temp;
    	res.push_back(num);
    	for(int i=v.size()-1;i>=0;i--){
    		temp = v;
    		if(v[i] == 0)
    			temp[i] = 1;
    		else if(v[i] == 1)
    			temp[i] = 0;
    		dfs(res, vis, temp, table);
    	}
    }

    int to_num(vector<int>& v, vector<int>& table){
    	int num = 0;
    	for(int i=0;i<v.size();i++){
    		num = num + v[i] * table[i];
    	}
    	return num;
    }

};