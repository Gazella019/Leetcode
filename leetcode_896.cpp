




class Solution {
public:
    bool isMonotonic(vector<int>& A) {
    	// mode 1 Increasing , 2 Decreasing
        int i, mode = -1;
        if(A.size() == 1 || A.size() == 0)
        	return true;

        for(i=1;i<A.size();i++){
        	if(A[i] > A[i-1]){
        		if(mode == -1)
        			mode = 1;
        		else if(mode == 2)
        			return false;
        	}
        	else if(A[i] < A[i-1]){
        		if(mode == -1)
        			mode = 2;
        		else if(mode == 1)
        			return false;
        	}
        }
        return true;
    }
};