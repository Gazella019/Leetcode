




class Solution {
public:
    string rankTeams(vector<string>& votes) {
		
		bool inserted;
		int i, j, temp;
		char c;
		vector<vector<int>> table(26, vector<int> (votes[0].size(), 0));
		vector<int> used(26, 0);
		string str;

		for(i=0;i<votes.size();i++){
			for(j=0;j<votes[0].size();j++){
				table[votes[i][j]-'A'][j] += 1;
				used[votes[i][j]-'A'] = 1;
			}
		}

		for(i=0;i<26;i++){
			if(used[i] == 0)
				continue;
			inserted = false;
			c = i + 'A';
			for(j=0;j<str.size();j++){
				if(greater(table, i, str[j]-'A')){
					str = str.substr(0, j) + c + str.substr(j);
					inserted = true;
					break;
				}
			}
			if(inserted == false){
				str = str + c;
			}
			cout << str << endl;
		}

		return str;
    }

    bool greater(vector<vector<int>> table, int a, int b){

    	for(int i=0;i<table[0].size();i++){
    		if(table[a][i] == table[b][i])
    			continue;
    		if(table[a][i] > table[b][i])
    			return true;
    		if(table[a][i] < table[b][i])
    			return false;
    	}
    	if(a < b)
    		return true;
    	return false;
    }
};