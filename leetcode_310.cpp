



class Solution {
public:
	int maxLevel = 0;
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(edges.size() == 0)
        	return {0};
        int i, j, size, cur;
        queue<int> q;
        vector<unordered_set<int>> graph(n);
        vector<int> res;

        for(i=0;i<edges.size();i++){
        	graph[edges[i][0]].insert(edges[i][1]);
        	graph[edges[i][1]].insert(edges[i][0]);
        }
        for(i=0;i<graph.size();i++){
        	if(graph[i].size() == 1){
        		q.push(i);
        	}
        }
        while(n > 2){
        	size = q.size();
        	n -= size;
        	for(i=1;i<=size;i++){
        		cur = q.front(), q.pop();
        		for(auto g:graph[cur]){
        			graph[g].erase(cur);
        			if(graph[g].size() == 1)
        				q.push(g);
        		}
        	}
        }
        while(q.size() != 0){
        	res.push_back(q.front());
        	q.pop();
        }
        return res;
    }
};