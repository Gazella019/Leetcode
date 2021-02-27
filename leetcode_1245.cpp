


class Solution {
public:
	int res = 0;
    int treeDiameter(vector<vector<int>>& edges) {
        
    	int i;
        vector<vector<int>> graph(edges.size()+1);
        vector<int> vis(edges.size()+1, 0);

        for(i=0;i<edges.size();i++){
        	graph[edges[i][0]].push_back(edges[i][1]);
        	graph[edges[i][1]].push_back(edges[i][0]);
        }

        i = length(graph, vis, 0);
        return res;
    }

    int length(vector<vector<int>>& graph, vector<int>& vis, int n){
    	
    	if(vis[n] == 1)
    		return 0;
    	int i, mx1 = 0, mx2 = 0, l;
    	vis[n] = 1;
    	for(i=0;i<graph[n].size();i++){
    		l = length(graph, vis, graph[n][i]);
    		if(l > mx1){
    			mx2 = mx1;
    			mx1 = l;
    		}
    		else if(l > mx2)
    			mx2 = l;
    	}
    	cout << "n:" << n << " mx1:" << mx1 << " mx2:" << mx2 << endl;
    	res = max(res, mx1+mx2);
    	return mx1 + 1;
    }
};