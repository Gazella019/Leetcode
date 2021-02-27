



class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> odd;
        vector<int> even;
        int i;

        for(i=0;i<A.size();i++){
        	if(A[i]%2 == 0)
        		even.push_back(A[i]);
        	else if(A[i]%2 == 1)
        		odd.push_back(A[i]);
        }
        for(i=0;i<odd.size();i++){
        	even.push_back(odd[i]);
        }
        return even;
    }
};



class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
    	int l = 0, r = A.size()-1;

    	while(l < r){
    		if(A[l]%2 == 1){
    			swap(A[l], A[r]);
    			r--;
    		}
    		else
    			l++;
    	}
    	return A;
    }
};