



class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

    	vector<int> res;
        int l = 0, r = numbers.size()-1;

        while(l < r){
        	if(numbers[l]+numbers[r] > target)
        		r--;
        	if(numbers[l]+numbers[r] < target)
        		l++;
        	if(numbers[l]+numbers[r] == target){
        		res.push_back(l+1);
        		res.push_back(r+1);
        		break;
        	}
        }
        return res;
    }
};