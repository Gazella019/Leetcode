





int equal(vector<int> arr) {

	int i, addNums = 0, temp, diff, res = 0;

	for(i=1;i<arr.size();i++){
		arr[i] += addNums;
		if(arr[i] > arr[i-1]){
			temp = arr[i];
			arr[i] = arr[i-1];
			arr[i-1] = temp;
		}
		diff = arr[i-1] - arr[i];
		while(diff != 0){
			if(diff >= 5){
				arr[i] += 5;
				addNums += 5;
			}
			if(diff >= 2){
				arr[i] += 2;
				addNums += 2;
			}
			else{
				arr[i] += 1;
				addNums += 1;
			}
			res += 1;
			diff = arr[i-1] - arr[i];
		}
	}
	return res;
}