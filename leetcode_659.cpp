


class Solution {
public:
    bool isPossible(vector<int>& nums) {
        
        // num, cnt
        bool canInsert;
        int i, j, mn;
        vector<vector<int>> table;

        for(i=0;i<nums.size();i++){
        	mn = 0, canInsert = false;
        	for(j=0;j<table.size();j++){
        		if(nums[i]-table[j][0] > 1 && table[j][1] < 3)
        			return false;
        		if(nums[i]-table[j][0] == 1){
        			canInsert = true;
        			if(table[mn][1] > table[j][1])
        				mn = j;
        		}
        	}
        	if(canInsert == true){
        		table[mn][0] = nums[i];
        		table[mn][1] += 1;
        	}
        	else
        		table.push_back({nums[i], 1});
        }

        for(i=0;i<table.size();i++){
        	if(table[i][1] < 3)
        		return false;
        }

        return true;
    }
};


class Solution {
public:
    bool isPossible(vector<int>& nums) {
        
        int i;
        unordered_map<int, int> table;
        unordered_map<int, int> need;

        for(i=0;i<nums.size();i++){
        	table[nums[i]] += 1;
        }
        
        for(i=0;i<nums.size();i++){
        	cout << nums[i] << " " << table[nums[i]] << endl;
        	if(table[nums[i]] == 0)
        		continue;
        	if(need[nums[i]] > 0){
        		table[nums[i]] --;
        		need[nums[i]] --;
        		need[nums[i]+1] ++;
        	}
        	else{
        		if(table[nums[i]+1] > 0 && table[nums[i]+2] > 0){
        			table[nums[i]] --;
        			table[nums[i]+1] --;
        			table[nums[i]+2] --;
        			need[nums[i]+3] ++;
        		}
        		else
        			return false;
        	}
        }
        return true;
    }
};