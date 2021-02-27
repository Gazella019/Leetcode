


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        if(nums.size() == 0)
        	return {};

    	int i, maxVal = INT_MIN, offset;
    	vector<int> table(nums.size(), INT_MIN);
    	vector<int> res;

    	for(i=0;i<=table.size()-k;i++){

    		table[i] = max(table[i], nums[i]);

    		for(offset=i+1;offset<i+k;offset++){
    			if(!isValid(nums, offset))
    				break;
    			if(table[offset] > nums[i])
    				break;
    			table[offset] = nums[i];
    		}
    	}

    	return table;

    }

    bool isValid(vector<int>& nums, int num){
    	if(num < 0 || num >= nums.size())
    		return false;
    	return true;
    }
};