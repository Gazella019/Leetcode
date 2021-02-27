




class Solution {
public:

	int res = 0;
    int countArrangement(int N) {
        
        vector<int> v(N, 0);
        vector<int> vis(N+1, 0);
        dfs(v, vis, 0, N);
        return res;
    }


    void dfs(vector<int>& v, vector<int>& vis, int n, int N){

    	if(n == N){
    		res ++;
    		for(int i=0;i<v.size();i++){
    			cout << v[i] << " ";
    		}
    		cout << endl;
    		return;
    	}

    	for(int i=1;i<=N;i++){
    		if(vis[i] == 1)
    			continue;
    		if(i%(n+1) == 0 || (n+1)%i == 0){
    			v[n] = i;
    			vis[i] = 1;
    			dfs(v, vis, n+1, N);
    			vis[i] = 0;
    		}
    	}
    }

};