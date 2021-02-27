



class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int row, col, size, m, n, cnt = 0, res = 0;
        m = grid.size(), n = grid[0].size();
        vector<int> dir = {1, 0, -1, 0, 1};
        queue<int> r;
        queue<int> c;

        for(int i=0;i<m;i++){
        	for(int j=0;j<n;j++){
        		if(grid[i][j] == 2){
        			r.push(i), c.push(j);
        		}
        		else if(grid[i][j] == 1)
        			cnt ++;
        	}
        }	
        if(cnt == 0)
        	return 0;
        while(r.size() > 0){
        	res ++;
        	size = r.size();
        	for(int i=1;i<=size;i++){
        		row = r.front(), r.pop();
        		col = c.front(), c.pop();
        		for(int j=0;j<4;j++){
        			if(row+dir[j] < 0 || col+dir[j+1] < 0 || row+dir[j] >= m || col+dir[j+1] >= n)
        				continue;
        			if(grid[row+dir[j]][col+dir[j+1]] == 1){
        				cnt --;
        				grid[row+dir[j]][col+dir[j+1]] = 2;
        				r.push(row+dir[j]), c.push(col+dir[j+1]); 
        			}
        		}
        	}
        }

        if(cnt >= 1)
        	return -1;
        return res-1;
    }
};