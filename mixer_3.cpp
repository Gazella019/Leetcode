

int canPass = 0;
// dir 1
void dfs(vector<vector<int>>& board, int row, int col, int tx, int ty, int dir){

	if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size())
		return;

	if(row == tx && col == ty){
		canPass = 1;
		return;
	}

	if(board[row][col] == 1){
		if(dir == 1)
			dfs(board, row, col-1, tx, ty, 4);
		else if(dir == 2)
			dfs(board, row, col+1, tx, ty, 3);
		else if(dir == 3)
			dfs(board, row-1, col, tx, ty, 2);
		else if(dir == 4)
			dfs(board, row+1, col, tx, ty, 1);
	}
	else{
		if(dir == 1)
			dfs(board, row, col+1, tx, ty, 3);
		else if(dir == 2)
			dfs(board, row, col-1, tx, ty, 4);
		else if(dir == 3)
			dfs(board, row+1, col, tx, ty, 1);
		else if(dir == 4)
			dfs(board, row-1, col, tx, ty, 2);
	}
}


int main() {

	int n , m, i, j, q, sx, sy, tx, ty, dir;
	char c;
    cin >> n;
    cin >> m;
    vector<vector<int>> board(n, vector<int>(m, 0));

    for(i=0;i<n;i++){
    	for(j=0;j<m;j++){
    		cin >> c;
    		if(c == '/')
    			board[i][j] = 1;
    		else
    			board[i][j] = 2;
    	}
    }	

    cin >> q;

    for(i=1;i<=q;i++){
    	cin >> sx >> sy >> c >> tx >> ty;
    	if(c == 'U')
    		dir = 1;
    	else if(c == 'D')
    		dir = 2;
    	else if(c == 'L')
    		dir = 3;
    	else if(c == 'R')
    		dir = 4;
    	canPass = 0;
    	dfs(board, sx, sy, tx, ty, dir);
    	if(canPass == 1)
    		cout << "Yes" << endl;
    	else
    		cout << "No" << endl;
    }

    return 0;
}