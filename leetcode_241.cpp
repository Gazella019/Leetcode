



class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        
        
        int i, n, k, x, y, end, l, sum = 0;
        vector<int> v;
        vector<char> op;
        vector<int> res;
        for(i=0;i<input.size();i++){
        	if(input[i] >= '0' && input[i] <= '9'){
        		sum = (sum * 10) + input[i]-'0';
        	}
        	else{
        		op.push_back(input[i]);
        		v.push_back(sum);
        		sum = 0;
        	}
        }
        v.push_back(sum);
        n = v.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n));
    	for(i=0;i<n;i++){
    		dp[i][i].push_back(v[i]);
    	}
    	for(l=2;l<=n;l++){
    		for(i=0;i+l-1<n;i++){
    			end = i+l-1;
    			for(k=i+1;k<=end;k++){
    				for(x=0;x<dp[i][k-1].size();x++){
    					for(y=0;y<dp[k][end].size();y++){
    						if(op[k-1] == '+')
    							dp[i][end].push_back(dp[i][k-1][x] + dp[k][end][y]);
    						else if(op[k-1] == '-')
    							dp[i][end].push_back(dp[i][k-1][x] - dp[k][end][y]);
    						else if(op[k-1] == '*')
    							dp[i][end].push_back(dp[i][k-1][x] * dp[k][end][y]);
    					}
    				}
    			}
    		}
    	}

    	for(l=1;l<=n;l++){
    		for(i=0;i+l-1<n;i++){
    			end = i+l-1;
    			for(k=0;k<dp[i][end].size();k++){
    				cout << dp[i][end][k] << " ";
    			}
    		}
    		cout << endl;
    	}

    	return dp[0][n-1];
    }
};