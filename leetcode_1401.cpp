


class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        
        int i, mn = INT_MAX;
        if(x_center >= x1 && x_center <= x2 && y_center >= y1 && y_center <= y2)
        	return true;

        for(i=x1;i<=x2;i++){
        	mn = min(mn, dist(x_center, y_center, i, y1));
        	mn = min(mn, dist(x_center, y_center, i, y2));
        }

        for(i=y1;i<=y2;i++){
        	mn = min(mn, dist(x_center, y_center, x1, i));
        	mn = min(mn, dist(x_center, y_center, x2, i));
        }

        if(mn <= (radius*radius))
        	return true;
        return false;
    }

    int dist(int x_center, int y_center, int x, int y){
    	int dx, dy;
    	dx = abs(x_center-x), dy = abs(y_center-y);
    	return (dx*dx) + (dy*dy);
    }
};