


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int i, j;
        vector<int> dp(s.size(), 0);
        unordered_set<string> set;
        string str;

        for(i=0;i<wordDict.size();i++){
        	set.insert(wordDict[i]);
        }
        for(i=0;i<s.size();i++){
        	for(j=i;j<s.size();j++){
        		str = s.substr(i, j-i+1);
        		if(i == 0 && set.find(str) != set.end()){
        			dp[j] = 1;
        		}
        		else if(set.find(str) != set.end() && dp[i-1] == 1){
        			dp[j] = 1;
        		}
        	}
        }

        return dp[s.size()-1];
    }
};



class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int i, j;
        int dp[s.size()+1] = {0};

        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

        dp[0] = 1;

        for(i=0;i<s.size();i++){
        	for(j=0;j<=i;j++){

        		if(dp[j] && wordSet.find(s.substr(j,i-j+1)) != wordSet.end() ){
        			dp[i+1] = 1;
        			break;
        		}
        	}
        }

        //for(i=0;i<=s.size();i++){
        //	cout << dp[i] << " ";
        //}

        return dp[s.size()];
    }
};