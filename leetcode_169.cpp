



class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        stack<int> st;
        for(int i=0;i<nums.size();i++){
            if(st.size() == 0)
                st.push(nums[i]);
            else{
                if(nums[i] != st.top())
                    st.pop();
                else
                    st.push(nums[i]);
            }
        }

        return st.top();
    }
};


class Solution {
public:
    int majorityElement(vector<int>& nums) {
    	map<int, int> hash;
    	int i, max = 0, element;

    	for(i=0;i<nums.size();i++){
    		if(hash.find(nums[i]) == hash.end()){
    			hash[nums[i]] = 1;
    			if(hash[nums[i]] > max){
    				max = hash[nums[i]];
    				element = nums[i];
    			}
    		}
    		else{
    			hash[nums[i]] ++;
    			if(hash[nums[i]] > max){
    				max = hash[nums[i]];
    				element = nums[i];
    			}

    		}

    	}    
    	return element;
    }
};