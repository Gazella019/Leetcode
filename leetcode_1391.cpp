




class Solution {
public:
	// up 1, down 2, left 3, right 4;
	bool find = false;
	vector<vector<vector<int>>> dir;
	

    bool hasValidPath(vector<vector<int>>& grid) {
    	if(grid.size() == 1 && grid[0].size() == 1)
    		return true;
    	dir.push_back({{-1, -1}, {-1, -1}});
        dir.push_back({{0, -1}, {0, 1}});
		dir.push_back({{1, 0}, {-1, 0}});
		dir.push_back({{0, -1}, {1, 0}});
		dir.push_back({{0, 1}, {1, 0}});
		dir.push_back({{0, -1}, {-1, 0}});
		dir.push_back({{0, 1}, {-1, 0}});
        int type = grid[0][0];
        dfs(grid, 0, 0, 0, 0);

    	return find;
    }

    void dfs(vector<vector<int>>& grid, int row, int col, int pr, int pc){
    	if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || find == true)
    		return;
    	int type = grid[row][col], nextDir;
    	bool canReturn = false;
    	if(row == 0 && col == 0){
    		dfs(grid, row+dir[type][0][0], col+dir[type][0][1], row, col);
    		dfs(grid, row+dir[type][1][0], col+dir[type][1][1], row, col);
    		return;
    	}
    	if(row+dir[type][0][0] == pr && col+dir[type][0][1] == pc){
    		nextDir = 1;
    		canReturn = true;
    	}
    	else if(row+dir[type][1][0] == pr && col+dir[type][1][1] == pc){
    		nextDir = 0;
    		canReturn = true;
    	}
    	if(row == grid.size()-1 && col == grid[0].size()-1 && canReturn){
    		find = true;
    		return;
    	}
    	if(canReturn == true){
    		dfs(grid, row+dir[type][nextDir][0], col+dir[type][nextDir][1], row, col);
    	}
    	
    }
};