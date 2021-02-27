

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        map<string, int> hash;
        
        vector<vector<string>> table(words.size());
        vector<string> res;
        for(int i=0;i<words.size();i++){
            hash[words[i]] += 1;
        }
        for(auto m: hash){
            table[m.second].push_back(m.first);
        }

        for(int i=table.size()-1;i>=0;i--){
            for(int j=0;j<table[i].size();j++){
                res.push_back(table[i][j]);
                k --;
                if(k == 0)
                    return res;
            }
        }

        return res;
    }
};


class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> hash;
        vector<vector<string>> v(words.size()+1);
        vector<string> res;
        string str;
        int i, j, count = 0;
        bool inserted;
        for(i=0;i<words.size();i++){
        	if(hash.find(words[i]) == hash.end())
        		hash[words[i]] = 1;
        	else
        		hash[words[i]] ++;
        }

        for(auto p:hash){
        	if(v[p.second].size() > 0){
        		inserted = false;
        		for(i=0;i<v[p.second].size();i++){
        			if(isGreater(v[p.second][i], p.first)){
        				v[p.second].insert(v[p.second].begin()+i, p.first);
        				inserted = true;
        				break;
        			}
        		}
        		if(inserted == false)
        			v[p.second].push_back(p.first);
        	}
        	else
        		v[p.second].push_back(p.first);
        }

        for(i=words.size();i>=0;i--){
        	for(j=0;j<v[i].size();j++){
        		res.push_back(v[i][j]);
        		count ++;
        		if(count >= k)
        			break;
        	}
        	if(count >= k)
        			break;
        }

        return res;
    }

    bool isGreater(string x, string y){
    	int len = min(x.size(), y.size());
    	for(int i=0;i<len;i++){
    		if(x[i] > y[i])
    			return true;
    		else if(x[i] < y[i])
    			return false;
    	}
    	if(x.size() > y.size())
    		return true;
    	return false;
    }
};