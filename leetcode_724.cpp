



class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int i, sum = 0, l = 0, r;

        for(i=0;i<nums.size();i++){
        	sum += nums[i];
        }

        for(i=0;i<nums.size();i++){
        	r = sum - nums[i] - l;
        	if(l == r)
        		return i;
        	l += nums[i];
        }
        return -1;
    }
};