




class Solution {
public:

	int time = 0;
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>> graph(n);
        vector<vector<int>> res;
        vector<int> vis(n, 0);
        vector<int> low(n, 0);
        for(int i=0;i<connections.size();i++){
        	graph[connections[i][0]].push_back(connections[i][1]);
        	graph[connections[i][1]].push_back(connections[i][0]);
        }

        for(int i=0;i<n;i++){
        	if(vis[i] != 0)
        		continue;
        	dfs(graph, res, vis, low, i, -1);
        }

        return res;
    }


    void dfs(vector<vector<int>>& graph, vector<vector<int>>& res, vector<int>& vis, vector<int>& low, int n, int parent){
    	time ++;
    	vis[n] = time, low[n] = time;
    	for(int i=0;i<graph[n].size();i++){
    		if(graph[n][i] == parent)
    			continue;
    		if(vis[graph[n][i]] != 0){
    			low[n] = min(low[n], vis[graph[n][i]]); 
    		}
    		else{
    			dfs(graph, res, vis, low, graph[n][i], n);
    			low[n] = min(low[n], low[graph[n][i]]);
    			if(vis[n] < low[graph[n][i]])
    				res.push_back({n, graph[n][i]});
    		}
    	}
    }
};