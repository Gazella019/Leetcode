
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {

    	int i, res = 0;
    	vector<int> dp(A.size(), 0);

    	for(i=2;i<A.size();i++){

    		if(A[i]-A[i-1] == A[i-1]-A[i-2]){
    			dp[i] = dp[i-1] + 1;
    			res = res + dp[i];
    		}
    	}

    	for(i=0;i<A.size();i++){
    		cout << dp[i] << " ";
    	}
    	return res;
    }
};

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        
        int i, cur, res = 0, cnt = 0;
        vector<int> diff;

        for(i=1;i<A.size();i++){
        	diff.push_back(A[i]-A[i-1]);
        }

        for(i=0;i<diff.size();i++){
        	cur = i;
        	while(cur<diff.size()-1 && diff[cur] == diff[cur+1]){
        		cur ++;
        	}
        	res = res + arithNums(cur-i+1+1);
        	i = cur;
        }

        return res;
    }

    int arithNums(int l){
    	if(l < 3)
    		return 0;
    	return ((l-1)*(l-2))/2;
    }
};