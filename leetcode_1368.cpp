


// BFS + DFS

class Solution {
public:

    int minCost(vector<vector<int>>& grid) {

    	int i, j, r, c, rx, cx, sz, cnt = 0;
    	queue<vector<int>> que;
    	vector<vector<int>> vis(grid.size(), vector<int> (grid[0].size(), -1));
    	vector<int> dir = {1, 0, -1, 0, 1};
    	vector<int> v;

    	dfs(vis, grid, que, 0, 0, 0);

    	while(que.size() != 0){
    		sz = que.size();
    		cnt ++;
    		for(i=1;i<=sz;i++){
    			v = que.front();
    			r = v[0], c = v[1];
    			for(j=0;j<4;j++){
    				rx = r+dir[j], cx = c+dir[j+1];
    				dfs(vis, grid, que, cnt, rx, cx);
    			}
    			que.pop();
    		}
    		
    	}

    	for(i=0;i<vis.size();i++){
    		for(j=0;j<vis[0].size();j++){
    			cout << vis[i][j] << " ";
    		}
    		cout << endl;
    	}
        
        return vis[grid.size()-1][grid[0].size()-1];
	}

	void dfs(vector<vector<int>>& vis, vector<vector<int>>& grid, queue<vector<int>>& que, int cnt, int r, int c){
		if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || vis[r][c] != -1)
			return;
		vis[r][c] = cnt;
		que.push({r, c});
		if(grid[r][c] == 1)
			dfs(vis, grid, que, cnt, r, c+1);
		if(grid[r][c] == 2)
			dfs(vis, grid, que, cnt, r, c-1);
		if(grid[r][c] == 3)
			dfs(vis, grid, que, cnt, r+1, c);
		if(grid[r][c] == 4)
			dfs(vis, grid, que, cnt, r-1, c);
	}

};






// TLE
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {

        vector<vector<int>> table(grid.size(), vector<int> (grid[0].size(), 10000));
        table[0][0] = 0;
        while(true){
        	vector<vector<int>> temp;
        	temp = table;
	        for(int i=0;i<grid.size();i++){
	        	for(int j=0;j<grid[0].size();j++){
	        		
	        		if(isValid(grid, i-1, j)){
	        			if(grid[i-1][j] == 3)
	        				table[i][j] = min(table[i][j], table[i-1][j]);
	        			else
	        				table[i][j] = min(table[i][j], table[i-1][j]+1);
	        		}	        		
	        		if(isValid(grid, i+1, j)){
	        			if(grid[i+1][j] == 4)
	        				table[i][j] = min(table[i][j], table[i+1][j]);
	        			else
	        				table[i][j] = min(table[i][j], table[i+1][j]+1);
	        		}	        		
	        		if(isValid(grid, i, j+1)){
	        			if(grid[i][j+1] == 2)
	        				table[i][j] = min(table[i][j], table[i][j+1]);
	        			else
	        				table[i][j] = min(table[i][j], table[i][j+1]+1);
	        		}
	        		if(isValid(grid, i, j-1)){
	        			if(grid[i][j-1] == 1)
	        				table[i][j] = min(table[i][j], table[i][j-1]);
	        			else
	        				table[i][j] = min(table[i][j], table[i][j-1]+1);
	        		}
	        	}
	        }
	        if(temp == table)
	        	break;
	    }

        return table[grid.size()-1][grid[0].size()-1];
	}

	bool isValid(vector<vector<int>>& grid, int row, int col){
		if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size())
			return false;
		return true;
	}

};