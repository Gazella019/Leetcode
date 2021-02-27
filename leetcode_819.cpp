



// Runtime: 4 ms, faster than 96.56% of C++
// Memory Usage: 8.9 MB, less than 100.00% of C++ 

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        vector<string> v;
        vector<int> freq;
        string s = "";
        int i, j, max = 0;
        bool isBanned = false, isSave = false;

        for(i=0;i<paragraph.size();i++){

        	if(paragraph[i] >= 'A' && paragraph[i] <= 'Z')
        		s.push_back(paragraph[i]-'A'+'a');
        	else if(paragraph[i] >= 'a' && paragraph[i] <= 'z')
        		s.push_back(paragraph[i]);
        	else if(s.size() != 0){
        		// check if banned
        		for(j=0;j<banned.size();j++){
        			if(s == banned[j])
        				isBanned = true;
        		}
        		if(!isBanned){
        			for(j=0;j<v.size();j++){
        				if(s == v[j]){
        					isSave = true;
        					freq[j] ++;
        					if(freq[j] > max)
        						max = freq[j];
        				}
        			}
        			if(!isSave){
        				v.push_back(s);
        				freq.push_back(1);
        			}
        		}
        		s = "";
        		isBanned = false;
        		isSave = false;
        	}
        }
        
        for(j=0;j<banned.size();j++){
        	if(s == banned[j])
        		isBanned = true;
        }
        if(!isBanned){
        	for(j=0;j<v.size();j++){
        		if(s == v[j]){
        			isSave = true;
        			freq[j] ++;
        			if(freq[j] > max)
        				max = freq[j];
        		}
        	}
        	if(!isSave){
        		v.push_back(s);
        		freq.push_back(1);
                if(1 > max)
                    max = 1;
        	}
        }
        
        
        for(i=0;i<freq.size();i++){
        	if(freq[i] == max){
        		return v[i];
        	}
        }
        return "";
    }
};