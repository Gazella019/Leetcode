





class Solution {
public:
    int scoreOfParentheses(string S) {

        stack<int> st;
        int i, sum, res = 0;
        for(i=0;i<S.size();i++){
        	if(S[i] == '('){
        		if(S[i+1] == ')'){
        			st.push(1);
        			i = i + 1;
        		}
        		else
        			st.push(0);
        	}
        	else if(S[i] == ')'){
        		sum = 0;
        		while(1){
        			if(st.top() == 0){
        				sum = sum * 2;
        				st.pop();
        				if(st.size() == 0)
        					res = res + sum;
        				else
        					st.push(sum);
        				break;
        			}
        			else{
        				sum = sum + st.top();
        				st.pop();
        			}
        		}
        	}
        }

        while(st.size()!=0){
        	res = res + st.top();
        	st.pop();
        }
        return res;
    }
};