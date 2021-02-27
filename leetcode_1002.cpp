




class Solution {
public:
    vector<string> commonChars(vector<string>& A) {

    	int i, j, min;
    	int table[A.size()][26] = {0};
    	bool same;
    	vector<string> res;
    	string v(1, 0);
    	for(i=0;i<A.size();i++){
    		for(j=0;j<A[i].size();j++){
    			table[i][A[i][j]-'a'] += 1;
    		}
    	}

    	for(i=0;i<26;i++){
    		min = table[0][i];
    		same = true;
    		for(j=1;j<A.size();j++){
    			if(table[j][i] < min)
    				min = table[j][i];
    		}
    		if(min != 0){
    			for(j=1;j<=min;j++){
    				v[0] = i + 'a';
    				res.push_back(v);
    			}
    		}
    	}
    	return res;

    }
};