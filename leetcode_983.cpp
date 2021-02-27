

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int i, d, num, prev;
        unordered_map<int, int> hash;
        vector<int> dp(366, 0);
        
        for(i=0;i<days.size();i++){
            hash[days[i]] += 1;
        }

        for(i=1;i<=365;i++){
            if(hash.find(i) == hash.end())
                dp[i] = dp[i-1];
            else{
                dp[i] = min(dp[max(0, i-7)]+costs[1], dp[max(0, i-30)]+costs[2]);
                dp[i] = min(dp[i], dp[max(0, i-1)]+costs[0]);
            }
        }
        return dp[365];
    }

};




class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        vector<int> dp(days.size()+1, INT_MAX);
        dp[0] = 0;
        for(int i=0;i<days.size();i++){
            cal(days, costs, dp, i);
            cout << dp[i] << " ";
        }

        return dp[days.size()];
    }

    void cal(vector<int>& days, vector<int>& costs, vector<int>& dp, int n){

        for(int i=n-1;i>=0;i--){

            if(days[n]-days[i]+1 > 30)
                break;
            if(days[n]-days[i]+1 <= 7){
                dp[n+1] = min(dp[n+1], dp[i]+costs[1]);
            }
            if(days[n]-days[i]+1 <= 30)
                dp[n+1] = min(dp[n+1], dp[i]+costs[2]);
        }
        dp[n+1] = min(dp[n+1], dp[n]+min(costs[0], min(costs[1], costs[2])));
    }
};






class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
    	int dayNums = days.size(), i, j, p;
        int table[dayNums] = {0};
        table[0] = costs[0];
        for(i=1;i<dayNums;i++){
        	table[i] = table[i-1] + costs[0];
        }

        for(i=0;i<dayNums;i++){
        	for(j=i;j<dayNums;j++){
        		if(days[j]-days[i] <= 6){
        			if(i==0)
        				p = costs[1];
        			else
        				p = table[i-1] + costs[1];
        			if(p < table[j]){
        				table[j] = p;  
        			}
        		}
        		if(days[j]-days[i] <= 29){
        			if(i==0)
        				p = costs[2];
        			else
        				p = table[i-1] + costs[2];
        			if(p < table[j]){
        				table[j] = p;  
        			}
        		}
        		if(i!=0 && table[j] > table[j-1] + costs[0]){
        			table[j] = table[j-1] + costs[0];
        		}
        	}
        }
        for(i=0;i<dayNums;i++){
        	cout << table[i] << " ";
        }
        cout << endl;
        return table[dayNums-1];
    }
};
