






int cnt = 0;

void dfs(vector<int>& A, vector<int>& vis, int n){

	if(vis[n] == 1)
		return;
	vis[n] = 1;
	cnt ++;
	dfs(A, vis, A[n]);
}


int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int i, res = 0, n;
    n = A.size();
	vector<int> vis(n, 0);

	for(i=0;i<n;i++){
		cnt = 0;
		dfs(A, vis, i);
		res = max(res, cnt);
	}
	cout << "res " << res << endl;
	return res;
}
