




class Solution {
public:
	int mod = 1e9 + 7;
    int numberOfArrays(string s, int k) {
        int cnt = 0, l, r, mul = 1;
        long sum = 0;
        if(s[0] == '0')
        	return 0;
        if(s.size() == 1)
        	return 1;
        for(int i=s.size()-1;i>=0;i--){
        	sum += ((s[i]-'0') * mul);
        	mul *= 10;
        	if(sum > k)
        		return 0;
        }
    	for(int i=1;i<s.size();i++){
    		l = numberOfArrays(s.substr(0, i), k);
    		r = numberOfArrays(s.substr(i), k);
    		cnt += max(0, (l*r) - 2);
    	}
    	return cnt + 2;
    }
};

