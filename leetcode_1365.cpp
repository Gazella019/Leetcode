

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        int i, j, cnt;
        vector<int> res(nums.size(), 0);
        for(i=0;i<nums.size();i++){
            cnt = 0;
            for(j=0;j<nums.size();j++){
                if(nums[j] < nums[i])
                    cnt ++;
            }
            res[i] = cnt;
        }

        return res;
    }
};


class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        int i, cnt;
        unordered_map<int, int> hash;	
        vector<int> res(nums.size(), 0);
        vector<int> v;
        v = nums;
        sort(v.begin(), v.end());
        cnt = 0;
        hash[v[0]] = cnt;
        for(i=1;i<v.size();i++){
        	cnt ++;
        	if(v[i] == v[i-1])
        		continue;
        	hash[v[i]] = cnt;
        }

        for(i=0;i<nums.size();i++){
        	res[i] = hash[nums[i]];
        }

        return res;
    }
};