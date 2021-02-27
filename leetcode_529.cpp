



class Solution {
public:
	vector<vector<int>> direction = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int row, col;
        row = click[0], col = click[1];
        if(board[row][col] == 'M'){
        	board[row][col] = 'X';
        	return board;
        }
        vector<vector<int>> vis(board.size(), vector<int>(board[0].size(), 0));

        dfs(board, vis, row, col);

        return board;
    }

    void dfs(vector<vector<char>>& board, vector<vector<int>>& vis, int row, int col){
    	
    	int val;
    	if(isValid(board, row, col) == false || vis[row][col] == 1)
    		return;
    	vis[row][col] = 1;
    	if(board[row][col] == 'E'){
    		val = cal(board, row, col);
    		if(val == 0){
    			board[row][col] = 'B';
    			for(int i=0;i<direction.size();i++){
    				dfs(board, vis, row + direction[i][0], col + direction[i][1]);
    			}
    		}
    		else{
    			board[row][col] = (val+'0');
    		}
    	}

    }

	int cal(vector<vector<char>>& board, int row, int col){
		int r, c, cnt = 0;
		for(int i=0;i<direction.size();i++){
			r = row + direction[i][0], c= col + direction[i][1];
			if(isValid(board, r, c) && board[r][c] == 'M')
				cnt ++;
		}
		return cnt;
	}

	bool isValid(vector<vector<char>>& board, int row, int col){
		if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size())
    		return false;
    	return true;
	}
};