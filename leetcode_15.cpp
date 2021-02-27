



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
     	
     	int i, l, r, sum;
     	vector<vector<int>> res;
     	sort(nums.begin(), nums.end());

     	for(i=0;i<nums.size();i++){
     		
     		if(i > 0 && nums[i] == nums[i-1])
     			continue;
     		l = i+1, r = nums.size()-1;

     		while(l < r){
     			sum = nums[i] + nums[l] + nums[r];
     			if(sum == 0){
     				res.push_back({nums[i], nums[l], nums[r]});
     				while(l+1 < nums.size() && nums[l] == nums[l+1])
     					l++;
     				while(r-1>=0 && nums[r] == nums[r-1])
     					r--;
     				l++, r--;
     			}
     			if(sum < 0)
     				l++;
     			if(sum > 0)
     				r--;
     		}

     	}
     	return res;
    }
};