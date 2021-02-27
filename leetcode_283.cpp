


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i, start = 0;

        for(i=0;i<nums.size();i++){
        	if(nums[i] != 0){
        		nums[start] = nums[i];
        		if(start != i)
        			nums[i] = 0;
        		start = start + 1;
        	}
        }
    }
};