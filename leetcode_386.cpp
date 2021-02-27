



class Solution {
public:
    vector<int> lexicalOrder(int n) {
    	int i , num;
    	vector<int> res;
    	for(i=1;i<=9;i++){
    		if(i>n)
    			break;
    		dfs(res, i, n);
    	}
    	return res;
    }
    
    void dfs(vector<int>& res, int num, int n){
    	res.push_back(num);
	    for(int i=0;i<=9;i++){
	    	if((num*10 + i) <= n){
	    		dfs(res, num*10+i, n);
	    	}
    	}
    }
};