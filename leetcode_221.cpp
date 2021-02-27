



class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        if(matrix.size() == 0)
        	return 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        int i, j, k, offset, res = 0;
    	for(i=0;i<matrix.size();i++){
    		for(j=0;j<matrix[0].size();j++){
    			if(matrix[i][j] == '1'){
    				dp[i][j] = 1;
    				if(isValid(matrix, i-1, j-1) && matrix[i-1][j-1] == '1'){
    					k = dp[i-1][j-1];
    					offset = 1;
    					while(offset <= k){
    						if(!isValid(matrix, i, j-offset) || !isValid(matrix, i-offset, j))
    							break;
    						if(matrix[i][j-offset] == '0' || matrix[i-offset][j] == '0')
    							break;
    						dp[i][j] = offset+1;
    						offset ++;
    					}
    				}
    				res = max(res, dp[i][j]);
    			}
    		}
    	}
    	return res*res;
    }

    bool isValid(vector<vector<char>>& matrix, int row, int col){
    	if(row < 0 || col < 0 || row >= matrix.size() || col >= matrix[0].size())
    		return false;
    	return true;
    }
};



class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        if(matrix.size() == 0)
        	return 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        int i, j, k, offset, res = 0;
    	for(i=0;i<matrix.size();i++){
    		for(j=0;j<matrix[0].size();j++){
    			if(matrix[i][j] == '1'){
    				dp[i][j] = 1;
    				if(isValid(matrix, i-1, j-1) && matrix[i-1][j-1] == '1'){
    					k = dp[i-1][j-1];
    					offset = 1;
    					while(offset <= k){
    						if(!isValid(matrix, i, j-offset) || !isValid(matrix, i-offset, j))
    							break;
    						if(matrix[i][j-offset] == '0' || matrix[i-offset][j] == '0')
    							break;
    						dp[i][j] = offset+1;
    						offset ++;
    					}
    				}
    				res = max(res, dp[i][j]);
    			}
    		}
    	}

    	for(i=0;i<dp.size();i++){
    		for(j=0;j<dp[0].size();j++){
    			cout << dp[i][j] << " ";
    		}
    		cout << endl;
    	}

    	return res*res;
    }

    bool isValid(vector<vector<char>>& matrix, int row, int col){
    	if(row < 0 || col < 0 || row >= matrix.size() || col >= matrix[0].size())
    		return false;
    	return true;
    }
};