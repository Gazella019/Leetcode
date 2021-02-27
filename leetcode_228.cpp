


class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.size() == 0)
    		return res;
        string str;
        int i, start = 0;
        for(i=1;i<nums.size();i++){
        	if(nums[i] != nums[i-1]+1){
        		if(i-1 == start){
        			str = convert(nums[start]);
        			res.push_back(str);
        		}
        		else{
        			str = convert(nums[start]) + "->" + convert(nums[i-1]);
        			res.push_back(str);
        		}
        		start = i;
        	}
        }
        if(start == nums.size()-1){
        	str = convert(nums[start]);
        	res.push_back(str);
        }
        else{
        	str = convert(nums[start]) + "->" + convert(nums[i-1]);
        	res.push_back(str);
        }
        return res;
    }

    string convert(int num){
    	string str = "";
    	int x;
    	if(num == INT_MIN)
    		return "-2147483648";
    	if(num < 0)
    		x = -1 * num;
    	else
    		x = num;
    	string temp = " "; 
    	while((x/10) != 0){
    		temp[0] = (x%10)+'0';
    		str = temp + str;
    		x = x/ 10;
    	}
    	temp[0] = x + '0';
    	str = temp + str;
    	if(num < 0)
    		str = "-" + str;
    	return str;
    }
};