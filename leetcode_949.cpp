



class Solution {
public:

	int mx = -1;
	int thre = 23*60 + 59;

    string largestTimeFromDigits(vector<int>& A) {
        
    	vector<int> vis(4, 0);
    	vector<int> v(4, 0);
    	vector<int> res(4, 0);
    	dfs(A, v, vis, 0);
    	if(mx == -1)
    		return "";
    	res[0] = (mx/60)/10;
    	res[1] = (mx/60)%10;
    	res[2] = (mx%60)/10;
    	res[3] = (mx%60)%10;
    	return to_string(res[0])+to_string(res[1])+":"+to_string(res[2])+to_string(res[3]);
    	return "";
    }

    void dfs(vector<int>&A, vector<int>&v, vector<int>&vis, int n){

    	if(n == A.size()){
    		int num = (v[0]*10+v[1])*60+(v[2]*10+v[3]);
    		if(num <= thre)
    			mx = max(mx, num);
    		return;
    	}

    	for(int i=0;i<A.size();i++){
    		if(vis[i] == 0){
    			vis[i] = 1;
    			v[n] = A[i];
    			dfs(A, v, vis, n+1);
    			vis[i] = 0;
    		}
    	}

    }
};