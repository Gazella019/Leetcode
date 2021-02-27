

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        int i, j;

        vector<Interval> v;
        vector<Interval> res;
        vector<Interval> ans;

        for(i=0;i<schedule.size();i++){
        	for(j=0;j<schedule[i].size();j++){
        		v.push_back(schedule[i][j]);
        	}
        }

        sort(v.begin(), v.end(), [](Interval& a, Interval &b){
        	return a.start < b.start; 
        });
        Interval cur;
        cur.start = v[0].start;
        cur.end = v[0].end;
        for(i=1;i<v.size();i++){
        	if(cur.end - v[i].start >= 0){
        		cur.start = min(cur.start, v[i].start);
        		cur.end = max(cur.end, v[i].end);
        	}
        	else{
        		res.push_back(cur);
        		cur.start = v[i].start;
        		cur.end = v[i].end;
        	}
        	if(i == v.size()-1)
        		res.push_back(cur);
        }

        for(i=1;i<res.size();i++){
        	cur.start = res[i-1].end;
        	cur.end = res[i].start;
        	ans.push_back(cur);
        }

       	return ans;
    }
};
