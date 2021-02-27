






class Solution {
public:
    int jump(vector<int>& nums) {

        if(nums.size() == 0 || nums.size() == 1)
            return 0;

        int i, res = 1, cur = 0, mx;

        vector<int> maxDistance(nums.size(), 0);

        for(i=0;i<maxDistance.size();i++){
            maxDistance[i] = i+nums[i];
        }

        while(maxDistance[cur] < nums.size()-1){
            mx = cur;
            for(i=cur;i<=maxDistance[cur];i++){
                if(maxDistance[i] > maxDistance[mx])
                    mx = i;
            }
            cur = mx;
            res ++;
        }
        return res;
    }
};




// O(N)
// maxVisit 是關鍵, 已經造訪過的不用重新traverse, 因為step只會更多

class Solution {
public:
    int jump(vector<int>& nums) {
    	if(nums.size() == 0 || nums.size() == 1)
    		return 0;
    	int i, j, count, total, n, step = 0, maxVisit = 0;
    	queue<int> q;
    	q.push(0);
    	total = 1;
    	while(q.size() != 0){
    		step ++;
    		count = 0;
    		for(i=1;i<=total;i++){
    			n = q.front();
    			if(n+nums[n] >= nums.size()-1)
    				return step;
    			if(n+nums[n] > maxVisit){
    				for(j=maxVisit+1;j<=n+nums[n];j++){
    					q.push(j);
    					count ++;
    				}
    				maxVisit = n + nums[n];
    			}
    			q.pop();
    		}
    		total = count;
    	}
    	return step;
    }
};

// 沒有使用maxVisit, 重複造訪的版本
/*
class Solution {
public:
    int jump(vector<int>& nums) {
    	if(nums.size() == 0 || nums.size() == 1)
    		return 0;
    	int i, j, count, total, n, step = 0, maxVisit = 0;
    	queue<int> q;
    	q.push(0);
    	total = 1;
    	while(q.size() != 0){
    		step ++;
    		count = 0;
    		for(i=1;i<=total;i++){
    			n = q.front();
    			if(n+nums[n] >= nums.size()-1)
    				return step;
    			for(j=1;j<=nums[n];j++){
    				q.push(n+j);
    				count ++;
    			}
    			q.pop();
    		}
    		total = count;
    	}
    	return step;
    }
};
*/


// O(N^2)	TLE (91/92)
class Solution {
public:
    int jump(vector<int>& nums) {
    	if(nums.size() == 0)
    		return 0;
        vector<int> table(nums.size(), INT_MAX);
        int i, j;
        table[0] = 0;
        for(i=0;i<nums.size()-1;i++){
        	for(j=1;j<=nums[i];j++){
        		if(i+j < nums.size())
        			table[i+j] = min(table[i]+1, table[i+j]);
        	}
        }
        for(i=0;i<table.size();i++){
        	cout << table[i] << " ";
        }

        return table[nums.size()-1];
    }
};