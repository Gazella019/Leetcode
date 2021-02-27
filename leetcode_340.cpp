



class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        
        if(k == 0)
        	return 0;
        int i, start = 0, end, count = 0, res = 0;
        unordered_map<char, int> hash;

        for(i=0;i<s.size();i++){
        	if(hash[s[i]] == 0){
        		if(count == k){
        			res = max(res, i-start);
        			while(true){
        				hash[s[start]] -= 1;
        				if(hash[s[start]] == 0){
        					count --;
        					start++;
        					break;
        				}
        				start ++;
        			}
        		}
        		hash[s[i]] = 1;
        		count++;
        	}
        	else
        		hash[s[i]] = hash[s[i]] + 1;
        }
        res = max(res, i-start);
        return res;
    }
};


