


// sol1  O(n^2) 
class Solution {
public:
    int maxArea(vector<int>& height) {
    	int i, j, max = 0, area;
    	for(i=0;i<height.size();i++){
    		for(j=i+1;j<height.size();j++){
    			area = min(height[i], height[j]) * (j-i);
    			if(area > max)
    				max = area;
    		}
    	}
    	return max;
    }
};



// sol2 O(n)


class Solution {
public:
    int maxArea(vector<int>& height) {
    	int l, r, max = 0, area;
    	r = height.size()-1;
    	l = 0;
    	while(r>l){
    		area = min(height[l], height[r]) * (r-l);
    		if(area > max)
    			max = area;
    		if(height[l] < height[r])
    			l = l + 1;
    		else
    			r = r - 1;
    	}
    	return max;
    }
};
