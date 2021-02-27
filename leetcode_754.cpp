

class Solution {
public:
    int reachNumber(int target) {
    	if(target == 0)
    		return 0;
        queue<int> q;
        int n = 2, count = 0, num = 2, now;
        q.push(1);
        q.push(-1);
        while(1){
        	now = q.front();
        	if(now == target)
        		break;
        	q.push(now + n);
        	q.push(now - n);
        	count = count + 1;
        	q.pop();
        	if(count == num){
        		count = 0;
        		num = num * 2;
        		n = n + 1;
        	}
        }
        return n-1;
    }
};