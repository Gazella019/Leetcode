


class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        int i, now;
    	vector<int> visited(arr.size(), 0);

    	queue<int> q;
    	q.push(start);
    	visited[start] = 1;

    	while(q.size() != 0){
    		now = q.front();
    		visited[now] = 1;
    		if(now+arr[now] < arr.size() && visited[now+arr[now]] == 0)
    			q.push(now + arr[now]);
    		if(now-arr[now] >= 0 && visited[now-arr[now]] == 0)
    			q.push(now - arr[now]);
    		q.pop();
    	}

    	for(i=0;i<arr.size();i++){
    		cout << visited[i] << " ";
    		if(arr[i] == 0 && visited[i] == 1)
    			return true;
    	}

    	return false;
    }
};