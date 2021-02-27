



class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        
    	int start = 0, end, res = 0, distinct = 0;
    	unordered_map<int, int> hash;

    	for(end=0;end<s.size();end++){
    		if(hash[s[end]] == 0){
    			res = max(res, end-start);
    			while(distinct >= 2 && start < s.size()){
    				hash[s[start]] --;
    				if(hash[s[start]] == 0)
    					distinct --;
    				start ++;
    			}
    			hash[s[end]] += 1;
    			distinct ++;
    		}
    		else{
    			hash[s[end]] += 1;
    		}
    	}
    	res = max(res, end-start);
    	return res;
    }
};