


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<int>> graph(N, vector<int> (N, -1));
        vector<int> table(N, INT_MAX);
        vector<int> color(N, 1);
        // 1: white, 2: gray
        int i, cost = 0, res = 0;
        // Build table with weight
        for(i=0;i<times.size();i++){
        	graph[times[i][0]-1][times[i][1]-1] = times[i][2];
        }

        dfs(graph, table, color, K-1, cost);

        for(i=0;i<N;i++){
        	if(i != K-1){
        		if(table[i] == INT_MAX)
        			return -1;
        		res = max(res, table[i]);
        	}
        }
   		return res;
    }

    void dfs(vector<vector<int>>& graph, vector<int>& table, vector<int>& color, int n, int cost){
    	for(int i=0;i<graph.size();i++){
    		//if(graph[n][i] != 0)	!! 乾 !!
    		if(graph[n][i] != -1 && color[i] != 2){
	    		if(cost+graph[n][i] < table[i]){
	    			color[i] = 2;
	    			table[i] = cost+graph[n][i];
	    			dfs(graph, table, color, i, cost+graph[n][i]);
	    			color[i] = 1;
	    		}
    		}
    	}
    }
};

// DFS sol
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<int>> graph(N, vector<int> (N, 0));
        vector<int> visited(N, 0);
        visited[K-1] = 1;
        int i, cost = 0, max = 0;
        for(i=0;i<times.size();i++){
        	graph[times[i][0]-1][times[i][1]-1] = times[i][2];
        }
        dfs(graph, visited, K-1, cost, &max);
        for(i=0;i<N;i++){
        	if(visited[i] == 0)
        		return -1;
        }
   		return max;
    }

    void dfs(vector<vector<int>>& graph, vector<int>& visited, int n, int cost, int* max){
    	if(cost > *max)
    		*max = cost;
    	for(int i=0;i<graph.size();i++){
    		if(visited[i] == 0 && graph[n][i] != 0){
    			visited[i] = 1;
    			dfs(graph, visited, i, cost+graph[n][i], max);
    		}
    	}
    }

    void print(vector<vector<int>>& graph){
    	for(int i=0;i<graph.size();i++){
    		for(int j=0;j<graph[0].size();j++){
    			cout << graph[i][j] << " ";
    		}
    		cout << endl;
    	}
    }
};



/*
void dfs(vector<vector<int>>& graph, vector<int>& visited, int n, int cost, int* max){
    	cout << "node " << n+1 << " cost" << cost << endl;
    	for(int i=0;i<graph.size();i++){
    		if(visited[i] == 0 && graph[n][i] != 0){
    			visited[i] = 1;
    			cost = cost + graph[n][i];
    			if(cost > *max)
    				*max = cost;
    			dfs(graph, visited, i, cost, max);
    		}
    	}
    }
*/

