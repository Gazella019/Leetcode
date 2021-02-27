


class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        
        int i, prev = 0, res = 0;
      	
        sort(A.begin(), A.end());
        for(i=1;i<A.size();i++){
        	if(A[i] == A[i-1]){
        		prev ++;
        		res += prev;
        	}
        	else{
        		prev = prev - (A[i] - A[i-1]-1);
        		prev = max(prev, 0);
        		res += prev;
        	}
        }
       	
        return res;
    }
};