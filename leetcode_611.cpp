


class Solution {
public:

    int triangleNumber(vector<int>& nums) {
        
        int cnt = 0, l, r;
        sort(nums.begin(), nums.end());
        for(int i=nums.size()-1;i>=2;i--){
        	l = 0, r = i-1;
        	while(l < r){
        		if(nums[l] + nums[r] > nums[i]){
        			cnt = cnt + r-l;
        			r --;
        		}
        		else{
        			l ++;
        		}
        	}
        }
        return cnt;
    }
};



class Solution {
public:
	int cnt = 0;
    int triangleNumber(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<int> v(3, 0);
        dfs(nums, v, 0, 0);

        return cnt;
    }

    void dfs(vector<int>& nums, vector<int>& v, int n, int pos){

    	if(pos == 3){
    		if(v[0] + v[2] > v[1] && v[1] + v[2] > v[0])
    			cnt ++;
    		return;
    	}
    	
    	for(int i=n;i<nums.size();i++){
    		if(pos == 2 && v[0] + v[1] <= nums[i]){
    			return;
    		}
    		v[pos] = nums[i];
    		dfs(nums, v, i+1, pos+1);
    	}

    }
};