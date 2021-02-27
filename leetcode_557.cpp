

// Runtime: 16 ms, faster than 96.68% of C++ 
// Memory Usage: 11.8 MB, less than 91.30% of C++

class Solution {
public:
    string reverseWords(string s) {

        int i, start = 0, end;
        char temp;
        for(i=0;i<s.size();i++){
        	if(s[i] == ' '){
        		end = i-1;
        		while(start < end){
        			temp = s[start];
        			s[start] = s[end];
        			s[end] = temp;
        			start++;
        			end--;
        		}
        		start = i+1;
        	}
        }
        end = s.size()-1;
        while(start < end){
        	temp = s[start];
        	s[start] = s[end];
        	s[end] = temp;
        	start++;
        	end--;
        }
        return s;
    }
};