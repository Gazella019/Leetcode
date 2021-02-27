
// Runtime: 0 ms, faster than 100.00% of C++ 
// Memory Usage: 8.7 MB, less than 40.91% of C++

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<int> st;
        stack<int> temp;
        int i;
        string s, t;
        for(i=0;i<S.size();i++){
        	if(S[i] == '#'){
        		if(st.size() != 0)
        			st.pop();
        	}
        	else
        		st.push(S[i]);
        }
        while(st.size() != 0){
        	temp.push(st.top());
        	st.pop();
        }
        while(temp.size() != 0){
        	s.push_back(temp.top());
        	temp.pop();
        }
        for(i=0;i<T.size();i++){
        	if(T[i] == '#'){
        		if(st.size() != 0)
        			st.pop();
        	}
        	else
        		st.push(T[i]);
        }
        while(st.size() != 0){
        	temp.push(st.top());
        	st.pop();
        }
        while(temp.size() != 0){
        	t.push_back(temp.top());
        	temp.pop();
        }
        return (s == t);
    }
};