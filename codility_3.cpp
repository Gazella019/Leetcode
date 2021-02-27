






int solution(vector<int> &A) {
    

	int i, j, n, num = 1, cnt = 0, res = 0;
	n = A.size();

	for(i=1;i<=31;i++){
		cnt = 0;
		for(j=0;j<n;j++){
			if((A[j]&num) >= 1)
				cnt ++;
		}
		num = num << 1;
		res = max(res, cnt);
	}

	return res;
}
