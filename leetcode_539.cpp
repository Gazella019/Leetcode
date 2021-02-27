


class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        
        int standard = 60*24;
        int i, j, h, m, res = standard;
        vector<int> minutes(timePoints.size());

        for(i=0;i<timePoints.size();i++){
        	h = (timePoints[i][0]-'0')*10 + (timePoints[i][1]-'0');
        	m = (timePoints[i][3]-'0')*10 + (timePoints[i][4]-'0');
        	minutes[i] = h*60+m;
        }

        sort(minutes.begin(), minutes.end());
        minutes.push_back(minutes[0]+standard);
        for(i=1;i<minutes.size();i++){
        	res = min(res, minutes[i]-minutes[i-1]);
        }

        return res;
    }
};

// TLE

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        
        int standard = 60*24, half = 12*24;
        int i, j, h, m, res = standard;
        vector<int> minutes(timePoints.size());

        for(i=0;i<timePoints.size();i++){
        	h = (timePoints[i][0]-'0')*10 + (timePoints[i][1]-'0');
        	m = (timePoints[i][3]-'0')*10 + (timePoints[i][4]-'0');
        	minutes[i] = h*60+m;
        }

        for(i=0;i<minutes.size();i++){
        	for(j=i+1;j<minutes.size();j++){
        		res = min(res, abs(minutes[i]-minutes[j]));
        		res = min(res, abs(abs(standard-minutes[i])+minutes[j]));
        		res = min(res, abs(abs(standard-minutes[j])+minutes[i]));
        	}
        }

        return res;
    }
};