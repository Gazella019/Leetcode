

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        // mn1 > mn2
        int i, mn1 = INT_MAX, mn2 = INT_MAX;

        for(i=0;i<nums.size();i++){
        	if(nums[i] > mn1 && nums[i] > mn2)
        		return true;
        	if(nums[i] > mn2 && nums[i] < mn1)
        		mn1 = nums[i];
        	if(nums[i] < mn2 && nums[i] < mn1)
        		mn2 = nums[i];
        }	

        return false;
    }
};



class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int i, j;
        vector<int> dp(nums.size(), 1);

        for(i=0;i<nums.size();i++){
        	for(j=i-1;j>=0;j--){
        		if(nums[i] > nums[j]){
        			dp[i] = max(dp[i], dp[j]+1);
        		}
        	}
        	if(dp[i] >= 3)
        		return true;
        }
        
        return false;
    }
};



class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        if(nums.size() <= 2)
        	return false;
        int i, j;
        vector<vector<int>> dp(nums.size(), vector<int> (nums.size(), 0));
        vector<int> sorted;
        sorted = nums;
        sort(sorted.begin(), sorted.end());

        if(nums[0] == sorted[0])
        	dp[0][0] = 1;

        for(i=1;i<nums.size();i++){
        	if(nums[0] == sorted[i])
        		dp[0][i] = 1;
        	else
        		dp[0][i] = dp[0][i-1];
        	if(nums[i] == sorted[0])
        		dp[i][0] = 1;
        	else
        		dp[i][0] = dp[i-1][0];
        }

        for(i=1;i<nums.size();i++){
        	for(j=1;j<nums.size();j++){
        		if(sorted[j] == sorted[j-1] || nums[i] == nums[i-1] || nums[i] != sorted[j])
        			dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        		else
        			dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + 1;
        		if(dp[i][j] >= 3)
        			return true;
        	}
        }

        for(i=0;i<nums.size();i++){
        	for(j=0;j<nums.size();j++){
        		cout << dp[i][j] << " ";
        	}
        	cout << endl;
        }

        return false;
    }
};