


class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        
        int i, j, m, n, res = 0;
        vector<int> row(picture.size(), 0);
        vector<int> col(picture[0].size(), 0);

        for(i=0;i<picture.size();i++){
        	for(j=0;j<picture[0].size();j++){
        		if(picture[i][j] == 'B'){
        			row[i] ++;
        			col[j] ++;
        		}
        	}
        }

        for(i=0;i<picture.size();i++){
        	for(j=0;j<picture[0].size();j++){
        		if(picture[i][j] == 'B'){
        			if(row[i] <= 1 && col[j] <= 1)
        				res ++;
        		}
        	}
        }
        return res;
    }
};




class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        
        bool conflict;
        int i, j, m, n, res = 0;

        for(i=0;i<picture.size();i++){
        	for(j=0;j<picture[0].size();j++){
        		if(picture[i][j] == 'B'){
        			conflict = false;
        			for(m=0;m<picture.size();m++){
        				if(picture[m][j] == 'B' && m != i)
        					conflict = true;
        			}
        			for(n=0;n<picture[0].size();n++){
        				if(picture[i][n] == 'B' && n != j)
        					conflict = true;
        			}
        			if(!conflict)
        				res ++;
        		}
        	}
        }
        return res;
    }
};