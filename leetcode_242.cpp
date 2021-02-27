


class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.size() != t.size())
        	return false;
        int i;
    	unordered_map<char, int> hash;

    	for(i=0;i<s.size();i++){
    		hash[s[i]] += 1;
    	}

    	for(i=0;i<t.size();i++){
    		if(hash[t[i]] == 0)
    			return false;
    		hash[t[i]] -= 1;
    	}

    	return true;
    }
};