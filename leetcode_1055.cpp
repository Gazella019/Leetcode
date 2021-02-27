

class Solution {
public:
    int shortestWay(string source, string target) {
        
        int i, j, cnt = 0;
        vector<int> table(26, 0);
        for(i=0;i<source.size();i++){
        	table[source[i]-'a'] += 1;
        }
        for(i=0;i<target.size();i++){
        	if(table[target[i]-'a'] == 0)
        		return -1;
        }
        j = 0;
        while(j <= target.size()-1){
        	for(i=0;i<source.size();i++){
        		if(source[i] == target[j]){
        			j++;
        		}
        	}
        	cnt ++;
        }

        return cnt;
    }
};


// 以為是substring
class Solution {
public:
    int shortestWay(string source, string target) {
        
        int i, j, l, mn;
        vector<int> dp(target.size()+1);
        unordered_map<string, int> hash;
        for(l=1;l<=target.size();l++){
        	for(i=0;i+l-1<target.size();i++){
        		hash[source.substr(i, l)] += 1;
        	}
        }

        for(i=0;i<target.size();i++){
        	mn = INT_MAX;
        	for(j=i;j>=0;j--){
        		if
        	}
        }

        return dp[target.size()];
    }
};