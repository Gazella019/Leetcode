



class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if(nums.size() == 0)
        	return {};
        
        int i, cnt = 0;
        vector<int> res(nums.size(), -1);
        stack<int> st;
        while(cnt <= (2*nums.size())-2){
        	i = cnt % nums.size();
        	while(st.size() != 0 && nums[i] > nums[st.top()]){
        		res[st.top()] = nums[i];
        		st.pop();
        	}
        	st.push(i);
        	cnt++;
        }

        return res;
    }
};