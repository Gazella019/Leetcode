



int main() {
   	
   	int i, n;
   	cin >> n;
   	vector<int> v(n, 0);
   	vector<int> res(n, 0);
   	stack<int> st;
   	for(i=0;i<n;i++){
   		cin >> v[i];
   	}


   	for(i=0;i<n;i++){
   		while(st.size() > 0 && v[i] > v[st.top()]){
   			res[st.top()] = v[i] - v[st.top()];
   			st.pop();
   		}
   		st.push(i);
   	}

   	for(i=0;i<n;i++){
   		cout << res[i] << " ";
   	}

    return 0;
}