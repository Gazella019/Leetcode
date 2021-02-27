




class Solution {
public:

    static bool cmp(const vector<int>& a,const vector<int>& b) {
        return a[0]<b[0];
    }

    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        if(intervals.size() == 0)
            return 0;
        int i, cur = 0, res = 1, size;
        sort(intervals.begin(), intervals.end(), cmp);
        priority_queue<int, vector<int>, greater<int>> pq;

        pq.push(intervals[0][1]);

        for(i=1;i<intervals.size();i++){
            if(intervals[i][0] >= pq.top()){
                while(pq.size() != 0 && pq.top() <= intervals[i][0]){
                    pq.pop();
                }
            }
            pq.push(intervals[i][1]);
            size = pq.size();
            res = max(res, size);
        }

        return res;
    }

};




















class Solution {
public:

	static bool cmp(const vector<int>& a,const vector<int>& b) {
        return a[0]<b[0];
    }

    int minMeetingRooms(vector<vector<int>>& intervals) {
        
    	if(intervals.size() == 0)
    		return 0;

    	int i, j, count, maxCount = 1;
    	sort(intervals.begin(),intervals.end(),cmp);
    	priority_queue<int, vector<int>, greater<int>> q;

    	q.push(intervals[0][1]);
    	count = 1;
    	for(i=1;i<intervals.size();i++){
    		while(intervals[i][0] >= q.top()){
    			q.pop();
    			count --;
    			if(count == 0)
    				break;
    		}
    		q.push(intervals[i][1]);
    		count++;
    		if(count > maxCount)
    			maxCount = count;
    	}

    	return maxCount;
    }

};





// 找出 edge case 幾乎通過
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
    	if(intervals.size() == 0)
    		return 0;

    	vector<vector<vector<int>>> table;
    	int i, j, count = 0;
    	bool isInsert;
    	table.push_back({intervals[0]});
    	count ++;

    	for(i=1;i<intervals.size();i++){
    		isInsert = false;
    		for(j=0;j<table.size();j++){
    			if(canInset(intervals[i], table[j])){
    				table[j].push_back(intervals[i]);
    				isInsert = true;
    				break;
    			}
    		}
    		if(isInsert == false){
    			table.push_back({intervals[i]});
    			count ++;
    		}
    	}

    	return table.size();
    }

    bool canInset(vector<int> v, vector<vector<int>> intervals){

    	int start, end;
    	for(int i=0;i<intervals.size();i++){
    		start = max(v[0], intervals[i][0]);
    		end = min(v[1], intervals[i][1]);
    		if(end - start > 0)
    			return false;
    	}
    	return true;

    }
};