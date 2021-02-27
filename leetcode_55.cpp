


class Solution {
public:
    bool canJump(vector<int>& nums) {
	
    	int i, maxDist = 0, n;

    	for(i=0;i<nums.size();i++){
    		if(i > maxDist)
    			return false;
    		maxDist = max(maxDist, i+nums[i]);
    	}
    	return true;
    }
};




class Solution {
public:
    bool canJump(vector<int>& nums) {
	
    	int i, n, now = 0, next = 0;
    	n = nums.size()-1;
    	vector<int> maxDistance(nums.size(), 0);

    	for(i=0;i<nums.size();i++){
    		maxDistance[i] = i + nums[i];
    	}

    	while(true){
    		now = next;
    		if(maxDistance[now] >= n)
    			return true;
    		for(i=now;i<=maxDistance[now];i++){
    			if(maxDistance[i] > maxDistance[next])
    				next = i;
    		}
    		if(now == next)
    			return false;
    	}
    	
    	return false;
    }
};


// Slower 

class Solution {
public:
    bool canJump(vector<int>& nums) {
	
		if(nums.size() == 1)
			return true;
		if(nums[0] == 0)
			return false;

    	int i, j;
    	vector<int> dp(nums.size(), 0);

    	dp[0] = 1;

    	for(i=0;i<nums.size();i++){
    		if(dp[i] == 1){
    			for(j=1;j<=nums[i];j++){
    				if(i+j >= nums.size())
    					break;
    				if()
    				dp[i+j] = 1;
    			}
    		}
    	}

    	for(i=0;i<nums.size();i++){
    		cout << dp[i] << " ";
    	}

    	if(dp[nums.size()-1] == 0)
    		return false;
    	return true;
    }
};