


class Solution {
public:
    string getPermutation(int n, int k) {
        string str(n, ' ');

    }

    int 
};


// 可以優化 根據 lead number
// 用階乘來算

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> used(n+1, 0);
        string s(n, ' ');
        int count = 1, now = 1;
        permutation(now, n, k, &count, used, s);
        return s;
    }

    void permutation(int now, int n, int k, int* count, vector<int>& used, string &s){
    	int i;
    	if(now > n){
    		*count = *count + 1;
 			return;
    	}
    	for(i=1;i<=n;i++){
    		if(used[i] == 0 && *count <= k){
    			used[i] = 1;
    			s[now-1] = i + '0';
    			permutation(now+1, n, k, count, used, s);
    			used[i] = 0;
    		}
    	}
    }
};