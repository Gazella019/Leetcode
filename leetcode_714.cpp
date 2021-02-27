

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        
        int i;
        vector<int> buy(prices.size(), 0);
        vector<int> sell(prices.size(), 0);

        sell[0] = 0;
        buy[0] = -1 * prices[0];

        for(i=1;i<prices.size();i++){
        	sell[i] = max(sell[i-1], buy[i-1] + prices[i] - fee);
        	buy[i] = max(buy[i-1], sell[i-1] - prices[i]);
        }

        cout << "sell: ";
        for(i=0;i<prices.size();i++){
        	cout << sell[i] << " ";
        }
        cout << endl;

        cout << "buy: ";
        for(i=0;i<prices.size();i++){
        	cout << buy[i] << " "; 
        }
        cout << endl;

        return sell[prices.size()-1];
    }
};



class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        
        int i;
        vector<int> buy(prices.size(), 0);
        vector<int> sell(prices.size(), 0);
        vector<int> no_has1(prices.size(), 0);
        vector<int> no_has0(prices.size(), 0);

        buy[0] = -1 * prices[0];
        sell[0] = -1 * prices[0];
        no_has0[0] = 0;
        no_has1[0] = 0;

        for(i=1;i<prices.size();i++){
        	buy[i] = max(sell[i-1], no_has0[i-1]) - prices[i];
        	sell[i] = max(buy[i-1], no_has1[i-1]) + prices[i];
        	no_has0[i] = max(no_has0[i-1], sell[i-1]);
        	no_has1[i] = max(no_has1[i-1], buy[i-1]);
        }

        cout << "buy: ";
        for(i=0;i<prices.size();i++){
        	cout << buy[i] << " ";
        }
        cout << endl;
        cout << "sell: ";
        for(i=0;i<prices.size();i++){
        	cout << sell[i] << " ";
        }
        cout << endl;
        cout << "no_has0: ";
        for(i=0;i<prices.size();i++){
        	cout << no_has0[i] << " ";
        }
        cout << endl;
        cout << "no_has1: ";
        for(i=0;i<prices.size();i++){
        	cout << no_has1[i] << " ";
        }

        return 0;
    }
};