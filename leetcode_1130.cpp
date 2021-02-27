



class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
    	
    	int dp[arr.size()][arr.size()] = {0};
    	int largest[arr.size()][arr.size()] = {0};
    	int i, j, k, t, large, num, sum;

    	for(i=0;i<arr.size();i++){
    		largest[i][i] = arr[i];
    	}
    	// k = 2
    	for(i=0;i+1<arr.size();i++){
    		j = i+1;
    		dp[i][j] = arr[i] * arr[j];
    		largest[i][j] = max(arr[i], arr[j]);
    	}

    	for(k=3;k<=arr.size();k++){
    		for(i=0;i+k-1<arr.size();i++){
    			j = i+k-1;
    			large = arr[i];
    			sum = INT_MAX;
    			for(t=i+1;t<=j;t++){
    				num = (largest[i][t-1] * largest[t][j]) + dp[i][t-1] + dp[t][j];
    				sum = min(num, sum);
    				large = max(large, arr[t]);
    			}
    			dp[i][j] = sum;
    			largest[i][j] = large;
    		}
    	}
    	return dp[0][arr.size()-1];
    }
};





// 搞錯題意
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int i, sum, num, lResult, rResult;
        vector<int> table(arr.size(), 0);
        vector<int> largeNum(arr.size(), 0);
        table[1] = (arr[0]*arr[1]);
        largeNum[1] = max(arr[0], arr[1]);

        for(i=2;i<arr.size();i++){
        	sum = (arr[i]*largeNum[i-1]) + table[i-1];

        	if(i%2 == 1){
        		num = table[i-2] + (largeNum[i-2]*max(arr[i], arr[i-1]));
        		table[i] = min(sum, num);
        	}
        	else
        		table[i] = sum;

        	largeNum[i] = max(largeNum[i-1], arr[i]);
        }


        lResult = table[arr.size()-1];

        reverse(arr.begin(), arr.end());

        table[1] = (arr[0]*arr[1]);
        largeNum[1] = max(arr[0], arr[1]);

        for(i=2;i<arr.size();i++){
        	sum = (arr[i]*largeNum[i-1]) + table[i-1];

        	if(i%2 == 1){
        		num = table[i-2] + (largeNum[i-2]*max(arr[i], arr[i-1]));
        		table[i] = min(sum, num);
        	}
        	else
        		table[i] = sum;

        	largeNum[i] = max(largeNum[i-1], arr[i]);
        }
        rResult = table[arr.size()-1];
        //cout << lResult << " " << rResult; 
        return min(lResult, rResult);
    }
};

