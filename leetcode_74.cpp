



class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        if(matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int i, l, r, up, down, mid, m, n, midd;
        m = matrix.size(), n = matrix[0].size();
        up = 0, down = m-1;
        while(up <= down){

            mid = (up+down)/2;

            if(target >= matrix[mid][0]){
                l = 0, r = n-1;
                while(l <= r){
                    midd = (l+r)/2;
                    if(matrix[mid][midd] == target)
                        return true;
                    if(matrix[mid][midd] > target)
                        r = midd-1;
                    else
                        l = midd+1;
                }
                up = mid + 1;
            }
            else if(target < matrix[mid][0])
                down = mid - 1;
        }
        return false;
    }
};



class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i, x, y, l, r, mid;

        if(matrix.size() == 0 || matrix[0].size() == 0)
        	return false;
        
        y = matrix[0].size()-1;
        x = 0; 
        while(x < matrix.size()){

        	if(matrix[x][y] == target)
        		return true;

        	else if(matrix[x][y] > target){
        		if(matrix[x][0] > target)
        			return false;
        		l = 0, r = y;
        		while(l <= r){
        			mid = (l+r)/2;
        			if(matrix[x][mid] == target)
        				return true;
        			if(matrix[x][mid] > target)
        				r = mid-1;
        			else
        				l = mid+1;
        		}
        		return false;
        	}
        	else if(matrix[x][y] < target)
        		x++;
        }

        return false;
    }
};