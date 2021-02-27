


int cal(int N){
	int digitSum = 0, num;
	num = N;
	while(num != 0){
		digitSum = digitSum + num%10;
		num = num / 10;
	}
	return digitSum;
}


int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
	int num, i, digitSum = 0;
	num = N;

	while(num != 0){
		digitSum = digitSum + num%10;
		num = num / 10;
	}

	i = N+1;
	while(true){
		if(cal(i) == digitSum){
			cout << "nums " << i << endl;
			return i;
		}
		i++;
	}

	return 0;
}


