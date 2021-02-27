


// treat as LCS problem
// Runtime: 8 ms, faster than 99.20% of C++
// Memory Usage: 9.8 MB, less than 66.67% of C++ 
class Solution {
public:
    int minDistance(string word1, string word2) {
    	if(word1.size() == 0)
    		return word2.size();
    	if(word2.size() == 0)
    		return word1.size();
        int table[word1.size()][word2.size()] = {0};
        int i, j, res, lcs;
        if(word1[0] == word2[0])
        	table[0][0] = 1;

        for(i=1;i<word1.size();i++){
        	if(word1[i] == word2[0])
        		table[i][0] = 1;
        	else
        		table[i][0] = table[i-1][0];
        }

        for(i=1;i<word2.size();i++){
        	if(word2[i] == word1[0])
        		table[0][i] = 1;
        	else
        		table[0][i] = table[0][i-1];
        }

        for(i=1;i<word1.size();i++){
        	for(j=1;j<word2.size();j++){
        		if(word1[i] == word2[j])
        			table[i][j] = table[i-1][j-1] + 1;
        		else
        			table[i][j] = max(table[i-1][j], table[i][j-1]);
        	}
        }
        //for(i=0;i<word1.size();i++){
        //	for(j=0;j<word2.size();j++){
        //		cout << table[i][j] << " ";
        //	}
        //	cout << endl;
        //}
        lcs = table[word1.size()-1][word2.size()-1];
        res = word1.size()-lcs + word2.size()-lcs;
        return res;
    }
};