



class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    	vector<int> row;
    	vector<int> col;
    	int i, j;
    	for(i=0;i<matrix.size();i++){
    		for(j=0;j<matrix[0].size();j++){
    			if(matrix[i][j] == 0){
    				row.push_back(i);
    				col.push_back(j);
    				//cout << "i " << i << " j " << j << endl;
    			}
    		}
    	}
    	for(i=0;i<row.size();i++){
    		clear(matrix, row[i], col[i]);
    	}

    }

    void clear(vector<vector<int>>& matrix, int i, int j){
    	for(int k=0;k<matrix[0].size();k++){
    		matrix[i][k] = 0;
    	}
    	for(int k=0;k<matrix.size();k++){
    		matrix[k][j] = 0;
    	}
    }

};