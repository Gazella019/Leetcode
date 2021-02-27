


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> res(nums1.size(), 0);
       	stack<int> st;
       	unordered_map<int, int> hash;

       	for(int i=0;i<nums2.size();i++){
       		while(st.size() != 0 && nums2[i] > st.top()){
       			hash[st.top()] = nums2[i];
       			st.pop();
       		}
       		st.push(nums2[i]);
       	}

       	while(st.size() != 0){
       		hash[st.top()] = -1;
       		st.pop();
       	}

       	for(int i=0;i<res.size();i++){
       		res[i] = hash[nums1[i]];
       	}
       	return res;
    }
};