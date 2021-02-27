
// Runtime: 172 ms, faster than 96.34% of C++
// Memory Usage: 38.3 MB, less than 100.00% of C++

class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        int i, j, m, n;
        bool isMatch;
        vector<string> res;
        if(A.size() == 0 || B.size() == 0)
        	return res;
        int requireMax[26] = {0};
        for(i=0;i<B.size();i++){
        	int temp[26] = {0};
        	for(j=0;j<B[i].size();j++){
        		temp[B[i][j]-'a'] += 1;
        	}
        	for(j=0;j<26;j++){
        		if(temp[j] > requireMax[j])
        			requireMax[j] = temp[j];
        	}
        }
        for(i=0;i<A.size();i++){
        	int table[26] = {0};
        	for(j=0;j<A[i].size();j++){
        		table[A[i][j]-'a'] += 1;
        	}
        	isMatch = true;
        	for(j=0;j<26;j++){
        		if(table[j] < requireMax[j])
        			isMatch = false;
        	}
        	if(isMatch)
        		res.push_back(A[i]);
        }
        return res;
    }
};



// TLE
class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        int i, j, m, n;
        bool isMatch;
        vector<string> res;
        if(A.size() == 0 || B.size() == 0)
        	return res;
        for(i=0;i<A.size();i++){
        	int table[26] = {0};
        	for(j=0;j<A[i].size();j++){
        		table[A[i][j]-'a'] += 1;
        	}
        	for(m=0;m<B.size();m++){
        		isMatch = true;
        		int temp[26] = {0};
        		for(n=0;n<B[m].size();n++){
        			if(table[B[m][n]-'a'] == 0){
        				isMatch = false;
        				break;
        			}
        			temp[B[m][n]-'a'] += 1;
        		}
        		for(n=0;n<26;n++){
        			if(table[n] < temp[n])
        				isMatch = false;
        		}
        		if(isMatch == false)
        			break;
        	}
        	if(isMatch == true)
        		res.push_back(A[i]);
        }
        return res;
    }
};