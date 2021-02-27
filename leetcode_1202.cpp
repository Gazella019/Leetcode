


class Solution {
public:

	string str;
	vector<vector<int>> graph;
	vector<int> vis;
	vector<int> v;
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        int i, j, n;
        n = s.size();
    	string res;
    	graph.resize(n);
    	vis.resize(n, 0);
    	res = s;
    	for(i=0;i<pairs.size();i++){
    		graph[pairs[i][0]].push_back(pairs[i][1]);
    		graph[pairs[i][1]].push_back(pairs[i][0]);
    	}

    	for(i=0;i<n;i++){
    		if(vis[i] == 0){
    			v.clear();
    			str = "";
    			dfs(s, i);
    			sort(str.begin(), str.end());
    			sort(v.begin(), v.end());
    			for(j=0;j<v.size();j++){
    				res[v[j]] = str[j];
    			}
    		}
    	}

    	return res;
    }

    void dfs(string s, int n){

    	vis[n] = 1;
    	v.push_back(n);
    	str = str + s[n];
    	for(int i=0;i<graph[n].size();i++){
    		if(vis[graph[n][i]] == 0)
    			dfs(s, graph[n][i]);
    	}
    }
};