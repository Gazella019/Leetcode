


class Solution {
public:
    int change(int amount, vector<int>& coins) {
    	if(coins.size() == 0){
    		if(amount == 0)
    			return 1;
    		return 0;
    	}
    	int table[amount+1][coins.size()] = {0};
    	int i, j, coin;
    	coin = coins[0];
    	table[0][0] = 1;
    	for(j=1;j<=amount;j++){
    		if(j-coin >= 0)
    			table[j][0] = table[j-coin][0];
    	}
    	for(i=1;i<coins.size();i++){
    		coin = coins[i];
    		table[0][i] = 1;
    		for(j=1;j<=amount;j++){
    			if(j-coin >= 0)
    				table[j][i] = table[j][i-1] + table[j-coin][i];
    			else
    				table[j][i] = table[j][i-1];
    		}
    	}

    	for(i=0;i<=amount;i++){
    		for(j=0;j<coins.size();j++){
    			cout << table[i][j] << " ";
    		}
    		cout << endl;
    	}

    	return table[amount][coins.size()-1];
    }
};



// DFS sol time exceed
class Solution {
public:
    int change(int amount, vector<int>& coins) {
    	int count = 0, sum = 0, n = 0;
    	dfs(amount, coins, n, sum, &count);
    	return count;
    }

    void dfs(int amount, vector<int>& coins, int n, int sum, int* count){
    	if(sum == amount){
    		*count = *count + 1;
    		return;
    	}
    	if(sum > amount || n >= coins.size())
    		return;
    	int i, val;
    	for(i=0;i<=amount/coins[n];i++){
    		val = coins[n] * i;
    		dfs(amount, coins, n+1, sum+val, count);
    	}
    }
};
