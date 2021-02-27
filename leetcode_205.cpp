


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        unordered_map<char, char> hash;
        unordered_map<char, int> maped;

        for(int i=0;i<s.size();i++){
        	if(hash.find(s[i]) != hash.end()){
        		if(hash[s[i]] != t[i])
        			return false;
        	}
        	else{
        		if(maped.find(t[i]) != maped.end())
        			return false;
        		hash[s[i]] = t[i];
        		maped[t[i]] = 1;
        	}
        }
        return true;
    }
};