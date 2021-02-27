



class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        
        int i, j, count = 0, maxDay = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int, vector<int>> hash;

        for(i=0;i<events.size();i++){
      
        	hash[events[i][0]].push_back(events[i][1]);
        	if(events[i][1] > maxDay)
        		maxDay = events[i][1];
        }	

        for(i=1;i<=maxDay;i++){

        	for(j=0;j<hash[i].size();j++){
        		pq.push(hash[i][j]);
        	}
        	while(pq.size() > 0 && pq.top() < i){
        		pq.pop();
        	}
        	if(pq.size() != 0){
        		pq.pop();
        		count ++;
        	}
        }

        return count;
    }
};