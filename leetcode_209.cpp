


class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int i, l = 0, r = nums.size()-1, sum = 0, count;

        for(i=0;i<nums.size();i++){
        	sum = sum + nums[i];
        }
        if(sum < s)
        	return 0;
        count = nums.size();
        while(l <= r && sum >= s){
        	if(nums[l] > nums[r]){
        		sum = sum - nums[r];
        		r = r - 1;
        	}
        	else{
        		sum = sum - nums[l];
        		l = l + 1;
        	}
        }
        cout << l << " " << r << endl;
        cout << sum;
        //cout << nums[l] << " " << nums[r];
        return r - l + 1 + 1;
    }
};