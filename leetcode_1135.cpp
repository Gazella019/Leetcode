


class Solution {
public:
    int minimumCost(int N, vector<vector<int>>& connections) {
        
        int res = 0, cnt = 0;
        vector<int> table(N+1, 0);

        for(int i=1;i<=N;i++){
        	table[i] = i;
        }
        sort(connections.begin(), connections.end(), [&](vector<int>&a, vector<int>&b){
        	return a[2] < b[2];
        });

        for(int i=0;i<connections.size();i++){
        	if(isSame(table, connections[i][0], connections[i][1]) == false){
        		res += connections[i][2];
        		cnt ++;
        		Union(table, connections[i][0], connections[i][1]);
        	}
        }
        if(cnt != N-1)
        	return -1;
        return res;
    }


    int Find(vector<int>& table, int x){
    	if(table[x] == x)
    		return x;
    	table[x] = Find(table, table[x]);
    	return table[x];
    }

    bool isSame(vector<int>& table, int x, int y){
    	if(Find(table, x) == Find(table, y))
    		return true;
    	return false;
    }

    void Union(vector<int>&table, int x, int y){
    	int gx, gy;
    	gx = Find(table, x);
    	gy = Find(table, y);
    	if(gx == gy)
    		return;
    	table[gx] = gy;
    }

};
