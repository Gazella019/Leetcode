


class Solution {
public:
    bool isPossible(vector<int>& target) {
     	
    	long i, sum = 0, mx, num;
    	priority_queue<long> pq;
    
    	for(i=0;i<target.size();i++){
    		sum = sum + target[i];
    		pq.push(target[i]);
    	}
    	
    	while(pq.top() > sum / 2  && sum > 1){
    		mx = pq.top(), pq.pop();
    		if(sum == mx) return false;
    		num = mx%(sum-mx);
    		pq.push(num);
    		sum = sum - mx + num;
    	}

     	return sum == 1 || sum == target.size();   
    }
};



class Solution {
public:
    bool isPossible(vector<int>& target) {
     	
    	long i, sum = 0, mx, num;
    	priority_queue<long> pq;
    
    	for(i=0;i<target.size();i++){
    		sum = sum + target[i];
    		pq.push(target[i]);
    	}
    	
    	while(pq.top() != 1){
    		mx = pq.top();
    		pq.pop();
    		num = mx - sum + mx;
    		if(num <= 0)	return false;
    		pq.push(num);
    		sum = sum - mx + num;
    	}

     	return true;   
    }
};