



class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
    	if(image.size() == 0 || image[0].size() == 0 || image[sr][sc] == newColor)
    		return image;

        int i, j, originColor, row, col, nr, nc;
        int direction[5] = {0, 1, 0, -1, 0};

        queue<vector<int>> q;
        vector<int> v;
        originColor = image[sr][sc];
        image[sr][sc] = newColor;

        q.push({sr, sc});

        while(q.size() != 0){
        	v = q.front();
        	row = v[0], col = v[1];
        	for(i=0;i<4;i++){
        		nr = row + direction[i];
        		nc = col + direction[i+1];
        		if(isValid(image, nr, nc)){
        			if(image[nr][nc] == originColor){
        				image[nr][nc] = newColor;
        				q.push({nr, nc});
        			}
        		}
        	}
        	q.pop();
        }

        return image;
    }

    bool isValid(vector<vector<int>>& image, int row, int col){
    	if(row < 0 || col < 0 || row >= image.size() || col >= image[0].size())
    		return false;
    	return true;
    }
};