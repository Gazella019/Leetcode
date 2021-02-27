


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        if(s.size() < p.size())
            return {};
        bool tf;
        vector<int> res;
        vector<int> v(26, 0);
        vector<int> table(26, 0);
        int i, start, end;
        start = 0, end = p.size()-1;

        for(i=0;i<p.size();i++){
            table[p[i]-'a'] += 1;
            v[s[i]-'a'] += 1;
        }

        while(end < s.size()){
            tf = true; 
            for(i=0;i<26;i++){
                if(v[i] != table[i])
                    tf = false;
            }
            if(tf)
                res.push_back(start);
            v[s[start]-'a'] --;
            start ++;
            end ++;
            if(end >= s.size())
                break;
            v[s[end]-'a'] ++;
        }

        return res;
    }
};



class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
    	if(p.size() > s.size())
    		return {};
        vector<int> res;
        int i, j, k, start = 0, psize, count = 0;
        bool tf = true;
        int table[26] = {0};
        int temp[26] = {0};
        psize = p.size();

        for(i=0;i<psize;i++){
        	table[p[i]-'a'] ++;
        }

        for(i=start;i<s.size()-psize+1;i++){
        	
        	tf = true;
        	count = 0;
        	for(j=0;j<psize;j++){
        		if(table[s[i+j]-'a'] != 0){
        			temp[s[i+j]-'a'] ++;
        			count ++;
        		}
        		else{
        			tf = false;
        			i = i + j;
        			for(k=0;k<26;k++){
        				temp[k] = 0;
        			}
        			break;
        		}
        		if(count == psize){
        			for(k=0;k<26;k++){
        				if(temp[k] != table[k]){
        					tf = false;
        				}
        				temp[k] = 0;
        			}
        		}
        	}
        	if(tf)
        		res.push_back(i);
        }

        return res;
    }
};