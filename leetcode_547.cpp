


// Runtime: 16 ms, faster than 97.13% of C++ 
// Memory Usage: 10.7 MB, less than 100.00% of C++
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
    	if(M.size() == 0)
    		return 0;
        int i, count = 0;
        vector<int> visited(M.size(), 0);
        for(i=0;i<visited.size();i++){
        	if(visited[i] == 0){
        		visited[i] = 1;
        		DFS(M, visited, i);
        		count ++;
        	}
        }
    	return count;
    }

    void DFS(vector<vector<int>>& M, vector<int>& visited, int n){
    	for(int i=0;i<M.size();i++){
    		if(M[n][i] == 1 && visited[i] == 0){
    			visited[i] = 1;
    			DFS(M, visited, i);
    		}
    	}
    }
};