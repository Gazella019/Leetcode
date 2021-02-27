



// BFS version
class Solution {
public:

	
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
    	
    	int cur, size;
    	queue<int> q;
    	vector<vector<int>> graph(numCourses);
    	vector<int> inDegree(numCourses, 0);
    	vector<int> res;

    	for(int i=0;i<prerequisites.size();i++){
    		graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
    		inDegree[prerequisites[i][0]] += 1;
    	}

    	for(int i=0;i<numCourses;i++){
    		if(inDegree[i] == 0){
    			q.push(i);
    			res.push_back(i);
    		}
    	}

    	while(q.size() != 0){
    		size = q.size();

    		for(int i=1;i<=size;i++){
    			cur = q.front();
    			q.pop();
    			for(int j=0;j<graph[cur].size();j++){
    				inDegree[graph[cur][j]] --;
    				if(inDegree[graph[cur][j]] == 0){
    					q.push(graph[cur][j]);
    					res.push_back(graph[cur][j]);
    				}
    			}
    		}
    	}

    	for(int i=0;i<numCourses;i++){
    		if(inDegree[i] != 0)
    			return {};
    	}

    	return res;
    }

};


// DFS version

class Solution {
public:

	bool hasCycle = false;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
    	vector<vector<int>> graph(numCourses);
    	vector<int> vis(numCourses, 0);
    	vector<int> res;
    	stack<int> st;

    	for(int i=0;i<prerequisites.size();i++){
    		graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
    	}

    	for(int i=0;i<numCourses;i++){
    		if(vis[i] == 0){
    			dfs(graph, vis, st, i);
    			if(hasCycle == true)
    				return {};
    		}
    	}

    	while(st.size() > 0){
    		res.push_back(st.top());
    		st.pop();
    	}

    	return res;
    }

    void dfs(vector<vector<int>>& graph, vector<int>& vis, stack<int>& st, int n){

    	vis[n] = 1;
    	for(int i=0;i<graph[n].size();i++){
    		if(vis[graph[n][i]] == 1){
    			hasCycle = true;
    			return;
    		}
    		if(vis[graph[n][i]] == 2)
    			continue;
    		dfs(graph, vis, st, graph[n][i]);
    	}
    	vis[n] = 2;
    	st.push(n);
    }
};