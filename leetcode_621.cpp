




class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
    	int tasksNums[26] = {0};
    	int i, now = 25, intervals = 0, count = 0, c, finished = 0;
    	for(i=0;i<tasks.size();i++){
    		tasksNums[tasks[i]-'A'] += 1;
    	}
    	sort(tasksNums, tasksNums+26);

    	while(tasksNums[now] != 0){
    		count = 0;
    		intervals ++;
    		tasksNums[now] --;
    		count ++;
    		finished ++;
    		c = now-1;
    		while(count <= n){
    			if(tasksNums[c] == 0){
    				break;
    			}
    			tasksNums[c] --;
    			intervals ++;
    			count ++;
    			finished ++;
    			c --;
    		}

    		if(count <= n && finished != tasks.size())
    			intervals = intervals + n - count + 1; 

    		sort(tasksNums, tasksNums+26);
    	}
    	cout << endl;
    	for(i=0;i<26;i++){
    		cout << " " << tasksNums[i];
    	}
    	cout << endl;
    	cout << " intervals = " << intervals ;
    	return intervals;
    }
};


// 用 idel slot 的方式去解


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
    	int tasksNums[26] = {0};
    	int i, max = 0, idleSlots;
    	for(i=0;i<tasks.size();i++){
    		tasksNums[tasks[i]-'A'] += 1;
    		if(tasksNums[tasks[i]-'A'] > max)
    			max = tasksNums[tasks[i]-'A'];
    	}

    	idleSlots = (max-1) * n;
    	for(i=0;i<26;i++){
    		if(tasksNums[i] == max)
    			idleSlots = idleSlots - max +1;
    		else
    			idleSlots = idleSlots - tasksNums[i];
    	}

    	idleSlots = idleSlots + max - 1;
    	if(idleSlots > 0)
    		return tasks.size() + idleSlots;
    	return tasks.size();
 	}
};


