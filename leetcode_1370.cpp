



class Solution {
public:
    string sortString(string s) {
        
        int i, sum = 0, cnt = 0;
        string res(s.size(), ' ');
        vector<int> table(26, 0);

        for(i=0;i<s.size();i++){
        	table[s[i]-'a'] += 1;
        	sum ++;
        }

        while(sum > 0){
        	for(i=0;i<26;i++){
        		if(table[i] > 0){
        			res[cnt] = (i+'a');
        			cnt++;
        			table[i]--, sum --;
        		}
        	}
        	for(i=25;i>=0;i--){
        		if(table[i] > 0){
        			res[cnt] = (i+'a');
        			cnt++;
        			table[i]--, sum --;
        		}
        	}
        }

        return res;
    }
};