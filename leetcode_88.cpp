




class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        
        int i, now;
        m = m-1;
        n = n-1;
        now = nums1.size()-1;
        while(n >= 0){
        	if(m >= 0 && nums1[m] >= nums2[n]){
        		nums1[now] = nums1[m];
        		m --;
        	}
        	else{
        		nums1[now] = nums2[n];
        		n --;
        	}
        	now --;
        }
    }
};



class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        vector<int> res;
        int i, n1 = 0, n2 = 0;

        while(n1 < m && n2 < n){
        	if(nums1[n1] <= nums2[n2]){
        		res.push_back(nums1[n1]);
        		n1++;
        	}
        	else{
        		res.push_back(nums2[n2]);
        		n2++;
        	}
        }
        while(n2 < n){
        	res.push_back(nums2[n2]);
        	n2 ++;
        }
        while(n1 < m){
        	res.push_back(nums1[n1]);
        	n1 ++;
        }
        for(i=0;i<res.size();i++){
        	nums1[i] = res[i];
        }

    }
};