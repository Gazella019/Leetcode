




int main() {
   	
   	int i, n;
   	cin >> n;
   	vector<int> v(n, 0);
   	vector<int> res(n, 0);
   	int mx;
   	for(i=0;i<n;i++){
   		cin >> v[i];
   	}
   	mx = v[n-1];

   	for(i=n-2;i>=0;i--){
   		if(v[i] > mx){
   			mx = v[i];
   		}
   		else{
   			res[i] = mx+1-v[i];
   		}
   	}

   	for(i=0;i<n;i++){
   		cout << res[i] << " ";
   	}

    return 0;
}