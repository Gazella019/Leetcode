

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        
        int l, r, end;
        vector<int> res(A.size(), 0);
        end = A.size()-1;
        l = 0, r = A.size()-1;
        while(l <= r){
        	if(abs(A[l]) > abs(A[r])){
        		res[end] = A[l] * A[l];
        		l ++;
        		end --;
        	}
        	else{
        		res[end] = A[r] * A[r];
        		r --;
        		end --;
        	}
        }

        return res;
    }
};