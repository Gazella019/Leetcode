


class Solution {
public:
	
    int monotoneIncreasingDigits(int N) {
        
        int i, j, res = 0;
        string s;
        s = to_string(N);
        j = s.size();
        for(i=s.size()-1;i>=1;i--){
        	if(s[i] >= s[i-1])
        		continue;
        	j = i;
        	s[i-1] --;
        }

        for(i=s.size()-1;i>=j;i--){
        	s[i] = '9';
        }

        res = stoi(s);
    	return res;
    }
};


class Solution {
public:
	int res = 0;
	bool isFind = false;
    int monotoneIncreasingDigits(int N) {
        if(N == 0)
        	return 0;
    	vector<int> v;
    	stack<int> st;
    	int num;
    	num = N;
    	while(num != 0){
    		st.push(num%10);
    		num = num / 10;
    	}

    	while(st.size() != 0){
    		v.push_back(st.top());
    		st.pop();
    	}
    	for(int i=v[0];i>=0;i--){
    		v[0] = i;
    		dfs(v, i, 1, N);
    		if(isFind)	
    			return res;
    	}
    	return res;
    }

    void dfs(vector<int>& v, int d, int n, int N){
    	if(isFind)
    		return;
    	if(n == v.size()){
    		int num = 0;
    		for(int i=0;i<v.size();i++){
    			num = num*10 + v[i];
    		}
    		if(num <= N){
    			isFind = true;	
    			res = num;
    		}
    		return;
    	}
    	for(int i=9;i>=d;i--){
    		v[n] = i;
    		dfs(v, i, n+1, N);
    	}
    }
};