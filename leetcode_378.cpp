


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int i, j, m, n, cur, num, res;
        m = matrix.size(), n = matrix[0].size();
        num = m*n;
        priority_queue<int> pq;
        for(i=0;i<m;i++){
        	for(j=0;j<n;j++){
        		cout << matrix[i][j] << " ";
        		pq.push(matrix[i][j]);
        	}
        }

        while(num >= k){
        	res = pq.top();
        	num--;
        	pq.pop();
        }

        return res;
    }
};