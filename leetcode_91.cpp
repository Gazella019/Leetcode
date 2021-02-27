


class Solution {
public:
    int numDecodings(string s) {
        int i, sum = 0;
        int table[s.size()] = {0};
        if(s[0]-'0' != 0){
        	table[0] = 1;
        	sum = sum + s[0]-'0';
        }
        else
        	return 0;
        for(i=1;i<s.size();i++){
        	sum = sum*10 + s[i]-'0';
        	if(sum == 0)
        		return 0;
        	if(s[i]-'0' == 0){
        		if(s[i-1]-'0' >= 3)
        			return 0;
        		if(i-2 >= 0)
        			table[i] = table[i-2];
        		else
        			table[i] = 1;
        		sum = 0;
        	}
        	else if(sum > 26){
        		table[i] = table[i-1];
        		sum = s[i]-'0';
        	}
        	else if(sum >= 10){
        		if(i-2 >= 0)
					table[i] = table[i-1] + table[i-2];
				else
					table[i] = table[i-1] + 1;
        		sum = s[i]-'0'; 
        	}
        	else if(sum > 0){
        		table[i] = table[i-1];
        	}
        }
        for(i=0;i<s.size();i++){
        	cout << table[i] << " ";
        }
        return table[s.size()-1];
    }
};

