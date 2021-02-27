


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> res(matrix.size(), vector<int>(matrix[0].size(), INT_MAX));
        for(int i=0;i<res.size();i++){
        	for(int j=0;j<res[0].size();j++){
        		if(matrix[i][j] == 0)
        			res[i][j] = 0;
        		else
        			res[i][j] = min(isValid(res, i-1, j)+1, isValid(res, i, j-1)+1, res[i][j]);
        	}
        }

        for(int i=res.size()-1;i>=0;i--){
        	for(int j=res[0].size()-1;j>=0;j--){
        		if(matrix[i][j] == 0)
        			res[i][j] = 0;
        		else
        			res[i][j] = min(isValid(res, i+1, j)+1, isValid(res, i, j+1)+1, res[i][j]);
        	}
        }
        print(res);

        return res;
    }

    void print(vector<vector<int>> res){
    	for(int i=0;i<res.size();i++){
        	for(int j=0;j<res[0].size();j++){
        		cout << res[i][j] << " ";
        	}
        	cout << endl;
        }
    }

    int min(int a, int b, int c){
    	if(a <= b && a <= c)
    		return a;
    	if(b <= a && b <= c)
    		return b;
    	return c;
    }

    int isValid(vector<vector<int>> res, int row, int col){
    	if(row < 0 || col < 0 || row >= res.size() || col >= res[0].size())
    		return 100000;
    	return res[row][col];
    }
};



class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> res(matrix.size(), vector<int>(matrix[0].size(), INT_MAX));
        for(int i=0;i<res.size();i++){
        	for(int j=0;j<res[0].size();j++){
        		if(matrix[i][j] == 0){
        			dfs(res, i, j, 0);
        		}
        	}
        }
        return res;
    }

    void dfs(vector<vector<int>>& res, int row, int col, int dist){
    	if(isValid(res, row, col) == false)
    		return;
    	if(res[row][col] < dist)
    		return;
    	res[row][col] = dist;
    	dfs(res, row+1, col, dist+1);
    	dfs(res, row-1, col, dist+1);
    	dfs(res, row, col+1, dist+1);
    	dfs(res, row, col-1, dist+1);
    }

    bool isValid(vector<vector<int>> matrix, int row, int col){
    	if(row < 0 || col < 0 || row >= matrix.size() || col >= matrix[0].size())
    		return false;
    	return true;
    }
};



// memory limit exceed
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> res(matrix.size(), vector<int>(matrix[0].size(), 0));
        for(int i=0;i<res.size();i++){
        	for(int j=0;j<res[0].size();j++){
        		if(matrix[i][j] == 0)
        			res[i][j] = 0;
        		else{
        			res[i][j] = bfs(matrix, i, j);
        		}
        	}
        }
        return res;
    }

    int bfs(vector<vector<int>> matrix, int row, int col){
    	int count = 0, m = matrix.size(), n = matrix[0].size(), total, step = 0;
    	queue<int> q1;
    	queue<int> q2;

    	if(isValid(matrix, row-1, col)){
    		q1.push(row-1);
    		q2.push(col);
    		count ++;
    	}
    	if(isValid(matrix, row+1, col)){
    		q1.push(row+1);
    		q2.push(col);
    		count ++;
    	}
    	if(isValid(matrix, row, col-1)){
    		q1.push(row);
    		q2.push(col-1);
    		count++;
    	}
    	if(isValid(matrix, row, col+1)){
    		q1.push(row);
    		q2.push(col+1);
    		count ++;
    	}
    	while(1){
    		total = count;
    		step ++;
    		count = 0;
    		for(int i=1;i<=total;i++){
    			row = q1.front();
    			col = q2.front();

    			if(isValid(matrix, row-1, col)){
    				if(matrix[row][col] == 0){
    					return step;
    					break;
    				}
		    		q1.push(row-1);
		    		q2.push(col);
		    		count ++;
		    	}
		    	if(isValid(matrix, row+1, col)){
		    		if(matrix[row][col] == 0){
    					return step;
    					break;
    				}
		    		q1.push(row+1);
		    		q2.push(col);
		    		count ++;
		    	}
		    	if(isValid(matrix, row, col-1)){
		    		if(matrix[row][col] == 0){
    					return step;
    					break;
    				}
		    		q1.push(row);
		    		q2.push(col-1);
		    		count++;
		    	}
		    	if(isValid(matrix, row, col+1)){
		    		if(matrix[row][col] == 0){
    					return step;
    					break;
    				}
		    		q1.push(row);
		    		q2.push(col+1);
		    		count ++;
		    	}

    			q1.pop();
    			q2.pop();
    		}

    	}
    	return step;
    }

    bool isValid(vector<vector<int>> matrix, int row, int col){
    	if(row < 0 || col < 0 || row >= matrix.size() || col >= matrix[0].size())
    		return false;
    	return true;
    }
};