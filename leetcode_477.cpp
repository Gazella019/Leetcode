


class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int i, j, p, q, total = 0;

        for(i=1;i<=32;i++){
            p = 0, q = 0;
            for(j=0;j<nums.size();j++){
                if(nums[j]&1 == 1)
                    p ++;
                else
                    q++;
                nums[j] = nums[j] >> 1;
            }
            total = total + p*q;
        }
        return total;
    }
};



// O(n^2) TLE
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int i, j, total = 0;
        for(i=0;i<nums.size();i++){
        	for(j=i+1;j<nums.size();j++){
        		total = total + numOf1(nums[i]^nums[j]);
        	}
        }
        return total;
    }

    int numOf1(int num){
        int count = 0;
        while(num > 0){
            num = num & (num - 1);
            count = count + 1;
        }
    	return count;
    }
};