


class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        
        int mx, mi;
        unordered_map<int, int> maxVal;
        unordered_map<int, int> minVal;
        vector<int> res;

        for(int i=0;i<matrix.size();i++){
        	mi = INT_MAX;
        	for(int j=0;j<matrix[0].size();j++){
        		mi = min(mi, matrix[i][j]);
        	}
        	minVal[mi] = 1;
        }

        for(int i=0;i<matrix[0].size();i++){
        	mx = 0;
        	for(int j=0;j<matrix.size();j++){
        		mx = max(mx, matrix[j][i]);
        	}
        	maxVal[mx] = 1;
        }

        for(auto& it:maxVal){
        	if(minVal.find(it.first) != minVal.end())
        		res.push_back(it.first);
        }
        
        return res;
    }
};