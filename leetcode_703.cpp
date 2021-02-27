


class KthLargest {
public:
    
    int threshold;
    priority_queue<int, vector<int>, greater<int>> q;
    KthLargest(int k, vector<int>& nums) {
        threshold = k;
        for(int i=0;i<nums.size();i++){
            q.push(nums[i]);
            while(q.size() > threshold){
                q.pop();
            }
        }
    }
    
    int add(int val) {
        q.push(val);
        while(q.size() > threshold){
            q.pop();
        }
        return q.top();
    }
};
