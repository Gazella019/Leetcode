




class Solution {
public:
	int cnt = 0;
	string ans;
    string getHappyString(int n, int k) {
        string str(n, ' ');
        traversal(str, 0, n, k);
        return ans;
    }

    void traversal(string& str, int cur, int n, int k){
    	if(cur == n){
    		cnt ++;
    		if(cnt == k)
    			ans = str;
    		return;
    	}
    	char c;
    	for(int i=0;i<3;i++){
    		c = i + 'a';
    		if(cur != 0 && str[cur-1] == c)
    			continue;
    		str[cur] = c;
    		traversal(str, cur+1, n, k);
    	}
    }
};