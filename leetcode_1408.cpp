



class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        
        int i, j, k, l;
        bool canAdd;
        vector<string> res;
        string str;

        for(i=0;i<words.size();i++){
        	canAdd = false;
        	for(j=0;j<words.size();j++){
        		if(i == j)
        			continue;
        		l = words[i].size();
        		if(l <= words[j].size()){
        			for(k=0;k+l-1<words[j].size();k++){
        				str = words[j].substr(k, l);
        				if(str == words[i]){
        					res.push_back(words[i]);
        					canAdd = true;
        					break;
        				}
        			}
        		}
        		if(canAdd)
        			break;
        	}
        }

        return res;
    }
};