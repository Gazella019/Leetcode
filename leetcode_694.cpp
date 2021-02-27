
class Solution {
public:

    int numDistinctIslands(vector<vector<int>>& grid) {
        
        int i, j, k, m, n, res = 0;
        bool diff;
        m = grid.size(), n = grid[0].size();

        vector<vector<int>> shape;

    	for(i=0;i<m;i++){
    		for(j=0;j<n;j++){
    			if(grid[i][j] == 1){
    				diff = true;
    				vector<int> v;
    				dfs(grid, v, i, j, 0);
    				for(k=0;k<shape.size();k++){
    					if(v == shape[k])
    						diff = false;
    				}
    				if(diff){
    					shape.push_back(v);
    					res ++;
    				}
    			}
    		}
    	}
    	return res;
    }	


    void dfs(vector<vector<int>>& grid, vector<int>& v, int row, int col, int dir){

    	if(isValid(grid, row, col) == false || grid[row][col] == 0){
    		v.push_back(-1);
    		return;
    	}
    	v.push_back(dir);
    	grid[row][col] = 0;
    	dfs(grid, v, row+1, col, 1);
    	dfs(grid, v, row-1, col, 2);
    	dfs(grid, v, row, col-1, 3);
    	dfs(grid, v, row, col+1, 4);

    }

    bool isValid(vector<vector<int>>& grid, int row, int col){
    	if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size())
    		return false;
    	return true;
    }

};


// Boundary doesnt add number, some case will wrong

class Solution {
public:

    int numDistinctIslands(vector<vector<int>>& grid) {
        
        int i, j, k, m, n, res = 0;
        bool diff;
        m = grid.size(), n = grid[0].size();

        vector<vector<vector<int>>> table((m*n)+1);

    	for(i=0;i<m;i++){
    		for(j=0;j<n;j++){
    			if(grid[i][j] == 1){
    				diff = true;
    				vector<int> v;
    				dfs(grid, v, i, j, 0);
    				for(k=0;k<table[v.size()].size();k++){
    					if(v == table[v.size()][k]){
    						diff = false;
    						break;
    					}
    				}
    				if(diff){
    					table[v.size()].push_back(v);
    					res ++;
    				}
    				//print(grid);
    			}
    		}
    	}
    	return res;
    }	


    void dfs(vector<vector<int>>& grid, vector<int>& v, int row, int col, int dir){

    	if(isValid(grid, row, col) == false || grid[row][col] == 0)
    		return;
    	v.push_back(dir);
    	grid[row][col] = 0;
    	dfs(grid, v, row+1, col, 1);
    	dfs(grid, v, row, col-1, 3);
    	dfs(grid, v, row, col+1, 2);
    	dfs(grid, v, row-1, col, 4);

    }

    bool isValid(vector<vector<int>>& grid, int row, int col){
    	if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size())
    		return false;
    	return true;
    }

    void print(vector<vector<int>>& grid){
    	cout << "Grid" << endl;
    	for(int i=0;i<grid.size();i++){
    		for(int j=0;j<grid[0].size();j++){
    			cout << grid[i][j] << " ";
    		}
    		cout << endl;
    	}
    }
};


