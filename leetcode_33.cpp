



// 先從基本的 Binary search 下手
// [4,5,1,3]
// [3,4,5,1] 分不出來要往哪裡走

class Solution {
public:
    int search(vector<int>& nums, int target) {


    	int l = 0, r = nums.size()-1, mid;

    	while(r>=l){

    		mid = (l+r) / 2;

    		if(nums[mid] == target)
    			return mid;

    		else if(nums[mid] > target){
    			// 在這裡有被反轉過, 防止超出範圍

    			if(mid != nums.size() -1 && nums[mid+1] < nums[mid]){
    				if(target <= nums[r])
    					l = mid + 1;
    				else
    					r = mid - 1;
    			}
    			else
    				r = mid - 1;
    		}
    		else if(nums[mid] < target){
    			// 在這裡有被反轉過, 防止超出範圍
    			if(mid != 0 && nums[mid-1] > nums[mid]){
    				if(nums[l]<=target)
    					r = mid -1;
    				else
    					l = mid + 1;
    			}
    			else
    				l = mid + 1;
    		}
    	}
    	return -1;
    }
};