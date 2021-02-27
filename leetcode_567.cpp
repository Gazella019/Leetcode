



class Solution {
public:
    bool checkInclusion(string s1, string s2) {
    	if(s2.size() < s1.size())
    		return false;
        int table[26] = {0};
        int memo[26] = {0};
        int i, j;
        bool tf = false;
        for(i=0;i<s1.size();i++){
        	table[s1[i]-'a'] += 1;
        }

        for(i=0;i<=s2.size()-s1.size();i++){
        	//cout << i;
        	if(tf == false){
        		for(j=i;j<i+s1.size();j++){
        			if(table[s2[j]-'a'] == 0)
        				break;
        			memo[s2[j]-'a'] += 1;
        			if(memo[s2[j]-'a'] > table[s2[j]-'a'])
        				break;
        		}
        		if(j == i+s1.size())
        			tf = true;
        	}
        	for(j=0;j<26;j++){
        		memo[j] = 0;
        	}
        }

        return tf;
    }
};