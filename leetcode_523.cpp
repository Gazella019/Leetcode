

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int i, sum = 0, index = 0;
        unordered_map<int, int> hash;
        hash[0] = -1;

        for(i=0;i<nums.size();i++){
            sum += nums[i];
            if(k != 0)
                index = sum%k;
            else
                index = sum;
            if(hash.find(index) == hash.end())
                hash[index] = i;
            else{
                if(i-hash[index] > 1)
                    return true;
            }
        }

        return false;
    }
};



class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int i, j, sum;
        for(i=0;i<nums.size();i++){
        	sum = nums[i];
        	for(j=i+1;j<nums.size();j++){
        		sum = sum + nums[j];
        		if(k == 0){
        			if(sum == 0)
        				return true;
        		}
        		else if(sum%k == 0)
        			return true;
        	}
        }
        return false;
    }
};