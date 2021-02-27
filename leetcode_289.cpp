




class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        int i, j, a, b, aliveNeighbors;
        int vertical[3] = {-1, 0, 1};
        int horizontal[3] = {-1, 0, 1};
        vector<vector<int>> res;
        for(i=0;i<m;i++){
            vector<int> v;
        	for(j=0;j<n;j++){
        		aliveNeighbors = 0;
        		for(a=0;a<3;a++){
        			for(b=0;b<3;b++){
        				if(a==1 && b==1)
        					continue;
        				else{
        					if(isValid(j+horizontal[a], i+vertical[b], m, n)){
                                if(board[i+vertical[b]][j+horizontal[a]] == 1)
                                    aliveNeighbors += 1;
        					}
    					}
        			}
        		}
                if(board[i][j] == 1){
                    if(aliveNeighbors < 2)
                        v.push_back(0);
                    else if(aliveNeighbors > 3)
                        v.push_back(0);
                    else
                        v.push_back(1);
                }
                else if(board[i][j] == 0){
                    if(aliveNeighbors == 3)
                        v.push_back(1);
                    else
                        v.push_back(0);
                }

        	}
            res.push_back(v);
        }

        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                board[i][j] = res[i][j];
            }
        }
    }

    bool isValid(int x, int y, int m, int n){

    	if(x < 0 || y < 0 || x >= n || y >= m)
    		return false;
    	return true;

    }
};