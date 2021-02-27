




class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int i, j, m, n;
        if(obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0)
        	return 0;
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        long table[m][n] = {0};

        if(obstacleGrid[0][0] == 1)
        	return 0;
        table[0][0] = 1;

        for(i=1;i<n;i++){

        	if(obstacleGrid[0][i] == 0)
        		table[0][i] = table[0][i-1];
        	else
        		table[0][i] = 0;
        }

        for(i=1;i<m;i++){

        	if(obstacleGrid[i][0] == 0)
        		table[i][0] = table[i-1][0];
        	else
        		table[i][0] = 0;
        }

        for(i=1;i<m;i++){
        	for(j=1;j<n;j++){
        		if(obstacleGrid[i][j] == 1)
        			table[i][j] = 0;
        		else
        			table[i][j] = table[i-1][j] + table[i][j-1];
        	}
        }

        for(i=0;i<m;i++){
        	for(j=0;j<n;j++){
        		cout << table[i][j] << " ";
        	}
        	cout << endl;
        }

        return table[m-1][n-1];
    }
};