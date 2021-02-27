


class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
    	
    	priority_queue<int> pq;
    	int mx1, mx2;

    	for(int i=0;i<stones.size();i++){
    		pq.push(stones[i]);
    	}

    	while(pq.size() > 1){
    		mx1 = pq.top();
    		pq.pop();
    		mx2 = pq.top();
    		pq.pop();
    		if(mx1 != mx2)
    			pq.push(mx1-mx2);
    	}
    	if(pq.size() == 0)
    		return 0;
    	return pq.top();
    }
};