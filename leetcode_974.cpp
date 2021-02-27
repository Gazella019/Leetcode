


// Sol O(N)

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int i, index, sum = 0, count = 0;
        map<int, int> hash;

        for(i=0;i<A.size();i++){        	
        	sum = sum + A[i];
        	index = sum % K;
        	if(index == 0)
        		count = count + hash[index] + 1;
        	else if(index > 0)
        		count = count + hash[index] + hash[index-K];
        	else if(index < 0)
        		count = count + hash[index] + hash[K+index];
        	hash[index] ++;
        }
        return count;
    }
};



// Sol O(N^2) TLE
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int i, j, sum, count = 0;
        for(i=0;i<A.size();i++){
        	sum = 0;
        	for(j=i;j<A.size();j++){
        		sum = sum + A[j];
        		if(sum % K == 0)
        			count = count + 1;
        	}
        }
        return count;
    }
};