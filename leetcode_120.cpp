

// Runtime: 4 ms, faster than 96.01% of C++
// Memory Usage: 9.5 MB, less than 100.00% of C++

// DP 
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int i, j;
        int minVal = 100000;
        for(i=1;i<triangle.size();i++){
        	triangle[i][0] += triangle[i-1][0];
        	for(j=1;j<triangle[i].size()-1;j++){
        		triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
        	}
        	triangle[i][j] += triangle[i-1][j-1];
        }

        i = triangle.size()-1;
        for(j=0;j<triangle[i].size();j++){
        	if(triangle[i][j] < minVal)
        		minVal = triangle[i][j];
        }
        return minVal;
    }
};

// dfs sol time exceed
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int min = 10000, n = 0, level = 0, sum = 0;
        dfs(triangle, level, n, sum, &min);
        return min;
    }
    void dfs(vector<vector<int>>& triangle, int level, int n, int sum, int* min){
    	
    	if(level == triangle.size()){
    		if(sum < *min)
    			*min = sum;
    		return;
    	}
    	sum = sum + triangle[level][n];
    	dfs(triangle, level+1, n, sum, min);
    	dfs(triangle, level+1, n+1, sum, min);
    }
};