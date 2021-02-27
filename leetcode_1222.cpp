



class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        
        vector<vector<int>> res;
        vector<vector<int>> chessBoard(8, vector<int>(8, 0));

        for(int i=0;i<queens.size();i++){
        	chessBoard[queens[i][0]][queens[i][1]] = 1;
        }

        check(chessBoard, res, king[0], king[1], 0, 1);
        check(chessBoard, res, king[0], king[1], 0, -1);
        check(chessBoard, res, king[0], king[1], 1, 0);
        check(chessBoard, res, king[0], king[1], -1, 0);

        check(chessBoard, res, king[0], king[1], 1, 1);
        check(chessBoard, res, king[0], king[1], -1, -1);
        check(chessBoard, res, king[0], king[1], 1, -1);
        check(chessBoard, res, king[0], king[1], -1, 1);

        return res;
    }

    void check(vector<vector<int>>& chessBoard, vector<vector<int>>& res, int row, int col, int rx, int cx){
    	row += rx, col += cx;
    	while(isValid(row, col)){
    		if(chessBoard[row][col] == 1){
    			res.push_back({row, col});
    			break;
    		}
    		row += rx;
    		col += cx;
    	}
    }

    bool isValid(int row, int col){
    	if(row < 0 || col < 0 || row >= 8 || col >= 8)
    		return false;
    	return true;
    }
};