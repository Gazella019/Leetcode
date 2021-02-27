

class Solution {
public:
    int minCut(string s) {
        
        int table[s.size()][s.size()] = {0};
        int dp[s.size()];
        int i, l, start, end;


        for(i=0;i<s.size();i++){
        	if(i != 0 && s[i-1] == s[i])
        		table[i-1][i] = 1;
        	table[i][i] = 1;
        	dp[i] = i;
        }

        for(l=3;l<=s.size();l++){
        	for(i=0;i+l-1<s.size();i++){
        		end = i+l-1;
        		if(s[i] == s[end]){
        			table[i][end] = table[i+1][end-1];
        		}
        		else
        			table[i][end] = 0;
        	}
        }

        for(i=1;i<s.size();i++){
        	for(start=i;start>=0;start--){
        		if(table[start][i] == 1){
        			if(start == 0)
        				dp[i] = 0;
        			else
        				dp[i] = min(dp[i], dp[start-1] + 1);
        		}
        	}
        }
        return dp[s.size()-1];
    }
};





// only 1 TLE
class Solution {
public:
    int minCut(string s) {
        
        int i, l, k, end, cut, res;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));

        for(i=0;i<s.size();i++){
        	dp[i][i] = 1;
        }

        for(i=0;i<s.size()-1;i++){
        	if(s[i] == s[i+1])
        		dp[i][i+1] = 1;
        	else
        		dp[i][i+1] = 2;
        }

        for(l=3;l<=s.size();l++){
        	for(i=0;i+l-1<s.size();i++){
        		end = i+l-1;
        		if(s[i] == s[end] && dp[i+1][end-1] == 1)
        			dp[i][end] = 1;
        		else{
        			cut = l;
	        		for(k=i+1;k<=end;k++){
	        			cut = min(cut, dp[i][k-1] + dp[k][end]);
	        		}
	        		dp[i][end] = cut;
	        	}
        	}
        }
        for(i=0;i<s.size();i++){
        	for(k=0;k<s.size();k++){
        		cout << dp[i][k] << " ";
        	}
        	cout << endl;
        }
        return dp[0][s.size()-1]-1;
    }
};

