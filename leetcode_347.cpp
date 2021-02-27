




class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> hash;
        vector<int> v;
        vector<int> res;
        int i, count, time;

        for(i=0;i<nums.size();i++){

        	if(hash.find(nums[i]) == hash.end())
        		hash[nums[i]] = 1;
        	else
        		hash[nums[i]] = hash[nums[i]] + 1;
        }
        for(i=0;i<nums.size();i++){
        	if(hash[nums[i]] != 0){
        		v.push_back(hash[nums[i]]);
        		hash[nums[i]] = 0;
        	}
        }

        sort(v.begin(), v.end());
        i = v.size()-2;
        count = 1;
     	while(i>=0){
     		if(count == k){
     			time = v[i+1];
     			break;
     		}
     		if(v[i] != v[i+1]){
     			count = count + 1;
     		}
     		i--;
     	}
     	if(v.size() == 1)
     		time = v[0];
     	sort(nums.begin(), nums.end());
     	count = 1;

     	for(i=1;i<nums.size();i++){
     		if(nums[i] != nums[i-1]){
     			if(count >= time)
     				res.push_back(nums[i-1]);
     			count = 1;
     		}
     		else
     			count = count + 1;
     	}
     	if(count >= time)
     		res.push_back(nums[nums.size()-1]);

     	for(i=0;i<v.size();i++){
     		cout << v[i] << " ";
     	}
     	cout << endl;
     	cout << " time is " << time;
     	return res;
    }
};