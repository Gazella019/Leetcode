



// 我搞錯題目的意思了
// 這個CASE是可以區分 invalid 的 以及  valid
// 實際上的test case 都只會有 valid 的
// 更新版會在version.1

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        
        // "1" vertical , "2"  horizontal ;
        int state, shipNum = 0;
        bool result = true;

        int i, j;
    	for(i=0;i<board.size();i++){
    		for(j=0;j<board[0].size();j++){
    			if(board[i][j] == 'X'){
    				if(hasShip(board, i+1, j) || hasShip(board, i-1, j)){
    					result = true;
    					vertical(board, i, j, &result);
    					if(result)
    						shipNum = shipNum + 1;

    				}
    				if(hasShip(board, i, j+1) || hasShip(board, i, j-1)){
    					horizontal(board, i, j, &result);
    					if(result)
    						shipNum = shipNum + 1;
    				}
    				else{
    					board[i][j] = '.';
    					shipNum = shipNum + 1;
    				}
    			}
    		}
    	}

        cout << "there is " << shipNum << " ship" << endl;
        showBoard(board);
        return 0;
    }

    void vertical(vector<vector<char>>& board, int x, int y, bool* isShip){

    	if(!isValid(board, x, y))
    		return;
    	if(board[x][y] != 'X')
    		return;
    	board[x][y] = '.';
    	vertical(board, x + 1, y, isShip);
    	vertical(board, x - 1, y, isShip);
    	if(hasShip(board, x, y+1)){
    		dfs(board, x, y+1);
    		*isShip = false;
    	}
    	if(hasShip(board, x, y-1)){
    		dfs(board, x, y-1);
    		*isShip = false;
    	}

    }

    void horizontal(vector<vector<char>>& board, int x, int y, bool* isShip){

    	if(!isValid(board, x, y))
    		return;
    	if(board[x][y] != 'X')
    		return;
    	board[x][y] = '.';
    	horizontal(board, x, y + 1, isShip);
    	horizontal(board, x, y - 1, isShip);
    	if(hasShip(board, x + 1, y)){
    		dfs(board, x - 1, y);
    		*isShip = false;
    	}
    	if(hasShip(board, x, y-1)){
    		dfs(board, x, y-1);
    		*isShip = false;
    	}
    }


    bool isValid(vector<vector<char>>& board, int x, int y){

    	if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size())
    		return false;
    	return true;
    }

    bool hasShip(vector<vector<char>>& board, int x, int y){
    	if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size())
    		return false;
    	if(board[x][y] == 'X')
    		return true;
    	return false;
    }

    void dfs(vector<vector<char>>& board, int x, int y){
    	if(!isValid(board, x, y))
    		return;
    	if(board[x][y] != 'X')
    		return;
    	board[x][y] = '.';
    	dfs(board, x, y+1);
    	dfs(board, x, y-1);
    	dfs(board, x+1, y);
    	dfs(board, x-1, y);

    }

    void showBoard(vector<vector<char>>& board){
    	int i, j;
    	for(i=0;i<board.size();i++){
    		for(j=0;j<board[0].size();j++){
    			cout << board[i][j] << " ";
    		}
    		cout << endl;
    	}
    }
};