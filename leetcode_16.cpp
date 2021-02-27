



class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        bool ok = false;
        int i, r, l, sum, res;

        sort(nums.begin(), nums.end());

        for(i=0;i+2<nums.size();i++){
        	l = i+1, r = nums.size()-1;
        	while(l < r){
        		sum = nums[i] + nums[l] + nums[r];
        		if(ok == false){
        			res = sum;
        			ok = true;
        		}
        		if(abs(res-target) > abs(sum-target))
        			res = sum;
        		if(sum == target)
        			return target;
        		if(sum > target)
        			r --;
        		else if(sum < target)
        			l ++;
        	}
        }
        return res;
    }
};