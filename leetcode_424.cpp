


class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.size() == 0)
        	return 0;
    	
    	int i, n, start = 0, end, maxCnt = 0, res = 0;
    	vector<int> table(26, 0); 
    	n = s.size();        

    	for(end=0;end<n;end++){
    		table[s[end]-'A'] += 1;
    		maxCnt = max(maxCnt, table[s[end]-'A']);
    		while(maxCnt + k < end-start+1){
    			table[s[start]-'A'] -= 1;
    			start ++;
    		}
    		res = max(res, end-start+1);
    	}
    	return res;
    }
};


class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.size() == 0)
        	return 0;
        int i, n, l, r, mx = 0, res = 0;
        n = s.size();
        vector<int> table(26, 0);
        l = 0, r = 0;
        table[s[0]-'A'] += 1;

        while(r < n){	
        	cout << l << " " << r << endl;
        	mx = 0;
        	for(i=0;i<26;i++){
        		mx = max(mx, table[i]);
        	}
        	if(mx + k >= r-l+1){
        		res = max(res, r-l+1);
        		r ++;
        		if(r < n)
        			table[s[r]-'A'] += 1;
        	}
        	else{
        		table[s[l]-'A'] -= 1;
        		l ++;
        	}
        }
        return res;
    }
};