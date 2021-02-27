



class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int i, n, temp;
        for(i=0;i<nums.size();i++){
			if(nums[i] == i+1)
				continue;   
			while(nums[i] >= 1 && nums[i] <= nums.size() && nums[i] != nums[nums[i]-1]){
				swap(nums[i], nums[nums[i]-1]);
			}     	
        }

        for(i=0;i<nums.size();i++){
        	if(i+1 != nums[i])
        		return i+1;
        }

    	return nums.size() + 1;
    }
};



class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int i;
    	unordered_map<int, int> hash;

    	for(i=0;i<nums.size();i++){
    		if(nums[i] > 0)
    			hash[nums[i]] = 1;
    	}
    	i = 1;
    	while(true){
    		if(i > 0 && hash.find(i) == hash.end())
    			return i;
    		i++;
    	}

    	return 0;
    }
};