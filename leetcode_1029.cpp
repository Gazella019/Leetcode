


class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        int i, n = costs.size(), res = 0;
        vector<int> v;

        sort(costs.begin(), costs.end(), [](vector<int> &v1, vector<int> &v2) {
    		return (v1[0] - v1[1] < v2[0] - v2[1]);
  		});
        for(i=0;i<n;i++){
        	if(i < n/2)
        		res = res + costs[i][0];
        	else
        		res = res + costs[i][1];
        }

        return res;
    }
};

