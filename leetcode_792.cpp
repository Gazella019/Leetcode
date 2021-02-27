



class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        
        int i, j, cnt = 0;
        vector<pair<int, int>> table[26];

        for(i=0;i<words.size();i++){
        	table[words[i][0]-'a'].push_back(i, 0);
        }

        return 0;

    }
};