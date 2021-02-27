

class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<long> table;
        vector<long> v(k+1);
        vector<int> vis(k+1, 0);
        for(int i=0;i<v.size();i++){
        	v[i] = i;
        }
        int res = 0, n;
        long f1 = 1, f2 = 1, temp;
        table.push_back(1);
        while(f2 < k){
        	temp = f1 + f2;
        	f1 = f2;
        	f2 = temp;
        	if(f2 <= k)
        		table.push_back(f2);
        }

        return memo(table, v, vis, k);
    }

    long memo(vector<long>& table, vector<long>& v, vector<int>& vis, int n){
    	if(n == 0)
    		return 0;
    	if(vis[n] == 1)
    		return v[n];
    	for(int j=0;j<table.size();j++){
    		if(n-table[j] > 0){
    			v[n] = min(v[n], memo(table, v, vis, n-table[j]) + 1);
    		}
    		else if(n-table[j] == 0)
    			return 1;
    		else
    			break;
    	}
    	vis[n] = 1;
    	return v[n];
    }
};




