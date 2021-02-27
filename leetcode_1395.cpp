




class Solution {
public:

    
    int numTeams(vector<int>& rating) {
        
        int i, j, n, res = 0, ls, lr, rs, rr;
        n = rating.size();
        vector<vector<int>> dp(n, vector<int>(2, 1));

        for(i=0;i<n;i++){
            ls = 0, lr = 0, rs = 0, rr = 0;
            for(j=i-1;j>=0;j--){
                if(rating[j] > rating[i])
                    lr ++;
                if(rating[j] < rating[i])
                    ls ++;
            }
            for(j=i+1;j<n;j++){
                if(rating[j] > rating[i])
                    rr ++;
                if(rating[j] < rating[i])
                    rs ++;
            }
            res = res + (ls * rr) + (lr * rs);
        }

        return res;
    }
};



class Solution {
public:

	
    int numTeams(vector<int>& rating) {
    	
    	int res = 0;
    	for(int i=0;i<rating.size();i++){
    		for(int j=i+1;j<rating.size();j++){
    			for(int k=j+1;k<rating.size();k++){
    				if(rating[k] > rating[j] && rating[j] > rating[i])
    					res ++;
    				if(rating[k] < rating[j] && rating[j] < rating[i])
    					res ++;
    			}
    		}
    	}	

    	return res;
    }
};
