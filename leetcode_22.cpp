




class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        vector<string> res;
        string str(n+n, ' ');
        traverse(res, str, n, n, 0);
        return res;
    }

    void traverse(vector<string>& res, string& str, int l, int r, int n){
    	
    	if(n == str.size()){
    		res.push_back(str);
    		return;
    	}
    	if(r < l)
    		return;
    	if(l > 0){
    		str[n] = '(';
    		traverse(res, str, l-1, r, n+1);
    	}
    	if(r > 0){
    		str[n] = ')';
    		traverse(res, str, l, r-1, n+1);
    	}
    }
};