



class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int i, res = 0, sum = 0;
        unordered_map<int, int> hash;

        for(i=0;i<nums.size();i++){
        	if(nums[i] == 0)
        		sum += -1;
        	else if(nums[i] == 1)
        		sum += 1;
        	if(sum == 0)
        		res = max(res, i+1);
        	else if(hash.find(sum) == hash.end())
        		hash[sum] = i;
        	else{
        		res = max(res, i-hash[sum]);
        	}
        }
        return res;
    }
};