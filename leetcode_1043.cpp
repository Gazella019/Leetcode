



class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        
        int i, j, mx;
        vector<int> dp(A.size()+1, 0);

        for(i=0;i<A.size();i++){
        	mx = 0;
        	for(j=i;j>=i-K+1;j--){
        		if(j<0)
        			break;
        		mx = max(mx, A[j]);
        		dp[i+1] = max(dp[i+1], dp[j]+(mx*(i-j+1)));
        	}

        }

        for(i=0;i<dp.size();i++){
        	cout << dp[i] << " ";
        }
        return dp[A.size()];
    }
};