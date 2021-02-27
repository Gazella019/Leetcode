


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
      	if(matrix.size() == 0 || matrix[0].size() == 0)
        	return {};
        int i, left, right, bottom, top, count = 0;
        int m, n;
        vector<int> v;
        m = matrix.size();
        n = matrix[0].size();
        left = 0;
        right = n-1;
        top = 0;
        bottom = m-1;

        while(count != m*n){
        	for(i=left;i<=right;i++){
        		v.push_back(matrix[top][i]);
        		count ++;
        	}
        	if(count == m*n)
        		break;
        	top ++;
        	for(i=top;i<=bottom;i++){
        		v.push_back(matrix[i][right]);
        		count ++;
        	}
        	if(count == m*n)
        		break;
        	right --;
        	for(i=right;i>=left;i--){
        		v.push_back(matrix[bottom][i]);
        		count ++;
        	}
        	if(count == m*n)
        		break;
        	bottom--;
        	for(i=bottom;i>=top;i--){
        		v.push_back(matrix[i][left]);
        		count ++;
        	}
        	if(count == m*n)
        		break;
        	left++;
        }
        return v;
    }
};