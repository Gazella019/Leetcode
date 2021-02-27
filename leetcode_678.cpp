

class Solution {
public:
    bool checkValidString(string s) {
        
        int i, l = 0, r = 0;
        stack<int> star;
        stack<int> left;

        for(i=0;i<s.size();i++){
       		if(s[i] == '*'){
       			star.push(i);
       		} 	
       		else if(s[i] == '('){
       			left.push(i);
       		}
       		else if(s[i] == ')'){
       			if(left.size() != 0)
       				left.pop();
       			else if(star.size() != 0)
       				star.pop();
       			else
       				return false;
       		}
        }

        while(left.size() != 0 && star.size() != 0){
        	if(left.top() > star.top())
        		return false;
        	else
        		left.pop(), star.pop();
        }
        if(left.size() > 0)
        	return false;
        return true;
    }
};





class Solution {
public:
    bool checkValidString(string s) {
        
        int i, l = 0, r = 0;

        for(i=0;i<s.size();i++){
        	if(s[i] == '(' || s[i] == '*'){
        		l ++;
        	}
        	else if(s[i] == ')')
        		r ++;
        	if(r > l)
        		return false;
        }
        l = 0, r = 0;
        for(i=s.size()-1;i>=0;i--){
        	if(s[i] == ')' || s[i] == '*')
        		r ++;
        	else
        		l ++;
        	if(l > r)
        		return false;
        }
        
        return true;
    }
};
