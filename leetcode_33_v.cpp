


// 先找出反轉的點

class Solution {
public:
    int search(vector<int>& nums, int target){

        int l = 0, r = nums.size()-1, mid = 0;        
        int inversePoint = -1;

        // 取得反轉的點
        while(1){

            mid = (l+r)/2;

            if(nums[mid] > nums[r])
                l = mid + 1;
            else if(nums[l] > nums[mid])
                r = mid - 1;
            // inverse at this point
            else if(l != 0 && nums[l] < nums[l-1]){
                inversePoint = l;
                break;
            }
            else if(r != nums.size()-1 && nums[r] > nums[r+1]){
                inversePoint = r;
                break;
            }

        }

        cout << "is " << nums[inversePoint] << endl;
        
        if(target == nums[inversePoint])
            return inversePoint;
        else if(nums[inversePoint-1] >= target && target >= nums[0]){
            r = 0;
            l = inversePoint - 1;
        }
        else if(target <= nums[nums.size()-1] && target >= nums[inversePoint]){
            r = inversePoint + 1;
            l = nums.size() - 1; 
        }
        else
            return -1;

        // Binary search
        while(r>=l){

            mid = (r+l) / 2;
            if(target == nums[mid])
                return mid;
            if(target > nums[mid])
                r = mid + 1;
            if(target < nums[mid])
                l = mid - 1;
        }
        return -1;
    }
};