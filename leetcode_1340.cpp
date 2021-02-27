


class Solution {
public:

    int maxJumps(vector<int>& arr, int d) {
        
        int i, n, res = 0, vis = -1;
        vector<int> dp(arr.size(), 1);
        vector<int> visited(arr.size(), 0);
        
        for(i=0;i<arr.size();i++){
        	dp[i] = dfs(arr, dp, visited, i, d);
        	res = max(res, dp[i]);
        }
        return res;
    }

    int dfs(vector<int>& arr, vector<int>& dp, vector<int>& visited, int n, int d){

    	if(visited[n] == 1)
    		return dp[n];

    	for(int i=n+1;i<=n+d;i++){
    		if(i < arr.size()){
    			if(arr[n] > arr[i])
    				dp[n] = max(dp[n], dfs(arr, dp, visited, i, d)+1);
    			else
    				break;
    		}
    		else
    			break;
    	}

    	for(int i=n-1;i>=n-d;i--){
    		if(i >= 0){
    			if(arr[n] > arr[i])
    				dp[n] = max(dp[n], dfs(arr, dp, visited, i, d)+1);
    			else
    				break;
    		}
    		else
    			break;
    	}

    	visited[n] = 1;
    	return dp[n];
    }	
};




class Solution {
public:

	int res = 0;

    int maxJumps(vector<int>& arr, int d) {
        
        int i, n, vis = -1;
        vector<int> dp(arr.size(), 1);
        unordered_map<int, vector<int>> hash;
        priority_queue<int, vector<int>, greater<int> > pq;

        for(i=0;i<arr.size();i++){
        	hash[arr[i]].push_back(i);
        	pq.push(arr[i]);
        }

        while(pq.size() != 0){
        	n = pq.top();
        	if(n != vis){
        		for(i=0;i<hash[n].size();i++){
        			dfs(arr, dp, hash[n][i], d);
        		}
        	}
        	vis = n;
        	pq.pop();
        }

        for(i=0;i<dp.size();i++){
        	cout << dp[i] << " ";
        }

        return res;
    }

    void dfs(vector<int>& arr, vector<int>& dp, int n, int d){

    	int i;
    	for(i=n-1;i>=n-d;i--){
    		if(i >= 0){
    			if(arr[n] > arr[i])
    				dp[n] = max(dp[n], dp[i]+1);
    			else
    				break;
    		}
    	}
    	for(i=n+1;i<=n+d;i++){
    		if(i < arr.size()){
    			if(arr[n] > arr[i])
    				dp[n] = max(dp[n], dp[i]+1);
    			else
    				break;
    		}
    	}
    	res = max(res, dp[n]);
    }
};