


class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        
    	sort(A.begin(), A.end());

    	int l = 0, r = A.size()-1, sum, res = -1;

    	while(l < r){
    		sum = A[l] + A[r];
    		if(sum < K){
    			res = max(res, sum);
    			l ++;
    		}
    		if(sum >= K){
    			r --;
    		}
    	}
    	return res;
    }
};