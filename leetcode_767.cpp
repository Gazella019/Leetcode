



class Solution {
public:
    string reorganizeString(string S) {
        
        int maxVal = 0, i, j, total;
        char head = ' ';
        string str = "";

        vector<int> v(26, 0);
        vector<char> ch;

        for(i=0;i<S.size();i++){
        	v[S[i]-'a'] += 1;
        	maxVal = max(maxVal, v[S[i]-'a']);
        }

        vector<vector<char>> table(maxVal+1);

        for(i=0;i<26;i++){
        	if(v[i] > 0)
        		table[v[i]].push_back(i+'a');
        }

        

        return str;
    }
};