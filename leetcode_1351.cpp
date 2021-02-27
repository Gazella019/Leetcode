


class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        int res = 0, i, j;

        for(i=0;i<grid.size();i++){
        	for(j=0;j<grid[0].size();j++){
        		if(grid[i][j] < 0){
        			res = res + (grid[0].size()-j);
        			break;
        		}
        	}
        }

        return res;
    }
};