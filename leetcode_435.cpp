



class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        if(intervals.size() == 0 || intervals.size() == 1)
        	return 0;

        int i, j, res = 0, l = 0;
        vector<vector<int>> newIntervals;
        sort(intervals.begin(), intervals.end());

        for(i=1;i<intervals.size();i++){
        	if(isOverlap(intervals[l], intervals[i])){
        		if(intervals[l][1] >= intervals[i][1]){
        			l = i;
        		}
        		res ++;
        	}
        	else{
        		l = i;
        	}
        }

        return res;
    }

    bool isOverlap(vector<int>& a, vector<int>& b){
    	int start, end;
    	start = max(a[0], b[0]);
    	end = min(a[1], b[1]);
    	if(end-start > 0)
    		return true;
    	return false;
    }
};

// dp solution
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        if(intervals.size() == 0 || intervals.size() == 1)
        	return 0;

        int i, j, start, end, maxVal, res = 0;
        vector<int> dp(intervals.size(), 0);

        sort(intervals.begin(), intervals.end());
        dp[0] = 1;

        cout << endl;
        for(i=1;i<dp.size();i++){
        	maxVal = 0;
        	for(j=i-1;j>=0;j--){
        		start = max(intervals[i][0], intervals[j][0]);
        		end = min(intervals[i][1], intervals[j][1]);
        		if(end - start <= 0){	//non Overlapp
        			maxVal = max(maxVal, dp[j]);
        		} 
        	}
        	dp[i] = maxVal+1;
        	cout << dp[i] << " ";
        }

        return intervals.size()-dp[intervals.size()-1];
    }
};



// TLE

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        if(intervals.size() == 0 || intervals.size() == 1)
        	return 0;

        int i, j, start, end, toPop, maxx, count = 0, res = 0;
        vector<vector<int>> table(intervals.size(), vector<int> (intervals.size(), 0));
        vector<int> overlapp(intervals.size(), 0);
        vector<vector<int>> newIntervals;

		auto comp = [](const auto& interval1, const auto& interval2)
        { 
            return interval1[1] < interval2[1]; 
        };
        sort(intervals.begin(), intervals.end(), comp);

        for(i=0;i<intervals.size()-1;i++){
        	if(intervals[i] != intervals[i+1]){
        		newIntervals.push_back(intervals[i]);
        	}
        }
        newIntervals.push_back(intervals[i]);    
        res = intervals.size() - newIntervals.size();

        for(i=0;i<newIntervals.size();i++){
        	for(j=i+1;j<newIntervals.size();j++){
        		start = max(newIntervals[i][0], newIntervals[j][0]);
        		end = min(newIntervals[i][1], newIntervals[j][1]);
        		if(end - start > 0){
        			table[i][j] = 1;
        			table[j][i] = 1;
        			overlapp[i] ++;
        			overlapp[j] ++;
        			count ++;
        		}
        	}
        }
        while(count != 0){
        	maxx = 0;
			for(i=0;i<overlapp.size();i++){
				if(overlapp[i] > overlapp[maxx])
					maxx = i;
			}
			if(overlapp[maxx] == 0)
				break;
			for(i=0;i<table.size();i++){
				if(table[i][maxx] == 1){
					table[i][maxx] = 0;
					overlapp[i] -= 1;
				}
			}
			overlapp[maxx] = 0;
			res ++;        
		}

		return res;
    }
};