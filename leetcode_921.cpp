


class Solution {
public:
    int minAddToMakeValid(string S) {
        
        int i, n, l = 0, r = 0, res = 0;
        n = S.size();

        for(i=0;i<n;i++){
        	if(S[i] == '(')
        		l++;
        	else{
        		while(r >= l){
        			l++, res ++;
        		}
        		r++;
        	}
        }

        res += abs(l-r);

        return res;
    }
};