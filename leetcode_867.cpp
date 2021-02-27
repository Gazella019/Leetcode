




class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<vector<int>> res(A[0].size(), vector<int> (A.size()));

        for(i=0;i<A.size();i++){
        	for(j=0;j<A[0].size();j++){
        		res[j][i] = A[i][j];
        	}
        }
        return res;
    }
};