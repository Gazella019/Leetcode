



class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        string res = S;
        string l, r;
        vector<int> list; 
        int i, j, k, plus;
        for(i=0;i<indexes.size();i++){
        	if(canReplace(S, sources[i], indexes[i])){
        		list.push_back(i);
        	}
        }
        for(k=0;k<list.size();k++){
        	i = list[k];
	        plus = targets[i].size() - sources[i].size(); 
	        l = S.substr(0, indexes[i]);
	        r = S.substr(indexes[i]+sources[i].size(), S.size()-indexes[i]-sources[i].size());
	        S = l + targets[i] + r;
	        for(j=0;j<list.size();j++){
	        	if(indexes[list[j]] > indexes[i])
	        		indexes[list[j]] += plus;
	        }
        }
        return S;
    }

    bool canReplace(string S, string source, int start){
    	for(int i=0;i<source.size();i++){
    		if(S[i+start] != source[i])
    			return false;
    	}
    	return true;
    }
};