


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        if(intervals.size() == 0)
        	return {newInterval};
        int i;
        bool inserted = false;
        vector<vector<int>> res;

    	for(i=0;i<intervals.size();i++){

    		if(isOverlap(intervals[i], newInterval)){
    			newInterval[0] = min(newInterval[0], intervals[i][0]);
    			newInterval[1] = max(newInterval[1], intervals[i][1]);
    		}
    		else{
    			if(newInterval[1] < intervals[i][0] && inserted == false){
    				res.push_back(newInterval);
    				inserted = true;
    			}
    			res.push_back(intervals[i]);
    		}
    	}
    	
    	if(inserted == false)
    		res.push_back(newInterval);
    	return res;
    }

    bool isOverlap(vector<int>& a, vector<int>& b){
    	int start, end;
    	start = max(a[0], b[0]);
    	end = min(a[1], b[1]);
    	if(end-start >= 0)
    		return true;
    	return false;
    }
};