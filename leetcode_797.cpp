



class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> v(graph.size(), 0);
        v.push_back(0);
        dfs(graph, res, v, 0, 1);
        return res;
    }

    void dfs(vector<vector<int>>& graph, vector<vector<int>> &res, vector<int> v, int n, int level){
    	
    	if(n == graph.size()-1){
            v.assign(v.begin(), v.begin()+level);
    		res.push_back(v);
    		return;
    	}

    	for(int i=0;i<graph[n].size();i++){
    		v[level] = graph[n][i];
    		dfs(graph, res, v, graph[n][i], level+1);
    	}
    }
};