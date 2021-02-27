





class Solution {
public:
    int findLucky(vector<int>& arr) {

    	int res = -1;
    	unordered_map<int, int> hash;

    	for(int i=0;i<arr.size();i++){
    		hash[arr[i]] += 1;
    	}

    	for(auto& it:hash){
    		if(it.second == it.first){
    			res = max(res, it.first);
    		}
    	}

    	return res;
    }
};