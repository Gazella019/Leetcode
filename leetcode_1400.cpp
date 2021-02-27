



class Solution {
public:
    bool canConstruct(string s, int k) {

     	int i, n, odd = 0, even = 0;
     	n = s.size();
     	if(k > n)
     		return false;
     	if(k == n)
     		return true;
     	vector<int> table(26, 0);
     	
     	for(i=0;i<s.size();i++){
     		table[s[i]-'a'] += 1;
     	}

     	for(i=0;i<26;i++){
     		if(table[i] == 0)
     			continue;
     		if(table[i] % 2 == 0)
     			even ++;
     		else
     			odd ++;
     	}
     	if(odd > k)
     		return false;
     	return true;
    }
};