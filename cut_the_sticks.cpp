





vector<int> cutTheSticks(vector<int> arr) {

	vector<int> res;
	int i, cutLength, mn, cnt;

	mn = 1000000000;
	for(i=0;i<arr.size();i++){
		if(arr[i] == 0)
			continue;
		mn = min(mn, arr[i]);
	}
	cutLength = mn;

	while(cutLength != 1000000000){
		mn = 1000000000;
		cnt = 0;
		for(i=0;i<arr.size();i++){
			if(arr[i] == 0)
				continue;
			cnt ++;
			arr[i] -= cutLength;
			if(arr[i] == 0)
				continue;
			mn = min(mn, arr[i]);
		}
		cutLength = mn;
		res.push_back(cnt);
	}

	return res;
}
