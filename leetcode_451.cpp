



class Solution {
public:
    string frequencySort(string s) {
        map<char,int> hash;
        vector<vector<char>> v(s.size()+1);
        string res;
        int i, j, k;

        for(i=0;i<s.size();i++){
        	if(hash.find(s[i]) == hash.end())
        		hash[s[i]] = 1;
        	else
        		hash[s[i]] += 1;
        }
        
        for(auto p:hash){
        	v[p.second].push_back(p.first);
        }

        for(i=v.size()-1;i>=0;i--){
        	for(j=0;j<v[i].size();j++){
        		for(k=1;k<=i;k++){
        			res.push_back(v[i][j]);
        		}
        	}
        }
        return res;
    }
};