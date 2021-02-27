


class Solution {
public:

    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        
        int i, maxVal;
    	vector<vector<int>> res;
    	vector<vector<int>> table;

    	for(i=0;i<buildings.size();i++){
    		
    	}
    	
        return res;
    }
};





class Solution {
public:

	struct node{
		int endTime;
		int height;
	};
		 
	struct cmp{
	    bool operator()(node a,node b){
	        return a.height <= b.height;
	        // return a.height > b.height
	    }
	};

    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        

    	int i, curHeight = -1, endPoint = INT_MAX;
    	node curNode;
        vector<vector<int>> res;
        priority_queue<node, vector<node>, cmp> pq;


        for(i=0;i<buildings.size();i++){

        	if(pq.size() == 0){
        		if(buildings[i][0] > endPoint){
        			res.push_back({endPoint, 0});
        		}
        		res.push_back({buildings[i][0], buildings[i][2]});
        		endPoint = buildings[i][1];
        	}
        	else if(pq.size() > 0){
        		if(buildings[i][2] > pq.top().height){
        			res.push_back({buildings[i][0], buildings[i][2]});
        			endPoint = buildings[i][1];
        		}
        		if(buildings[i][0] > endPoint){
        			while(pq.size() > 0){
        				if(pq.top().endTime < endPoint){
        					pq.pop();
        				}
        				else{
        					res.push_back({endPoint, pq.top().height});
        					endPoint = pq.top().endTime;
        				}
        			}
        		}
        	}
        	curNode.endTime = buildings[i][1];
        	curNode.height = buildings[i][2];
        	pq.push(curNode);
        }

        return res;
    }
};