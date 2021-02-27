



class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {

    	if(intervals.size() == 0 || intervals.size() == 1)
    		return 1;
    	sort(intervals.begin(),intervals.end());

    	for(int i=0;i<intervals.size()-1;i++){
    		if(intervals[i][1] > intervals[i+1][0])
    			return false;
    	}

    	return true;
    }
};