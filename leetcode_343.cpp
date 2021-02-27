
// Runtime: 0 ms, faster than 100.00% of C++
// Memory Usage: 8.3 MB, less than 93.33% of C++

class Solution {
public:
    int integerBreak(int n) {
    	if(n == 0)
    		return 1;
    	int i, j, maxVal, num;
    	int table[n+1] = {0};
    	table[1] = 1;

    	for(i=2;i<=n;i++){
    		maxVal = 0;
    		for(j=1;j<=i/2;j++){
    			num = max(table[j]*table[i-j], j*table[i-j]);
    			num = max(num, table[j]*(i-j));
    			num = max(num, j*(i-j));
    			if(num > maxVal)
    				maxVal = num;
    		}
    		table[i] = maxVal;
    	}
    	return table[n];
    }
};