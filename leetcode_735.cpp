



class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        bool skip;
        int cur, size;
        stack<int> st;
        st.push(asteroids[0]);

        for(int i=1;i<asteroids.size();i++){
        	if(st.size() > 0 && asteroids[i] < 0 && st.top() > 0){
        		cur = asteroids[i];
        		while(st.size() > 0 && cur < 0 && st.top() > 0){
        			if(cur + st.top() == 0){
        				skip = true;
        				st.pop();
        				break;
        			}
        			else if(cur + st.top() > 0){
        				skip = true;
        				break;
        			}
        			else if(cur + st.top() < 0){
        				skip = false;
        				st.pop();
        			}
        		}
        		if(skip == false)
        			st.push(cur);
        	}
        	else
        		st.push(asteroids[i]);
        }
        size = st.size();
        vector<int> res(size, 0);
        for(int i=size-1;i>=0;i--){
        	res[i] = st.top();
        	st.pop();
        }
        return res;
    }
};