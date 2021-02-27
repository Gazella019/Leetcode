



bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int i, x = 0;

        for(i=1;i<n;i++){
        	if(knows(x, i) == true)
        		x = i;
        }

        for(i=0;i<n;i++){
        	if(i == x)
        		continue;
        	if(knows(x, i) == true || knows(i, x) == false)
        		return -1;
        }
        
        return x;
    }
};



bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int i, j;
        bool isCelb;
        for(i=0;i<n;i++){
        	isCelb = true;
        	for(j=0;j<n;j++){
        		if(i != j && knows(i, j) == true){
        			isCelb = false;
        			break;
        		}
        	}
        	if(isCelb == true){
        		for(j=0;j<n;j++){
        			if(knows(j, i) == false){
        				isCelb = false;
        				break;
        			}
        		}
        		if(isCelb == true)
        			return i;
        	}
        }

        return -1;
    }
};


// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        vector<int> cleberity(n, 1);
        int i, j, count = n;
        bool isCelb;
        for(i=0;i<n;i++){
        	if(cleberity[i] == 1){
        		for(j=0;j<n;j++){
        			if(i != j){
        				if(knows(i, j) == false){
        					cleberity[j] = 0;
        				}
        				else if(knows(i, j) == true){
        					cleberity[i] = 0;
        				}
        			}
        		}
        	}
        }

        for(i=0;i<n;i++){
        	if(cleberity[i] == 1){
        		isCelb = true;
        		for(j=0;j<n;j++){
        			if(knows(j, i) == false){
        				isCelb = false;
        				break;
        			}
        		}
        		if(isCelb == true)
        			return i;
        	}
        }

        return -1;
    }
};