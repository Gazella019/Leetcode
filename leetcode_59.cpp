



class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n, vector<int>(n, 0));
        int i, l, r, t, b, num = 1;
        l = 0, r = n-1, t = 0, b = n-1;

        while(num != (n*n)+1){

        	for(i=l;i<=r;i++){
        		v[t][i] = num;
        		num++;
        	}
        	t++;
        	for(i=t;i<=b;i++){
        		v[i][r] = num;
        		num++;
        	}
        	r--;
        	for(i=r;i>=l;i--){
        		v[b][i] = num;
        		num++;
        	}
        	b--;
        	for(i=b;i>=t;i--){
        		v[i][l] = num;
        		num++;
        	}
        	l++;
        }
        return v;
    }
};