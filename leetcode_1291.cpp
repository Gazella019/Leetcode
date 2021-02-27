


class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        int i;
        for(i=0;i<=9;i++){
        	traversal(res, 0, i, low, high);
        }

        sort(res.begin(), res.end());
        return res;
    }

    void traversal(vector<int>& res, int num, int digit, int low, int high){

    	if(digit == 9)
    		return;
    	int i, temp;
    	temp = (num*10) + digit+1;
    	if(temp >= low && temp <= high){
    		res.push_back(temp);
    	}
    	else if(temp > high)
    		return;
    	traversal(res, temp, digit+1, low, high);
    }
};