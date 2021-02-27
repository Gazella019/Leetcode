

class Solution {
public:
    int longestSubstring(string s, int k) {
        
        int i, res = 0, start = 0, n;
        n = s.size();
        bool tf = true;
        vector<int> table(26, 0);
        
        for(i=0;i<s.size();i++){
        	table[s[i]-'a'] += 1;
        }
        for(i=0;i<s.size();i++){
        	if(table[s[i]-'a'] < k){
        		tf = false;
        		res = max(res, longestSubstring(s.substr(start, i-start), k));
        		start = i+1;
        	}
        }
        
        if(tf == true)
        	return s.size();
        res = max(res, longestSubstring(s.substr(start, n-start), k));
        return res;
    }
};




class Solution {
public:
    int longestSubstring(string s, int k) {
        
        if(k == 1)
        	return s.size();
        int i, j, m, res = 0;
        bool sw;
        vector<int> table(26, 0);

        for(i=0;i<s.size();i++){
        	for(m=0;m<26;m++){
        		table[m] = 0;
        	}
        	for(j=i;j<s.size();j++){
        		table[s[j]-'a'] += 1;
        		if(table[s[j]-'a'] >= k){
        			sw = true;
        			for(m=0;m<26;m++){
        				if(table[m] > 0 && table[m] < k){
        					sw = false;
        					break;
        				}
        			}
        			if(sw)
        				res = max(res, j-i+1);
        		}
        	}
        }

        return res;
    }
};


