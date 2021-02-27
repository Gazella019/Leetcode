



class Solution {
public:

    bool canPartitionKSubsets(vector<int>& nums, int k){

    	int i, j, sum = 0, target;
        vector<int> used(nums.size(), 0);
        vector<int> v;

        if(nums.size() < k)
        	return false;
        for(i=0;i<nums.size();i++){
        	sum = sum + nums[i];
        }

        if(sum % k != 0)
        	return false;
        target = sum / k;

        return canPartition(nums, used, 0, k, 0, target);
    }

    bool canPartition(vector<int>& nums, vector<int>& used, int n, int k, int sum, int target){
    	if(k == 1)
    		return true;
    	if(sum > target)
    		return false;
    	if(sum == target)
    		return canPartition(nums, used, 0, k-1, 0, target);

    	for(int i=n;i<nums.size();i++){
    		if(used[i] == 0){
    			used[i] = 1;
    			if(canPartition(nums, used, i+1, k, sum+nums[i], target))
    				return true;
    			used[i] = 0;
    		}
    	}
    	return false;
    }
};




class Solution {
public:

	bool canMake;

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int i, j, sum = 0, target;
        vector<int> used(nums.size(), 0);
        vector<int> v;

        if(nums.size() < k)
        	return false;

        for(i=0;i<nums.size();i++){
        	sum = sum + nums[i];
        }
        if(sum % k != 0)
        	return false;
        target = sum / k;

        for(j=1;j<=k;j++){
	        canMake = false;
		    traversal(nums, used, v, 0, 0, target);
		    //if(canMake == false)
		    	//return false;
		    for(int i=0;i<used.size();i++){
    			cout << used[i] << " ";
    		}
    		cout << endl;
		}
        return true;
    }

    void traversal(vector<int>& nums, vector<int>& used, vector<int>& v, int n, int sum, int target){

    	if(sum == target){
    		for(int i=0;i<v.size();i++){
    			used[v[i]] = 2;
    		}
    		canMake = true;
    		return;
    	}
    	if(n == nums.size() || sum > target)
    		return;

    	if(used[n] == 0){
    		used[n] = 1;
    		v.push_back(n);
    		traversal(nums, used, v, n+1, sum+nums[n], target);
    		if(used[n] == 1)
    			used[n] = 0;
    		v.pop_back();
    	}
    	if(canMake == true)
    		return;
    	traversal(nums, used, v, n+1, sum, target);
    }
};

