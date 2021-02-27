



class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {

    	int i, j, n = light.size(), nums = 0, cnt = 0;
        vector<int> bulbs(n+1, 0);
        vector<int> blue(n+1, 0);
        blue[0] = 1;

        for(i=0;i<light.size();i++){
        	bulbs[light[i]] = 1;
        	nums ++;
        	if(blue[light[i]-1] == 1){
        		blue[light[i]] = 1;
        		nums --;
        		j = light[i]+1;
        		while(nums > 0 && j <= n){
        			if(bulbs[j] == 0)
        				break;
        			blue[j] = 1;
        			nums --;
        			j++;	
        		}
        	}
        	if(nums == 0){
        		cnt ++;
        	}
        }
        return cnt;
    }
};