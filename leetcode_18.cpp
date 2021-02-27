


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        if(nums.size() < 4)
        	return {};
        vector<vector<int>> res;
        int i, j, sum, base, l, r;

        sort(nums.begin(), nums.end());
        for(i=0;i<=nums.size()-4;i++){
        	if(i > 0 && nums[i] == nums[i-1])
        		continue;
        	base = nums[i];

        	for(j=i+1;j<=nums.size()-3;j++){
        		if(j > i+1 && nums[j] == nums[j-1])
        			continue;
        		l = j+1, r = nums.size()-1;
        		while(l < r){
        			sum = base + nums[j] + nums[l] + nums[r];
        			if(sum == target){
        				res.push_back({base, nums[j], nums[l], nums[r]});
        				while(l+1 <nums.size() && nums[l] == nums[l+1])
        					l++;
        				while(r-1 >= 0 && nums[r] == nums[r-1])
        					r--;
        				l++, r--;
        			}
        			else if(sum < target)
        				l++;
        			else
        				r--;
        		}
        	}
        }
        return res;
    }
};