



class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> v;
        int i, l, r;
        for(i=0;i<s.size();i++){
        	if(s[i] >= 'A' && s[i] <= 'Z')
        		v.push_back(s[i]-'A'+'a');

        	else if(s[i] >= 'a' && s[i] <= 'z')
        		v.push_back(s[i]);

        	else if(s[i] >= '0' && s[i] <= '9')
        		v.push_back(s[i]);
        }
        l = 0, r = v.size()-1;

        while(l<=r){

        	if(v[l] != v[r])
        		return false;
        	l++;
        	r--;
        }

        for(i=0;i<v.size();i++){
        	cout << " " << v[i] ;
        }
        return true;
    }
};