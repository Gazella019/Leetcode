



class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        
        int res = 0;
        vector<vector<int>> graph(n);
        vector<int> vis(n, 0);
        for(int i=0;i<edges.size();i++){
        	graph[edges[i][0]].push_back(edges[i][1]);
        	graph[edges[i][1]].push_back(edges[i][0]);
        }

        for(int i=0;i<n;i++){
        	if(vis[i] == 0){
        		res ++;
        		dfs(graph, vis, i);
        	}
        }

        return res;
    }

    void dfs(vector<vector<int>>& graph, vector<int>& vis, int n){
    	if(vis[n] == 1)
    		return;
    	vis[n] = 1;
    	for(int i=0;i<graph[n].size();i++){
    		dfs(graph, vis, graph[n][i]);
    	}
    }
};