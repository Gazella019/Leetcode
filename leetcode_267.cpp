


class Solution {
public:
	
    vector<string> generatePalindromes(string s) {
        
        int oddNums = 0;
        unordered_map<char, int> table;
        unordered_map<char, int> odd;
        vector<string> res;
        string str(s.size(), ' ');
        for(int i=0;i<s.size();i++){
        	table[s[i]] += 1;
        }
        for(auto& it:table){
        	if(it.second%2 == 1){
        		odd[it.first] = 1;
        		oddNums ++;
        	}
        	it.second /= 2;
        }
        if(oddNums > 1)
        	return res;
        backtracking(res, table, odd, str, 0, s.size());
        return res;
    }

    void backtracking(vector<string>& res, unordered_map<char, int>& table, unordered_map<char, int>& odd, string str, int n, int sz){
    	
    	if(n == (sz/2)){
    		int l, r;
    		l = 0, r = sz-1;
    		while(l < r){
    			str[r] = str[l];
    			l++, r--;
    		}
    		if(sz%2 == 1){
    			for(auto& it:odd){
    				if(it.second >= 1){
    					str[n] = it.first;
    					res.push_back(str);
    				}
    			}	
    			return;
    		}
    		res.push_back(str);
    		return;
    	}

    	for(auto& it:table){
    		if(it.second >= 1){
    			it.second -= 1;
    			str[n] = it.first;
    			backtracking(res, table, odd, str, n+1, sz);
    			it.second += 1;
    		}
    	}
    }
};


// shit do not check if can palindrome
class Solution {
public:
	unordered_map<char, int> table;
    vector<string> generatePalindromes(string s) {
        
        int oddNums = 0;
        vector<string> res;
        string str(s.size(), ' ');

        for(int i=0;i<s.size();i++){
        	table[s[i]] += 1;
        }
        for(auto& it:table){
        	if(it.second%2 == 1){
        		if(oddNums >= 1)
        			return res;
        		oddNums ++;
        	}
        };
        backtracking(res, str, 0, s.size()-1);
        return res;
    }

    void backtracking(vector<string>& res, string str, int l, int r){
    	if(r < l){
    		res.push_back(str);
    		return;
    	}
    	if(l == r){
    		for(auto& it:table){
    			if(it.second >= 1){
    				str[l] = it.first;
    				res.push_back(str);
    			}
    		}
    	}
    	for(auto& it:table){
    		if(it.second >= 2){
    			it.second -= 2;
    			str[l] = it.first;
    			str[r] = it.first;
    			backtracking(res, str, l+1, r-1);
    			it.second += 2;
    		}
    	}
    }
};