

// Runtime: 0 ms, faster than 100.00% of C++ 
// Meory Usage: 8.1 MB, less than 100.00% of C++


class Solution {
public:
    int hammingDistance(int x, int y) {
        int h = x ^ y;
        int count = 0;
        while(h > 0){
        	count = count + 1;
        	h = h & (h - 1);
        }
        return count;
    }
};


class Solution {
public:
    int hammingDistance(int x, int y) {
        int h = x ^ y;
        int count = 0;
        while(h >= 1){
        	if(h%2 == 1)
        		count++;
        	h = h / 2;
        }
        return count;
    }
};