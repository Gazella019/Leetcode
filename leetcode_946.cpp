




class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    	if(pushed.size() == 0)
    		return true;
    	stack<int> st;
    	int i = 0, j = 0;
    	bool res = true;
    	while(1){
    		if(pushed[i] == popped[j]){
    			i++;
    			j++;
    		}
    		else if(st.size() > 0 && st.top() == popped[j]){
    			st.pop();
    			j++;
    		}
    		else{
    			st.push(pushed[i]);
    			i++;
    		}
    		if(j == popped.size() || i == pushed.size())
    			break;
    	}

    	while(j!=popped.size() && st.size() > 0){
    		if(st.top() != popped[j])
    			return false;
    		st.pop();
    		j++;
    	}
    	return true;
    }
};



/*
for(i=0;i<pushed.size();i++){
    		if(pushed[i] == popped[j]){
    			cout << "i " << i << " j " << j << endl;
    			j = j + 1;
    		}
    		else if(st.size() > 0 && st.top() == popped[j]){
    			cout << "i " << i << " j " << j << endl;
    			st.pop();
    			j = j + 1;
    		}
    		else{
    			cout << "push " << pushed[i] << endl;
    			cout << "i " << i << " j " << j << endl;
    			st.push(pushed[i]);
    		}
    		if(j == popped.size())
    			break;
    	}
*/