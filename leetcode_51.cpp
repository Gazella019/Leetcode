

// Runtime: 4 ms, faster than 97.30% of C++
// Memory Usage: 9.9 MB, less than 100.00% of C++ 

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
    	vector<vector<string>> res;
    	vector<string> board(n, string (n, '.'));
    	dfs(res, board, 0);
    	return res;
    }	

    void dfs(vector<vector<string>>& res, vector<string>& board, int row){
    	
    	if(row >= board.size()){
    		res.push_back(board);
    		return;
    	}

    	for(int i=0;i<board.size();i++){
    		if(isValid(board, row, i)){
    			board[row][i] = 'Q';
    			dfs(res, board, row+1);
    			board[row][i] = '.';
    		}
    	}
    }

    bool isValid(vector<string> &board, int row, int col){
    	int i, offset = 1;
    	for(i=row-1;i>=0;i--){
    		if(board[i][col] == 'Q')
    			return false;
    		if(col+offset < board.size()){
    			if(board[i][col+offset] == 'Q')
    				return false;
    		}
    		if(col-offset >= 0){
    			if(board[i][col-offset] == 'Q')
    				return false;
    		}
    		offset++;
    	}
    	return true;
    }
};