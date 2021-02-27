




class Solution {
public:
    int getKth(int lo, int hi, int k) {
        
        int i, idx = 0;
        unordered_map<int, int> dp;
        dp[1] = 0;

        vector<int> v;
        
        for(i=lo;i<=hi;i++){
        	v.push_back(i);
        	power(dp, i);
        }

        sort(v.begin(), v.end(), [&](int& a, int& b){
        	int x, y;
        	x = power(dp, a), y = power(dp, b);
        	if(x == y)
        		return a <= b;
        	return x < y;
        });
        
        return v[k-1];
    }

    int power(unordered_map<int, int>& dp, int n){
    	if(dp.find(n) != dp.end())
    		return dp[n];
    	int res;
    	if(n%2 == 0){
    		res = power(dp, n/2);
    	}
    	else{
    		res = power(dp, (3*n)+1);
    	}
    	dp[n] = res+1;
    	return res + 1;
    }
};