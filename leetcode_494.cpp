


// sol 1 burte force

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
   		int count = 0, sum = 0;
   		find(nums, S, sum, 0, &count);
   		return count;
    }

    void find(vector<int>& nums, int S, int sum, int n, int *count){

    	if(n == nums.size()){
    		cout << "sum is " << sum << endl;
    		if(sum == S)
    			*count = *count + 1;
    		return;
    	}
    	int temp;
    	temp = sum + nums[n];
    	find(nums, S, temp, n+1, count);
    	temp = sum + (-1 * nums[n]);
    	find(nums, S, temp, n+1, count);
    }
};