


class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        vector<vector<int>> table(mat[0].size()+1);
        vector<int> res;
        int i, j, soldiers, count = 0;

        for(i=0;i<mat.size();i++){
        	soldiers = 0;
        	for(j=0;j<mat[i].size();j++){
        		if(mat[i][j] == 0)
        			break;
        		soldiers ++;
        	}
        	table[soldiers].push_back(i);
        }

        for(i=0;i<table.size();i++){
        	for(j=0;j<table[i].size();j++){
        		res.push_back(table[i][j]);
        		count++;
        		if(count == k)
        			return res;
        	}
        }

        return res;
    }
};