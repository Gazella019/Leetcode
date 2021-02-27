

class Solution {
public:
    string reverseWords(string s) {
    	int i, j, l, r;
    	char tmp;
    	bool first = true;
    	string temp = "";
        string str;
        for(i=0;i<s.size();i++){
        	if(s[i] != ' '){
        		for(j=i;j<s.size();j++){
        			if(s[j] == ' ')
        				break;
        			temp = temp + s[j];
        		}
        		i = j;
        		if(first){
        			str = str + temp;
        			first = false;
        		}
        		else
        			str = str + " " + temp;
        		temp = "";
        	}

        }
        l = 0, r = str.size()-1;
        str = reverse(str, l, r);
        l = 0;
        for(i=0;i<str.size();i++){
        	if(str[i] == ' '){
        		r = i-1;
        		str = reverse(str, l, r);
        		l = i+1;
        	}
        }
        str = reverse(str, l, str.size()-1);
        return str;
    }

    string reverse(string str, int l, int r){
    	int temp;
        while(l < r){
        	temp = str[l];
        	str[l] = str[r];
        	str[r] = temp;
        	l++;
        	r--;
        }
        return str;
    }
};