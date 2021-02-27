



class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        vector<int> res;
        int x = 0, y = 1, xc = 0, yc = 0;

        for(int i=0;i<nums.size();i++){
        	if(nums[i] == x)
        		xc ++;
        	else if(nums[i] == y)
        		yc ++;
        	else if(xc == 0){
        		x = nums[i];
        		xc = 1;
        	}
        	else if(yc == 0){
        		y = nums[i];
        		yc = 1;
        	}
        	else
        		xc --, yc --;
        }
        xc = 0 , yc = 0;
        for(int i=0;i<nums.size();i++){
        	if(nums[i] == x)
        		xc ++;
        	if(nums[i] == y)
        		yc ++;
        }

        if(xc > nums.size()/3)
        	res.push_back(x);
        if(yc > nums.size()/3)
        	res.push_back(y);
        return res;
    }
};