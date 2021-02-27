



class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
    	vector<int> res;
        int i, total = 0, sum = 0;

        for(i=0;i<nums.size();i++){
        	total += nums[i];
        }

        sort(nums.begin(), nums.end(), greater<int>());

        for(i=0;i<nums.size();i++){
        	sum += nums[i];
        	res.push_back(nums[i]);
        	if(sum > total-sum){
        		return res;
        	}
        }
        return res;
    }
};