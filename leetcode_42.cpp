


class Solution {
public:
    int trap(vector<int>& height) {
        
        int i, res = 0, pre, h;
        stack<int> st;
        pre = 0;
        for(i=0;i<height.size();i++){

            if(height[i] >= pre){
                h = min(height[i], pre);
                while(st.size() > 0 && st.top() <= h){
                    res += (h-st.top());
                    st.pop();
                }
                pre = height[i];
            }
            else{
                st.push(height[i]);
            }

        }
        while(st.size() != 0){
            st.pop();
        }
        pre = 0;
        for(i=height.size()-1;i>=0;i--){

            if(height[i] > pre){
                h = min(height[i], pre);
                while(st.size() > 0 && st.top() <= h){
                    res += (h-st.top());
                    st.pop();
                }
                pre = height[i];
            }
            else{
                st.push(height[i]);
            }

        }

        return res;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        
        int i, n, res = 0;
        n = height.size();
        if(n == 0)
            return 0;
        vector<int> leftMost(n, 0);
        vector<int> RightMost(n, 0);
        leftMost[0] = height[0], RightMost[n-1] = height[n-1];
        for(i=1;i<height.size();i++){
            leftMost[i] = max(leftMost[i-1], height[i]);
        }
        for(i=height.size()-2;i>=0;i--){
            RightMost[i] = max(RightMost[i+1], height[i]);
        }

        for(i=0;i<n;i++){
            res += max(0, min(leftMost[i], RightMost[i]) - height[i]);
        }  

        return res;
    }
};


// TLE 314/315 almost done;

class Solution {
public:
    int trap(vector<int>& height) {
        int i, h, l, r, max = 0, count, sum = 0;

        for(i=0;i<height.size();i++){
        	if(height[i] > max)
        		max = height[i];
        }

        for(h=1;h<=max;h++){
        	count = 0;
        	for(i=0;i<height.size();i++){
        		if(height[i] >= h){
        			if(count == 0)
        				l = i;
        			else{
        				r = i;
        				sum = sum + r - l - 1;
        				l = i; 
        			}
        			count++;
        		}
        	}
        }
        return sum;
    }
};