

// Runtime: 180 ms, faster than 87.90% of C++ 
// Memory Usage: 20.6 MB, less than 100.00% of C++ 

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
    	int i, j, oddNum = 0, res = 0, count = 0;
    	vector<int> v;
    	for(i=0;i<nums.size();i++){
    		if(nums[i]%2 == 0)
    			count++;
    		if(nums[i]%2 == 1){
    			oddNum ++;
    			v.push_back(count);
    			count = 0;
    		}
    	}
    	v.push_back(count);

    	if(oddNum < k)
    		return 0;
    	i = k;
    	while(i <= v.size()-1){
    		res = res + (v[i]+1)*(v[i-k]+1);
    		i++;
    	}
    	return res;   
    }
};


// O(N^2)
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
    	int i, j, oddNum, count = 0;

    	for(i=0;i<nums.size();i++){
    		oddNum = 0;
    		for(j=i;j<nums.size();j++){
    			if(nums[j]%2 == 1)
    				oddNum ++;
    			if(oddNum == k)
    				count ++;
    			if(oddNum > k)
    				break;
    		}
    	}
    	return count;   
    }
};