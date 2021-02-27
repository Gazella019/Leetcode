

// Runtime: 64 ms, faster than 73.43% of C++
// Memory Usage: 12.8 MB, less than 100.00% of C++
 
class Solution {
public:
    int longestPalindromeSubseq(string s) {
    	if(s.size() == 0)
    		return 0;
        int table[s.size()][s.size()] = {0};
        int i, j, k;

        for(i=0;i<s.size();i++){
        	table[i][i] = 1;
        }
        for(i=1;i<s.size();i++){
        	if(s[i-1] == s[i])
        		table[i-1][i] = 2;
        	else
        		table[i-1][i] = 1;
        }

        for(k=2;k<=s.size();k++){
        	for(i=0;i<s.size()-k+1;i++){
        		if(s[i] == s[i+k-1])
        			table[i][i+k-1] = table[i+1][i+k-1-1] + 2;
        		else
        			table[i][i+k-1] = max(table[i+1][i+k-1], table[i][i+k-1-1]);
        	}
        }

        //for(i=0;i<s.size();i++){
        //	for(j=0;j<s.size();j++){
        //		cout << table[i][j] << " ";
        //	}
        //	cout << endl;
        //}
        return table[0][s.size()-1];
    }
};