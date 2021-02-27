



class Solution {
public:
    int longestStrChain(vector<string>& words) {
        
        int i, j, k, n, res = 0;

        n = words.size();

        vector<vector<int>> length(17);
        vector<vector<int>> table(n, vector<int>(26, 0));
        vector<int> dp(n, 1);


        for(i=0;i<words.size();i++){
        	length[words[i].size()].push_back(i);
        	for(j=0;j<words[i].size();j++){
        		table[i][words[i][j]-'a'] += 1;
        	}
        }

        for(i=1;i<length.size();i++){
        	for(j=0;j<length[i].size();j++){
        		for(k=0;k<length[i-1].size();k++){
        			if(canChian(table[length[i][j]], table[length[i-1][k]])){
        				dp[length[i][j]] = max(dp[length[i][j]], dp[length[i-1][k]]+1);
        			}
        		}
        		res = max(res, dp[length[i][j]]);
        	}
        }
        for(i=0;i<dp.size();i++){
        	cout << dp[i] << " ";
        }
        return res;
    }

    bool canChian(vector<int>& a, vector<int>& b){
    	int i, diff = 0;
    	for(i=0;i<26;i++){
    		diff += abs(a[i]-b[i]); 
    	}
    	if(diff == 1)
    		return true;
    	return false;
    }
};