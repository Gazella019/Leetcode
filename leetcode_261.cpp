


class Solution {
public:

	bool hasCycle = false;

    bool validTree(int n, vector<vector<int>>& edges) {

        vector<vector<int>> graph(n);
        vector<int> visited(n, 0);
        int i;
        for(i=0;i<edges.size();i++){
        	graph[edges[i][0]].push_back(edges[i][1]);
        	graph[edges[i][1]].push_back(edges[i][0]);
        }

        dfs(graph, visited, 0, 0);

        if(hasCycle)
        	return false;
        for(i=0;i<visited.size();i++){
        	if(visited[i] == 0)
        		return false;
        }
        return true;
    }

    void dfs(vector<vector<int>>& graph, vector<int>& visited, int n, int pre){
    	
    	visited[n] = 1;
    	for(int i=0;i<graph[n].size();i++){
    		if(visited[graph[n][i]] == 0){
    			dfs(graph, visited, graph[n][i], n);
    		}
    		else if(visited[graph[n][i]] == 1 && graph[n][i] != pre){
    			hasCycle = true;
    			return;
    		}
    	}
    	return;
    }
};