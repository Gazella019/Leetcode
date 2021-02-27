



class Solution {
public:
    int compress(vector<char>& chars) {
        
        stack<int> st;
        int res = 0, i, count, n = 0;
        char c;

        for(i=0;i<chars.size();i++){
        	if(chars[i] >= 35 && chars[i] <= 126){
        		c = chars[i];
        		count = 0;
        		while(i<chars.size() && chars[i] == c){
        			i++;
        			count++;
        		}
        		i--;
        		if(count == 1){
        			chars[n] = c;
        			n++, res++;
        		}
        		else{
        			chars[n] = c;
        			n++, res++;
        			while(count != 0){
        				st.push(count%10);
        				count = count/10;
        				res++;
        			}
        			while(st.size() != 0){
        				chars[n] = st.top()+'0';
        				st.pop(), n++;
        			}
        		}
        	}

        }
        return res;
    }
};