


class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        
        bool meet;
    	int i, res = 0, cnt; 
    	vector<int> dist(seats.size(), INT_MAX);

    	meet = false;
    	for(i=0;i<seats.size();i++){
    		if(seats[i] == 1){
    			meet = true;
    			cnt = 0;
    			dist[i] = 0;
    		}
    		else if(meet){
    			cnt ++;
    			dist[i] = min(dist[i], cnt);
    		}
    	}
    	meet = false;
    	for(i=seats.size()-1;i>=0;i--){
    		if(seats[i] == 1){
    			meet = true;
    			cnt = 0;
    			dist[i] = 0;
    		}
    		else if(meet){
    			cnt ++;
    			dist[i] = min(dist[i], cnt);
    		}
    	}

    	for(i=0;i<dist.size();i++){
    		res = max(res, dist[i]);
    	}

    	return res;
    }
};