



class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {

        int i, j, n, offest;
        string res;
        n = s.size();
        vector<int> v(n, 0);
        res = s;

        for(i=0;i<n;i++){
        	v[i] = i;
        }

        for(i=0;i<shift.size();i++){
        	offest = shift[i][1];
        	if(shift[i][0] == 0){
        		for(j=0;j<n;j++){
        			v[j] -= offest;
        			if(v[j] < 0)
        				v[j] += n;
        		}
        	}
        	else{
        		for(j=0;j<n;j++){
        			v[j] += offest;
        			if(v[j] >= n)
        				v[j] %= n;
        		}
        	}
        }

        for(i=0;i<n;i++){
        	res[v[i]] = s[i];
        }

        return res;
    }
};