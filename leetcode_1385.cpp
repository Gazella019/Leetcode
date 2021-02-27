


class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        
        int i, j, cnt = 0;
        bool sw;
        for(i=0;i<arr1.size();i++){
        	sw = false;
        	for(j=0;j<arr2.size();j++){
        		if(abs(arr1[i]-arr2[j]) <= d)
        			sw = true;
        	}
        	if(sw == false)
        		cnt ++;
        }

        return cnt;
    }
};