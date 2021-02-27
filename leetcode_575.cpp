


class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        
        unordered_map<int, int> hash;
        int i, cnt = 0;

        for(i=0;i<candies.size();i++){
        	if(hash.find(candies[i]) == hash.end()){
        		hash[candies[i]] += 1;
        		cnt ++;
        	}
        }
        if(cnt <= candies.size()/2)
        	return cnt;
        return candies.size()/2;
    }
};