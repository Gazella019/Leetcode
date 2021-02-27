


class Solution {
public:
    int findMin(vector<int>& nums) {
    	
        int l, r, mid;
        l = 0, r = nums.size()-1;
        while(l <= r && nums[l] > nums[r]){

            mid = (l+r) / 2;
                       
            if(mid != 0 && nums[mid-1] > nums[mid])
                return nums[mid];
            if(nums[mid] >= nums[l])
                l = mid+1;
            else if(nums[mid] < nums[l])
                r = mid-1;
        }

    	return nums[l];
    }

};