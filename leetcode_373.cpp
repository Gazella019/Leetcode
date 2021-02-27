


class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int i, j, size, cur, sum, m, n;
        m = nums1.size(), n = nums2.size();
        size = min(m*n, k);
        vector<vector<int>> res;
        vector<int> index(nums1.size(), 0);

        for(i=1;i<=size;i++){
            cur, sum = INT_MAX;
            for(j=0;j<nums1.size();j++){
                if(index[j] < nums2.size() && nums1[j]+nums2[index[j]] <= sum){
                    sum = nums1[j]+nums2[index[j]];
                    cur = j;
                }
            }
            res.push_back({nums1[cur], nums2[index[cur]]});
            index[cur] ++;
        }
        
        return res;
    }
};



class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    	
    	int i, j, n, sum, cnt = 0;
    	unordered_map<int, vector<vector<int>>> hash;
    	vector<vector<int>> res;
    	priority_queue<int> pq;
    	stack<int> st;

    	for(i=0;i<nums1.size();i++){
    		for(j=0;j<nums2.size();j++){
    			sum = nums1[i] + nums2[j];
    			hash[sum].push_back({nums1[i], nums2[j]});
    			pq.push(sum);
    			while(pq.size() > k){
    				pq.pop();
    			}
    		}
    	}

    	while(pq.size() != 0){
    		st.push(pq.top());
    		pq.pop();
    	}

    	while(st.size() > 0 && cnt < k){
    		n = st.top();
    		st.pop();
    		i = hash[n].size()-1;
    		res.push_back(hash[n][i]);
    		hash[n].pop_back();
    		
    	}

    	return res;
    }
};