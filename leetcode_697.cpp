



class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        
        int i, rank = 1, res = 50000;
        unordered_map<int, vector<int>> hash;

        for(i=0;i<nums.size();i++){
        	if(hash.find(nums[i]) == hash.end()){
        		hash[nums[i]].push_back(1);
        		hash[nums[i]].push_back(i);
        		hash[nums[i]].push_back(0);
        	}
        	else{
        		hash[nums[i]][0] += 1;
        		hash[nums[i]][2] = i;
        		rank = max(rank, hash[nums[i]][0]);
        	}
        }

        if(rank == 1)
        	return 1;

        for(auto& it:hash){
        	if(it.second[0] == rank){
        		res = min(res, it.second[2]-it.second[1]+1);
        	}
        }

        return res;
    }
};


class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        
        int i, rank = 1, res = 50000;
        vector<vector<int>> table(50000, vector<int>(3, -1));

        for(i=0;i<nums.size();i++){
        	if(table[nums[i]][0] == -1){
        		table[nums[i]][0] = 1;
        		table[nums[i]][1] = i;
        	}
        	else{
        		table[nums[i]][0] += 1;
        		table[nums[i]][2] = i;
        		rank = max(rank, table[nums[i]][0]);
        	}
        }

        if(rank == 1)
        	return 1;
        for(i=0;i<table.size();i++){
        	if(table[i][0] == rank){
        		res = min(res, table[i][2]-table[i][1]+1);
        	}
        }
        return res;
    }
};