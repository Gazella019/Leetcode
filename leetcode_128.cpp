



class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int, int> hash;
        int i, res = 0, current, count;

        for(i=0;i<nums.size();i++){
        	hash[nums[i]] = 1;
        }

        for(i=0;i<nums.size();i++){
        	if(hash.find(nums[i]-1) == hash.end()){
        		current = nums[i]+1;
        		count = 1;
        		while(hash.find(current) != hash.end()){
        			current = current + 1;
        			count ++;
        		}
        		if(count > res)
        			res = count;
        	}
        }

        return res;
    }
};



class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int, int> hash;
        vector<int> v;
        int count = 0;
        int res = 0, temp;

        for(int i=0;i<nums.size();i++){

        	if(hash[nums[i]] != end())
        		continue;
        	
        	if(hash[nums[i]-1] != end() && hash[nums[i]+1] != end()){

        	} 

        }



        return res;

    }
};



class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int, int> hash;
        vector<int> v;
        int count = 0;
        int res = 0, temp;

        for(int i=0;i<nums.size();i++){

        	if(hash.find(nums[i]) != hash.end())
        		continue;
        	if(hash.find(nums[i]-1) != hash.end() && hash.find(nums[i]+1) != hash.end()){

        		temp = v[hash[nums[i]-1]];
        		v[hash[nums[i]-1]] = v[hash[nums[i]-1]] + 1 + v[hash[nums[i]+1]];
        		v[hash[nums[i]+1]] = v[hash[nums[i]+1]] + 1 + temp;
        		hash[nums[i]] = hash[nums[i]-1];
        	}

        	else if(hash.find(nums[i]-1) != hash.end()){
        		v[hash[nums[i]-1]] += 1;
        		hash[nums[i]] = hash[nums[i]-1];
        	}
        	else if(hash.find(nums[i]+1) != hash.end()){
        		v[hash[nums[i]+1]] += 1;
        		hash[nums[i]] = hash[nums[i]+1];
        	}

        	else{
        		hash[nums[i]] = count;
        		v.push_back(1);
        		count ++;  
        	}

        }

        for(int i=0;i<v.size();i++){
        	cout << v[i] << " ";
        	if(v[i] > res)
        		res = v[i];
        }

        return res;

    }
};