



class Solution {
public:
    int minStartValue(vector<int>& nums) {
    	int res, mn = nums[0];
    	int sum = nums[0];
    	for(int i=1;i<nums.size();i++){
    		sum += nums[i];
    		mn = min(mn, sum);
    	}
    	
    	if(mn >= 1)
    		return 1;
    	return abs(mn)+1;
    }
};