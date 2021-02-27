


class Solution {
public:
    string generateTheString(int n) {
        
        int i;
        string str;
        if(n%2 == 0){
        	for(i=1;i<=n-1;i++){
        		str = str + 'a';
        	}
        	str = str + 'b';
        }
    	else{
    		for(i=1;i<=n;i++){
    			str = str + 'a';
    		}
    	}
    	return str;
    }
};