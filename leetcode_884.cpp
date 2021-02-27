

// Runtime: 0 ms, faster than 100.00% of C++
// Memory Usage: 8.7 MB, less than 100.00% of C++

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {

        vector<string> res;
        map<string, int> hash;
        string str = "";
        int i;
        for(i=0;i<A.size();i++){
        	if(A[i] == ' '){
        		if(hash.find(str) == hash.end())
        			hash[str] = 1;
        		else
        			hash[str] ++;
        		str = "";
        	}
        	else
        		str.push_back(A[i]);
        }
        if(hash.find(str) == hash.end())
        	hash[str] = 1;
        else
       		hash[str] ++;
       	str = "";
       	for(i=0;i<B.size();i++){
        	if(B[i] == ' '){
        		if(hash.find(str) == hash.end())
        			hash[str] = 1;
        		else
        			hash[str] ++;
        		str = "";
        	}
        	else
        		str.push_back(B[i]);
        }
        if(hash.find(str) == hash.end())
        	hash[str] = 1;
        else
       		hash[str] ++;

       	for(auto p:hash){
       		if(p.second == 1)
       			res.push_back(p.first);
       	}
       	return res;
    }
};