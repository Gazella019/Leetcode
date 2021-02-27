



int lilysHomework(vector<int> arr) {
	
	int i, n, res, cnt = 0, temp, to_swap;
	unordered_map<int, int> hash;
	vector<int> v;
	vector<int> origin;
	origin = arr;

	v = origin;
	sort(v.begin(), v.end());
	n = arr.size();

	for(i=0;i<n;i++){
		hash[arr[i]] = i;
	}
	cnt = 0;
	for(i=0;i<n;i++){
		if(v[i] == arr[i])
			continue;
		to_swap = hash[v[i]];

		hash[arr[i]] = to_swap;
		hash[v[i]] = i;

		temp = arr[i];
		arr[i] = v[i];
		arr[to_swap] = temp;

		cnt ++;
	}
	res = cnt, cnt = 0;
	arr = origin;
	v = origin;
	for(i=0;i<n;i++){
		hash[arr[i]] = i;
	}
	sort(v.begin(), v.end(), greater<int>());
	for(i=0;i<n;i++){
		if(v[i] == arr[i])
			continue;

		to_swap = hash[v[i]];

		hash[arr[i]] = to_swap;
		hash[v[i]] = i;

		temp = arr[i];
		arr[i] = v[i];
		arr[to_swap] = temp;

		cnt ++;
	}

	res = min(res, cnt);
	return res;
}

// TLE
int lilysHomework(vector<int> arr) {
	
	int i, j, cnt = 0, mn, mx, temp, res;
	vector<int> v;
	v = arr;
	for(i=0;i<arr.size();i++){
		mn = i;
		for(j=i;j<arr.size();j++){
			if(arr[j] < arr[mn]){
				mn = j;
			}
		}
		if(mn == i)
			continue;
		cnt ++;
		temp = arr[i];
		arr[i] = arr[mn];
		arr[mn] = temp;
	}
	res = cnt, cnt = 0;
	arr = v;
	for(i=0;i<arr.size();i++){
		mx = i;
		for(j=i;j<arr.size();j++){
			if(arr[j] > arr[mx]){
				mx = j;
			}
		}
		if(mx == i)
			continue;
		cnt ++;
		temp = arr[i];
		arr[i] = arr[mx];
		arr[mx] = temp;
	}
	res = min(res, cnt);
	return cnt;
}