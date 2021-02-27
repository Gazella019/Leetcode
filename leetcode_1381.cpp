

class CustomStack {
public:
    int cnt = 0;
    vector<int> st;
    vector<int> table;
    CustomStack(int maxSize) {
        st = vector<int>(maxSize);
        table = vector<int>(maxSize, 0);
    }
    
    void push(int x) {
        if(cnt >= st.size())
            return;
        st[cnt] = x;
        cnt ++;
    }
    
    int pop() {
        if(cnt == 0)
            return -1;
        int num;
        cnt --;
        num = st[cnt] + table[cnt];
        if(cnt > 0)
            table[cnt-1] += table[cnt];
        table[cnt] = 0;
        return num;
    }
    
    void increment(int k, int val) {
         
        if(cnt == 0)
            return;
        int index;
        index = min(k, cnt)-1;
        table[index] += val;
    }
};




class CustomStack {
public:
	int mx;
	stack<int> st;
	stack<int> temp;
    CustomStack(int maxSize) {
        mx = maxSize;
    }
    
    void push(int x) {
        if(st.size() == mx)
        	return;
        st.push(x);
    }
    
    int pop() {
        if(st.size() == 0)
        	return -1;
        int x;
        x = st.top();
        st.pop();
        return x;
    }
    
    void increment(int k, int val) {
        
        while(st.size() != 0){
        	if(st.size() <= k){
        		temp.push(st.top()+val);
        	}
        	else
        		temp.push(st.top());
        	st.pop();
        }

        while(temp.size() != 0){
        	st.push(temp.top());
        	temp.pop();
        }
    }
};

