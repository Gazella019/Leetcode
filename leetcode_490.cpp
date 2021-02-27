


class Solution {
public:

    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
		       	
    	vector<vector<int>> visited(maze.size(), vector<int>(maze[0].size(), 0));
    	vector<vector<int>> directions ={{1,0}, {-1,0}, {0,1}, {0,-1}};
    	queue<vector<int>> q;
    	vector<int> temp;
    	vector<int> now;
    	bool isFind = false;
    	int row, col;

    	row = start[0];
    	col = start[1];


    	visited[row][col] = 1;
    	for(int i=0;i<4;i++){
    		temp = toEnd(row, col, maze, directions[i]);
    		if(visited[temp[0]][temp[1]] != 1 && (temp[0] != row || temp[1] != col))
    			q.push(temp);
    	}

    	visited[row][col] = 1;
    	cout << q.size();
    	while(q.size() != 0){

    		now = q.front();
    		visited[now[0]][now[1]] = 1;
    		cout << "row: " << now[0] << " col: " << now[1] << endl;
    		if(now[0] == destination[0] && now[1] == destination[1]){
    			isFind = true;
    			break;
    		}

    		for(int i=0;i<4;i++){
    			temp = toEnd(now[0], now[1], maze, directions[i]);
    			if(visited[temp[0]][temp[1]] != 1 && (temp[0] != now[0] || temp[1] != now[1]))
    				q.push(temp);
    		}

    		q.pop();
    	}

		return isFind;
    }

    
    vector<int> toEnd(int row, int col, vector<vector<int>>& maze, vector<int> directions){
    	while(true){
    		if(willStop(maze, row, col))
    			return {row - directions[0], col - directions[1]};
    		row = row + directions[0];
    		col = col + directions[1];
    	}
    }

    bool willStop(vector<vector<int>>& maze, int row, int col){

    	if(row < 0 || col < 0 || row >= maze.size() || col >= maze[0].size())
    		return true;
    	if(maze[row][col] == 1)
    		return true;
    	return false;
    }
};




// DFS
class Solution {
public:

	bool isFind = false;

    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
		       	
    	vector<vector<int>> visited(maze.size(), vector<int>(maze[0].size(), 0));
    	traversal(start[0], start[1], maze, destination, maze);

		return isFind;

    }

    void traversal(int row, int col, vector<vector<int>>& maze, vector<int>& destination, vector<vector<int>>& visited){
    	
    	int temp;
    	if(row == destination[0] && col == destination[1]){
    		isFind = true;
    		return;
    	}
    	visited[row][col] = 1;
    	cout << "row: " << row << " col: " << col << endl;
    	// 4 direction
    	temp = row + 1;
	    while(willStop(maze, temp, col) == false && isFind == false){
	    	temp++;
	    }
	    temp --;
	    if(visited[temp][col] == 0)
	    	traversal(temp, col, maze, destination, maze);

    	temp = row - 1 ;
	    while(willStop(maze, temp, col) == false && isFind == false){
	    	temp--;
	    }
	    temp ++;
	    if(visited[temp][col] == 0)
	    	traversal(temp, col, maze, destination, maze);

    	temp = col - 1;
	    while(willStop(maze, row, temp) == false && isFind == false){
	    	temp--;
	    }
	    temp ++;
	    if(visited[row][temp] == 0)
	    	traversal(row, temp, maze, destination, maze);

    	temp = col + 1;
	    while(willStop(maze, row, temp) == false && isFind == false){
	    	temp++;
	    }
	    temp --;
	    if(visited[row][temp] == 0)
	    	traversal(row, temp, maze, destination, maze);

    }


    bool willStop(vector<vector<int>>& maze, int row, int col){

    	if(row < 0 || col < 0 || row >= maze.size() || col >= maze[0].size())
    		return true;
    	if(maze[row][col] == 1)
    		return true;
    	return false;
    }
};