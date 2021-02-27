
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    	int i, gasNum, count, now;
    	bool canCycle;
    	vector<int> need;
    	for(i=0;i<gas.size();i++){
    		need.push_back(gas[i] - cost[i]);
    	}
    	
    	for(i=0;i<need.size();i++){
    		now = i;
    		count = 0;
    		gasNum = 0;
    		canCycle = true;
    		while(count < need.size()){
    			if(now == need.size())
    				now = 0;
    			else{
    				gasNum = gasNum + need[now];
    				count = count + 1;
    				now = now + 1;
    				if(gasNum < 0){
    					canCycle = false;
    					break;
    				}
    			}
    		}
    		if(canCycle)
    			return i;
    	}
    	return -1;
    }
};




// DFS sol
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    	int i;
        for(i=0;i<gas.size();i++){
        	cout << " " << i;
        	traversal(gas, cost, 0, i, 0);
        }
        return 0;
    }

    void traversal(vector<int>& gas, vector<int>& cost, int gasNum, int n, int count){
	    if(gasNum  < 0)
	    	return;    	
    	if(n == gas.size()){
    		n = 0;
	    }
    	if(count == gas.size()-1){
    		cout << "yes";
    		return;
    	}
	    gasNum = gasNum + gas[n] - cost[n];
	    count = count + 1;
	    traversal(gas, cost, gasNum, n+1, count);
    }
};