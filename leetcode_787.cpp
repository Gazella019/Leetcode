


class Solution {
public:

	int res = INT_MAX;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
        int i, j, cur, num, cnt, sz;
        vector<vector<int>> graph(n);
        vector<vector<int>> weight(n);
        vector<int> v(n, INT_MAX);
        queue<int> que;
        queue<int> sum;

        for(i=0;i<flights.size();i++){
        	graph[flights[i][0]].push_back(flights[i][1]);
        	weight[flights[i][0]].push_back(flights[i][2]);
        }

        que.push(src);
        sum.push(0);
        cnt = 0;
        while(que.size() != 0 && cnt <= K+1){
        	sz = que.size();
        	for(j=1;j<=sz;j++){
	        	cur = que.front(), num = sum.front();
	        	que.pop(), sum.pop();
	        	if(num >= v[cur] || num >= v[dst])
	        		continue;
	        	v[cur] = num;
	        	for(i=0;i<graph[cur].size();i++){
	        		que.push(graph[cur][i]);
	        		sum.push(num + weight[cur][i]);
	        	}
	        }
	        cnt ++;
        }

        if(v[dst] == INT_MAX)
        	return -1;
        return v[dst];
    }

};


// TLE
class Solution {
public:

	int res = INT_MAX;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
        int i;
        vector<vector<int>> graph(n);
        vector<vector<int>> weight(n);

        for(i=0;i<flights.size();i++){
        	graph[flights[i][0]].push_back(flights[i][1]);
        	weight[flights[i][0]].push_back(flights[i][2]);
        }
        dfs(graph, weight, src, 0, dst, 0, K+1);
        if(res == INT_MAX)
        	return -1;
        return res;
    }

    void dfs(vector<vector<int>>& graph, vector<vector<int>>& weight, int n, int cnt, int dst, int k, int K){

    	if(k > K)
    		return;
    	if(n == dst){
    		res = min(res, cnt);
    		return;
    	}

    	for(int i=0;i<graph[n].size();i++){
    		dfs(graph, weight, graph[n][i], cnt+weight[n][i], dst, k+1,K);
    	}

    }
};