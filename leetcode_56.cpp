


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
    	if(intervals.size() == 0)
    		return {};
    	int i, start, end, cur;
    	vector<vector<int>> res;

    	sort(intervals.begin(), intervals.end());

    	res.push_back(intervals[0]);
    	cur = 0;
    	for(i=1;i<intervals.size();i++){
    		if(intervals[i][0] <= res[cur][1]){
    			res[cur][1] = max(res[cur][1], intervals[i][1]);
    		}
    		else{
    			res.push_back(intervals[i]);
    			cur ++;
    		}
    	}
    	return res;
    }
};




class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
    	if(intervals.size() == 0)
    		return {};
    	int i, start, end, cur;
    	vector<vector<int>> res;

    	sort(intervals.begin(), intervals.end());

    	res.push_back(intervals[0]);
    	cur = 0;
    	for(i=1;i<intervals.size();i++){
    		start = max(res[cur][0], intervals[i][0]);
    		end = min(res[cur][1], intervals[i][1]);

    		if(end - start >= 0){
    			res[cur][0] = min(res[cur][0], intervals[i][0]);
    			res[cur][1] = max(res[cur][1], intervals[i][1]);
    		}
    		else{
    			res.push_back({intervals[i][0], intervals[i][1]});
    			cur ++;
    		}

    	}
    	return res;
    }
};