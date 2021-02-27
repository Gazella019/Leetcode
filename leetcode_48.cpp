
// Runtime: 0 ms, faster than 100.00% of C++
// Memory Usage: 8.8 MB, less than 100.00% of C++

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

    	if(matrix.size() == 0 || matrix[0].size() == 0)
    		return;
    	int n = matrix.size(), temp, i;
        int top = 0, bottom = n-1, left = 0, right = n-1;

        while(top < bottom){
        	for(i=0;left+i<bottom;i++){
        		temp = matrix[top][left+i];
        		matrix[top][left+i] = matrix[bottom-i][left];
        		matrix[bottom-i][left] = matrix[bottom][right-i];
        		matrix[bottom][right-i] = matrix[top+i][right];
        		matrix[top+i][right] = temp;
        	}
        	top ++;
        	left ++;
        	bottom --;
        	right --;
        }
    }
};