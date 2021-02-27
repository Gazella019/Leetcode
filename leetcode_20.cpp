



class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int i;
        for(i=0;i<s.size();i++){
        	if(s[i] == ')'){
        		if(st.empty() || st.top() != '(')
        			return false;
        		st.pop();
        	}
        	else if(s[i] == ']'){
        		if(st.empty() || st.top() != '[')
        			return false;
        		st.pop();
        	}
        	else if(s[i] == '}'){
        		if(st.empty() || st.top() != '{')
        			return false;
        		st.pop();
        	}
        	else
        		st.push(s[i]);
        }
    
        if(st.empty())
        	return true;
        return false;
    }
};