


class Solution {
public:

	int res = 0, count = 0, total = 0;

    int maxStudents(vector<vector<char>>& seats) {
        
        int i, j;
        for(i=0;i<seats.size();i++){
        	for(j=0;j<seats.size();j++){
        		if(seats[i][j] = '.')
        			total ++;
        	}
        }
        traversal(seats, 0, 0, 0);
        return res;
    }

    void traversal(vector<vector<char>>& seats, int row, int col, int visited){
    	int i;
    	if(total-visited+count <= res)
    		return;
    	for(i=col;i<seats[0].size();i++){
    		if(seats[row][i] == '.')
    			visited ++;
    		if(seats[row][i] == '.' && canCheat(seats, row, i) == false){
    			seats[row][i] = 's';
    			count ++;
    			traversal(seats, row, i+2, visited);
    			seats[row][i] = '.';
    			count --;
    		}
    	}

    	if(row == seats.size()-1){
    		res = max(res, count);
    		return;
    	}

    	traversal(seats, row+1, 0, visited);
    }

    bool canCheat(vector<vector<char>>& seats, int row, int col){

    	if(isValid(seats, row, col-1) && seats[row][col-1] == 's')
    		return true;
    	if(isValid(seats, row, col+1) && seats[row][col+1] == 's')
    		return true;
    	if(isValid(seats, row-1, col-1) && seats[row-1][col-1] == 's')
    		return true;
    	if(isValid(seats, row-1, col+1) && seats[row-1][col+1] == 's')
    		return true;
    	return false;
    }

    bool isValid(vector<vector<char>>& seats, int row, int col){
    	if(row < 0 || col < 0 || row >= seats.size() || col >= seats[0].size())
    		return false;
    	return true;
    }
};