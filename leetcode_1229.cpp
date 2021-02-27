




class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        
    	int s1, s2, n, m, start, end;
    	s1 = 0, s2 = 0;
    	sort(slots1.begin(), slots1.end());
    	sort(slots2.begin(), slots2.end());
    	n = slots1.size(), m = slots2.size();

    	while(s1 < n && s2 < m){
    		start = max(slots1[s1][0], slots2[s2][0]);
    		end = min(slots1[s1][1], slots2[s2][1]);
    		if(end - start >= duration){
    			return {start, start + duration};
    		}
    		
    		if(slots1[s1][1] > slots2[s2][1])
    			s2 ++;
    		else
    			s1 ++;
    	}
    	return {};
    }
    
};