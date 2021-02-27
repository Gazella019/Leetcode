






class Solution {
public:
    vector<int> countBits(int num) {
    	int i, j, count = 2;
        vector<int> res(num+1, 0);
        if(num == 0)
        	return res;
        res[1] = 1;

        if(num == 1)
        	return res;
        
        for(i=2;i<=num;i++){
        
        	if(num <= (count*2)-1){

        		for(j=i;j<=num;j++){
        			res[j] = res[j-count] + 1;
        		}

        	}
        	else{
        		for(j=i;j<=(count*2)-1;j++){
        			res[j] = res[j-count] + 1;
        		}
        		i = count*2 -1;
        		count = count *2;
        	}
        }
        return res;
    }
};