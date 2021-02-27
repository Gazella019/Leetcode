



class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        bool x, y;
        x = overlapped(rec1[0], rec1[2], rec2[0], rec2[2]);
        y = overlapped(rec1[1], rec1[3], rec2[1], rec2[3]);
    	return x && y; 
    }

    bool overlapped(int s1, int e1, int s2, int e2){
    	int start, end;
    	start = max(s1, s2);
    	end = min(e1, e2);
    	if(end - start > 0)
    		return true;
    	return false;
    }
};