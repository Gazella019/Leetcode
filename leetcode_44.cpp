



class Solution {
public:
    bool isMatch(string s, string p) {
        
        if(s.size() == 0 && p.size() == 0)
        	return true;
        vector<vector<int>> dp(p.size()+1, vector<int>(s.size()+1, 0));
        int i, j, count = 0;

        dp[0][0] = 1;

        for(i=1;i<p.size()+1;i++){
        	if(p[i-1] == '*')
        		dp[i][0] = 1;
        	else
        		break;
        }


        for(i=1;i<p.size()+1;i++){
        	for(j=1;j<s.size()+1;j++){

        		if(s[j-1] == p[i-1] || p[i-1] == '?'){
        			dp[i][j] = dp[i-1][j-1];
        		}
        		else if(p[i-1] == '*')
        			dp[i][j] = max(dp[i-1][j], max(dp[i-1][j-1], dp[i][j-1]));
        		else
        			dp[i][j] = 0;
        	}
        }

        for(i=0;i<p.size()+1;i++){
        	for(j=0;j<s.size()+1;j++){
        		cout << dp[i][j] << " ";
        	}
        	cout << endl;
        }

        return dp[p.size()][s.size()];
    }

};
