



class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        
        if(rooms.size() <= 0 || rooms[0].size() <= 0)
        	return;
        int m, n, size, row, col, rr, cc;
        vector<int> dir = {1, 0, -1, 0, 1};
    	queue<int> r;
    	queue<int> c;
    	m = rooms.size(), n = rooms[0].size();
    	for(int i=0;i<m;i++){
    		for(int j=0;j<n;j++){
    			if(rooms[i][j] == 0)
    				r.push(i), c.push(j);
    		}
    	}

    	while(r.size() > 0){
    		size = r.size();
    		for(int i=1;i<=size;i++){
    			row = r.front(), r.pop();
    			col = c.front(), c.pop();
    			for(int j=0;j<4;j++){
    				rr = row + dir[j];
    				cc = col + dir[j+1];
    				if(rr < 0 || cc < 0 || rr >= m || cc >= n || rooms[rr][cc] <= rooms[row][col] + 1)
    					continue;
    				rooms[rr][cc] = rooms[row][col] + 1;
    				r.push(rr), c.push(cc);
    			}
    		}
    	}
    }	
};