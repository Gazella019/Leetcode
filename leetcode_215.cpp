




// sol 1 O(nlogn)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()-k];
    }
};


// sol 2 O(nlogk) priority queue


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        for(int i=1;i<=k;i++){
        	pq.pop();
        }
        
        return pq.top();
    }
};


// sol 3 quick select

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    	int res;
        res = quick_select(nums, k, nums.size()-1, -1);
        return(nums[res]);
    }

    int quick_select(vector<int>& nums, int k, int pivot, int n){

    	int temp, res, i;
    	for(i=n+1;i<pivot;i++){

    		if(nums[i] < nums[pivot]){
    			n = n + 1;
    			temp = nums[i];
    			nums[i] = nums[n];
    			nums[n] = temp;
    		}
    	}
    	n = n + 1;
    	// if(nums[n] <= nums[pivot]) 的話代表 sorted 好了
    	if(nums[n] > nums[pivot]){
	    	temp = nums[pivot];
	    	nums[pivot] = nums[n];
	    	nums[n] = temp;
	    }
    	//cout << "pivot is " << n << endl; 
    	if(nums.size()-n == k)
    		return n;
    	// 要找的值比較大 , k 比較小
    	if(nums.size()-n > k){
    		res = quick_select(nums, k, pivot, n);
    	}
    	// 要找的值比較小 , k 比較大
    	else if(nums.size()-n < k){
    		res = quick_select(nums, k, n-1, -1);
    	}
    	return res;
    }

};







// Disscuss sol

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return KthLargestInternal(nums, k, 0, nums.size()-1);
    }
private:
    int KthLargestInternal(vector<int>& nums, int k, int low, int high) {
        int pivot = rand()%(high-low+1) + low;  // choose random pivot ans swap with first element in array[low..high]
        swap(nums[low], nums[pivot]);
        int i = low+1, j = high;
        while(i <= j) {                
            if (nums[i] < nums[low]) {          // keep on putting elements less than pivot to the end of current array
                swap(nums[i], nums[j]);     
                j--;
            } else {
                i++;                            // bigger elements remain at the front of the array
            }
        }
        swap(nums[low], nums[j]);               // put the pivot in right place after partition
        if (j-low == k-1) {
            return nums[j];                     // if pivot is in the required position return it.
        }
        if (k-1 < j-low) {
            return KthLargestInternal(nums, k, low, j-1);     // if required order is less than pivot recurse to left half
        } else {
            return KthLargestInternal(nums, k-(j-low+1), j+1, high);  // if required order is greater recurese to right half
        }
    }
};
