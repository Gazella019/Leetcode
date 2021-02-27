




class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
		
		int offset;
		unordered_map<string, vector<int>> hash;
		vector<vector<string>> res;
		string str;

		for(int i=0;i<strings.size();i++){
			str = strings[i];
			offset = str[0]-'a';
			for(int j=0;j<str.size();j++){
				str[j] = str[j]-offset;
				if(str[j] < 'a')
					str[j] += 26;
			}
			hash[str].push_back(i);
		}        
		for(auto it:hash){
			vector<string> temp;
			for(int i=0;i<it.second.size();i++){
				temp.push_back(strings[it.second[i]]);
			}
			res.push_back(temp);
		}

		return res;
    }
};