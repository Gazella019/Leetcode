



class Solution {
public:
    bool hasCycle = false;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int i;
        vector<vector<int>> graph(numCourses);
        vector<int> vis(numCourses, 0);

        for(i=0;i<prerequisites.size();i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for(i=0;i<numCourses;i++){
            if(vis[i] == 0){
                dfs(graph, vis, i);
                if(hasCycle)
                    return false;
            }
        }
        for(i=0;i<numCourses;i++){
            if(vis[i] == 0)
                return false;
        }
        return true;
    }

    void dfs(vector<vector<int>>& graph, vector<int>& vis, int n){

        vis[n] = 1;
        for(int i=0;i<graph[n].size();i++){
            if(vis[graph[n][i]] == 1){
                hasCycle = true;
                continue;
            }
            if(vis[graph[n][i]] == 2)
                continue;
            dfs(graph, vis, graph[n][i]);
        }
        vis[n] = 2;
    }
};