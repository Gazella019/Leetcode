


class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        
        int i;
        unordered_map<int, int> hash;
        
        for(i=0;i<arr.size();i++){
        	hash[arr[i]] += 1;
        }

        for(i=0;i<arr.size();i++){
        	if(arr[i]%2 == 0 && arr[i] != 0){
        		if(hash[arr[i]/2]){
        			return true;
        		}
        	}
        }
        if(hash[0] >= 2)
        	return true;
        return false;
    }
};


class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        
        int i, j;
        for(i=0;i<arr.size();i++){
            for(j=0;j<arr.size();j++){
                if(i != j && arr[i] == arr[j]*2)
                    return true;
            }
        }
        
        return false;
    }
};