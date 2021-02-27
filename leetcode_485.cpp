



class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i, sum = 0, max = 0;
        for(i=0;i<nums.size();i++){
        	if(nums[i] == 0)
        		sum = 0;
        	else{
        		sum = sum + 1;
        		if(sum > max)
        			max = sum;
        	}
        }
        return max;
    }
};