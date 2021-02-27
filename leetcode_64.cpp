


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
    	vector<vector<int>> table;
    	int i, j, m, n;
    	m = grid.size();
    	n = grid[0].size();

    	for(i=1;i<=m;i++){
    		vector<int> v(n,0);
    		table.push_back(v);
    	}

    	table[0][0] = grid[0][0];

    	for(i=1;i<m;i++){
    		table[i][0] = grid[i][0] + table[i-1][0];
    	}
    	for(i=1;i<n;i++){
    		table[0][i] = grid[0][i] + table[0][i-1];
    	}

    	for(i=1;i<m;i++){
    		for(j=1;j<n;j++){
    			if(table[i-1][j] < table[i][j-1])
    				table[i][j] = table[i-1][j] + grid[i][j];
    			else
    				table[i][j] = table[i][j-1] + grid[i][j];
    		}
    	}    

    	return table[m-1][n-1]; 
    }
};