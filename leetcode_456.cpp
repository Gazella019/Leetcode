



class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size() <= 2)
        	return false;
        int i, mn = nums[0], n;
        n = nums.size();
        vector<int> v(n, INT_MAX);
        vector<int> lgreater(n, -1);
        stack<int> st;

        for(i=1;i<n;i++){
        	if(nums[i] >= mn)
        		v[i] = mn;
        	mn = min(mn, nums[i]);
        }
        
        for(i=n-1;i>=0;i--){
        	while(st.size() != 0 && nums[i] > nums[st.top()]){
        		lgreater[st.top()] = i;
        		st.pop();
        	}
        	st.push(i);
        }

        for(i=0;i<n;i++){
        	if(lgreater[i] != -1 && v[lgreater[i]] < nums[i])
        		return true;
        }
        return false;
    }
};