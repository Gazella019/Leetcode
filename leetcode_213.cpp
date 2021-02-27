

// Runtime: 0 ms, faster than 100.00% of C++ 
// Memory Usage: 8.6 MB, less than 91.43% of C++ 

class Solution {
public:
    int rob(vector<int>& nums) {
    	if(nums.size() == 0)
    		return 0;
    	else if(nums.size() == 1)
    		return nums[0];
    	else if(nums.size() == 2)
    		return max(nums[0], nums[1]);
    	
    	int i, res;
    	int table[nums.size()];
        table[0] = nums[0];
        table[1] = max(nums[0], nums[1]);
        for(i=2;i<nums.size()-1;i++){
        	table[i] = max(table[i-1], table[i-2]+nums[i]);
        }
        res = table[nums.size()-2];

        table[0] = 0;
        table[1] = max(0, nums[1]);
        for(i=2;i<nums.size();i++){
        	table[i] = max(table[i-1], table[i-2]+nums[i]);
        }
        if(res < table[nums.size()-1])
        	res = table[nums.size()-1];
       return res;
    }
};