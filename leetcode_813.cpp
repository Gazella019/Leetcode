




class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
    	int size, i, j;
    	double sum, max = 0;
    	size = A.size();
    	vector<vector<double>> table(size, vector<double> (size, 0));
    	vector<double> nums(K+1, 0);


    	for(i=0;i<size;i++){
    		sum = 0;
    		for(j=i;j<size;j++){
    			sum = sum + A[j];
    			table[i][j] = sum / (j-i+1);
    		}
    	}
    	sum = 0;
    	dfs(nums, table, -1, 1, K, sum, &max);

    	//for(i=0;i<nums.size();i++){
    	//	cout << nums[i] << " ";
    	//}
    	return max;
    }


    void dfs(vector<double>& nums, vector<vector<double>> table, int l, int n, int K, double sum, double* max){
    	if(n == K){
    		sum = sum + table[l+1][table.size()-1];
    		if(sum > *max){
    			*max = sum;
    			//for(int z=0;z<nums.size();z++){
    			//	cout << nums[z] << " ";
    			//}
    			//cout<< " sum is " << sum << endl;
    		}
    		return;
    	}
    	double temp;
    	for(int r=l+1;r<table.size()-(K-n);r++){
    		nums[n] = table[l+1][r];
    		temp = sum + table[l+1][r];
    		dfs(nums, table, r, n+1, K, temp, max);
    	}
    }
};




class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
    	int size, i, j, k;
    	double sum = 0, max = 0;
    	size = A.size();
    	double dp[size][K+1] = {0};
    	double table[size][size] = {0};

    	for(i=0;i<size;i++){
    		sum = 0;
    		for(j=i;j<size;j++){
    			sum = sum + A[j];
    			table[i][j] = sum / (j-i+1);
    		}
    	}
    	sum = 0;
    	for(i=0;i<size;i++){
    		sum = sum + A[i];
    		dp[i][1] = sum / (i+1); 
    	}
    	for(i=0;i<size;i++){
    		for(k=2;k<=K;k++){
    			if(i+1 >= k){
    				max = 0;
    				for(j=i;j>=k-1;j--){
    					if(table[j][i] + dp[j-1][k-1] > max)
    						max = table[j][i] + dp[j-1][k-1];
    				}
    				dp[i][k] = max;
    			}
    		}
    	}
    	return dp[A.size()-1][K];
    }
};