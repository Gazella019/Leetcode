



int main() {

	int i, n, maxCnt = 0, x, y, mn = 1000000, l;
   	cin >> n;
   	vector<int> v(n, 0);
   	unordered_map<int, int> hash;
   	unordered_map<int, int> head;
   	unordered_map<int, int> end;

   	for(i=0;i<n;i++){
   		cin >> v[i];
   		hash[v[i]] += 1;
   		maxCnt = max(maxCnt, hash[v[i]]);
   	}

   	for(i=0;i<n;i++){
   		if(hash[v[i]] == maxCnt){
   			if(head.find(v[i]) == head.end())
   				head[v[i]] = i;
   			end[v[i]] = i;
   		}
   	}

   	for(auto&it : end){
   		l = it.second - head[it.first] + 1;
   		if(l < mn){
   			mn = l;
   			x = head[it.first];
   			y = it.second;
   		}
   		else if(l == mn){
   			if(head[it.first] < x){
   				x = head[it.first];
   				y = it.second;
   			}
   		}
   	}

   	cout << x+1 << " " << y+1;

    return 0;
}