



class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        
        bool canSwap;
        int i, n, acount, bcount, max, c;
       	vector<int> total(7, 0);
       	n = A.size();
        for(i=0;i<n;i++){
        	total[A[i]] += 1;
        	total[B[i]] += 1;
        }

        max = 1;
        for(i=0;i<7;i++){
        	if(total[i] > total[max])
        		max = i;
        }

        canSwap = true;
        c = max;
        for(i=0;i<A.size();i++){
       		if(A[i] != c && B[i] != c){
       			canSwap = false;
       			break;
       		}
       	}
       	if(canSwap){
       		acount = 0, bcount = 0;
       		for(i=0;i<A.size();i++){
       			if(A[i] != c)
       				acount++;
       			if(B[i] != c)
       				bcount++;
       		}
       		return min(acount, bcount);
       	}
        
        return -1;
    }
};