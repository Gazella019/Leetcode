



class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int min = INT_MAX;
        for

    }

    bool canBuy(vector<int> combo, vector<int> need){
    	for(int i=0;i<need.size();i++){
    		if(combo[i] > need[i])
    			return false;
    	}
    	return true;
    }
};