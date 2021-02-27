



class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        
        int i, j;
        unordered_map<int, int> hash;

        if(nums.size()%k != 0)
        	return false;
        sort(nums.begin(), nums.end());

        for(i=0;i<nums.size();i++){
        	hash[nums[i]] += 1;
        }

        for(i=0;i<nums.size();i++){
        	cout << nums[i] << endl;
        	if(hash[nums[i]] == 0)
        		continue;

        	if(hash[nums[i]] >= 1){
        		for(j=nums[i];j<=nums[i]+k-1;j++){
        			if(hash[j] <= 0)
        				return false;
        			hash[j] --;
        		}
        	}
        }

        return true;
    }
};