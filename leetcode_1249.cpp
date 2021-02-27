



class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        int i, sz, cnt;
    	cnt = 0;
    	for(i=0;i<s.size();i++){
    		if(s[i] == '(')
    			cnt ++;
    		if(s[i] == ')'){
    			if(cnt == 0)
    				s[i] = '*';
    			else
    				cnt --;
    		}
    	}
    	cnt = 0;
    	for(i=s.size()-1;i>=0;i--){
    		if(s[i] == ')')
    			cnt ++;
    		if(s[i] == '('){
    			if(cnt == 0)
    				s[i] = '*';
    			else
    				cnt --;
    		} 
    	}
    	s.erase(remove(s.begin(), s.end(), '*'), s.end());
    	return s;
    }
};



class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        int i;
    	stack<int> pos;
    	string res;
    	vector<int> del(s.size(), 0);

    	for(i=0;i<s.size();i++){

    		if(s[i] == '(')
    			pos.push(i);

    		if(s[i] == ')'){
    			if(pos.size() > 0)
    				pos.pop();
    			else
    				del[i] = 1;
    		}

    	}
    	while(pos.size() != 0){
    		del[pos.top()] = 1;
    		pos.pop();
    	}

    	for(i=0;i<del.size();i++){
    		if(del[i] == 0)
    			res = res + s[i];
    	}

    	return res;
    }
};