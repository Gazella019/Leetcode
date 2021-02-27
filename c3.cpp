


class Solution {
public:
	int cnt = 0;
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        int i;
        unordered_map<int, vector<int>> hash;
        for(i=0;i<manager.size();i++){
        	if(i == headID)
        		continue;
        	hash[manager[i]].push_back(i);
        }

        dfs(hash, informTime, headID, 0);
        return cnt;
    }

	void dfs(unordered_map<int, vector<int>>& hash, vector<int>& informTime, int n, int sum){
		if(hash[n].size() == 0){
			cnt = max(cnt, sum);
			return;
		}
		sum = sum + informTime[n];
		for(int i=0;i<hash[n].size();i++){
			dfs(hash, informTime, hash[n][i], sum);
		}
	}

};






class Solution {
public:
	
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        int i, j, cur, sz, cnt, res = 0;
        unordered_map<int, vector<int>> hash;
        queue<int> q;

        for(i=0;i<manager.size();i++){
        	if(i == headID)
        		continue;
        	hash[manager[i]].push_back(i);
        }
        q.push(headID);
        while(q.size() != 0){
        	sz = q.size();
        	cnt = 0;
        	for(i=1;i<=sz;i++){
        		cur = q.front();
        		q.pop();
        		for(j=0;j<hash[cur].size();j++){
        			q.push(hash[cur][j]);
        		}
        		cnt = max(cnt, informTime[cur]);
        	}
        	res = res + cnt;
        }

        return res;
    }


};
