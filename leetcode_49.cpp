

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        int i, j;
        unordered_map<string, vector<int>> hash;
        vector<vector<string>> res;
        string str;
        for(i=0;i<strs.size();i++){
        	str = strs[i];
        	sort(str.begin(), str.end());
        	hash[str].push_back(i);
        }

        for(auto& it:hash){
        	res.push_back({});
        	for(i=0;i<it.second.size();i++){
        		res.back().push_back(strs[it.second[i]]);
        	}
        }
        return res;
    }
};


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        int i, j;
        bool isFind;
        vector<vector<int>> table;
        vector<int> temp(26, 0);
        vector<vector<string>> res;

        for(i=0;i<strs.size();i++){
        	for(j=0;j<26;j++){
        		temp[j] = 0;
        	}
        	for(j=0;j<strs[i].size();j++){
        		temp[strs[i][j]-'a'] += 1;
        	}
        	isFind = false;
        	for(j=0;j<table.size();j++){
        		if(temp == table[j]){
        			isFind = true;
        			res[j].push_back(strs[i]);
        		}
        	}
        	if(isFind == false){
        		table.push_back(temp);
        		res.push_back({strs[i]});
        	}
        }

        return res;
    }
};