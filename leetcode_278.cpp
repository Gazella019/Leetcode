




// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        int l, r, mid;
        l = 1, r = n; 
        while(l < r){

        	mid = l + (r - l)/2;

        	if(isBadVersion(mid) == true)
        		r = mid;
        	else if(isBadVersion(mid) == false)
        		l = mid + 1;
        }

        return l;
    }
};