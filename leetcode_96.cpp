


class Solution {
public:
    int numTrees(int n) {
        int table[n+1], i, j, sum;
        table[0] = 1;
        table[1] = 1;
        // table[i]
        for(i=2;i<=n;i++){
        	sum = 0;
        	// j 是 root
        	for(j=1;j<=i;j++){
        		sum = sum + table[j-1] * table[i-j];
        	}
        	table[i] = sum;
        }
        for(i=1;i<=n;i++){
        	cout << table[i] << " ";
        }
        return 	table[n];
    }	
};