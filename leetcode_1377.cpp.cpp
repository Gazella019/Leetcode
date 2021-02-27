



class Solution {
public:

	double res = 0;
	bool isFound = false;
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
    	
    	int i, j, cnt, size, cur, time = 0;
    	vector<vector<int>> graph(n+1);
    	vector<int> vis(n+1, 0);

    	for(i=0;i<edges.size();i++){
    		graph[edges[i][0]].push_back(edges[i][1]);
    		graph[edges[i][1]].push_back(edges[i][0]);
    	}

    	dfs(graph, vis, 1, 1, 0, t, target);
    	return res;
    }

    void dfs(vector<vector<int>>& graph, vector<int>& vis, double prob, int n, int time, int t, int target){

    	if(time > t || isFound == true)
    		return;

    	int i, nums = 0;
    	for(i=0;i<graph[n].size();i++){
    		if(vis[graph[n][i]] == 0)
    			nums ++;
    	}
    	if(n == target){
    		isFound = true;
    		if(time == t || nums == 0)
    			res = prob;
    		return;
    	}
    	vis[n] = 1;
    	for(i=0;i<graph[n].size();i++){
    		if(vis[graph[n][i]] == 0){
    			dfs(graph, vis, prob/nums, graph[n][i], time+1, t, target);
    		}
    	}
    }

};