


class Solution {
public:
    int lastRemaining(int n) {
        if(n == 1)
        	return 1;
        int i, state = 0, count;
        stack<int> s1, s2;
        for(i=1;i<=n;i++){
        	if(i%2 == 0)
        		s1.push(i);
        }
        while(s1.size()+s2.size() != 1){
        	
        	count = 1;
        	if(state == 1){
	        	while(s2.size() != 0){
	        		if(count%2 == 0)
	        			s1.push(s2.top());
	        		s2.pop();
	        		count ++;
	        	}
	        	state = 2;
        	}
        	else{
	        	while(s1.size() != 0){
	        		if(count%2 == 0)
	        			s2.push(s1.top());
	        		s1.pop();
	        		count ++;
	        	}
	        	state = 1;
	        }
        }
        if(s1.size() == 1)
        	return s1.top();

        return s2.top();
    }
};