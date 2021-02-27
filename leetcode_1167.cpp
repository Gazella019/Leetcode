




class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        
        int res = 0, x, y;
    	priority_queue<int, vector<int>, greater<int>> pq;

    	for(int i=0;i<sticks.size();i++){
    		pq.push(sticks[i]);
    	}

    	while(pq.size() > 1){
    		x = pq.top(), pq.pop();
    		y = pq.top(), pq.pop();
    		res += x + y;
    		pq.push(x+y);
    	}

    	return res;
    }
};