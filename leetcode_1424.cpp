

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        
        vector<vector<int>> v;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
        	for(int j=0;j<nums[i].size();j++){
        		v.push_back({i+j, i, nums[i][j]});
        	}
        }
        sort(v.begin(), v.end(), [&](vector<int>&a, vector<int>&b){
        	if(a[0] == b[0])
        		return a[1] > b[1];
        	return a[0] < b[0];
        });

        for(int i=0;i<v.size();i++){
        	res.push_back(v[i][2]);
        }

        return res;
    }
};


class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        
        unordered_map<int, vector<int>> hash;
        vector<int> res;
        int mx = 0;
        for(int i=0;i<nums.size();i++){
        	for(int j=0;j<nums[i].size();j++){
        		hash[i+j].push_back(nums[i][j]);
        		mx = max(mx, i+j);
        	}
        }
     	
     	for(int i=0;i<=mx;i++){
     		vector<int> temp;
     		temp = hash[i];
     		for(int j=temp.size()-1;j>=0;j--){
     			res.push_back(temp[j]);
     		}
     	}   

     	return res;
    }
};