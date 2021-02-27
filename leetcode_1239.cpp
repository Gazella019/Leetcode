



class Solution {
public:
    int maxLength(vector<string>& arr) {
        map<char,int> hash;
        int max = 0;
        combination(arr, hash, &max, 0);
        return max;
    }


    void combination(vector<string>& arr, map<char,int>& hash, int* max, int n){
    	if(n >= arr.size()){
    		int count = 0;
    		for(auto p:hash){
    			if(p.second == 1)
    				count = count + 1;
    		}
    		if(count > *max)
    			*max = count;
    		return;
    	}
    	int i;
    	bool canAdd = true;
    	for(i=0;i<arr[n].size();i++){
    		hash[arr[n][i]] += 1;
    		if(hash[arr[n][i]] >= 2)
    			canAdd = false;		
    	}
    	if(canAdd == false){
    		for(i=0;i<arr[n].size();i++){
    			hash[arr[n][i]] -= 1;
    		}
    	}
    	combination(arr, hash, max, n+1);
    	if(canAdd){
    		for(i=0;i<arr[n].size();i++){
    			hash[arr[n][i]] = 0;
    		}
    	}
    	combination(arr, hash, max, n+1);
    }
};