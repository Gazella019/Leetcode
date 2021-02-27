


class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        
        int i, cur;
        unordered_map<int, vector<int>> hash;
        vector<int> res;
        queue<int> q;

        for(i=0;i<pid.size();i++){
        	hash[ppid[i]].push_back(pid[i]);
        }
        q.push(kill);
        res.push_back(kill);
        while(q.size() != 0){
        	cur = q.front();
        	q.pop();
        	for(i=0;i<hash[cur].size();i++){
        		q.push(hash[cur][i]);
        		res.push_back(hash[cur][i]);
        	}
        }

        return res;
    }
};