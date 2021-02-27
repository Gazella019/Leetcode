


// Runtime: 20 ms, faster than 83.00% of C++
// Memory Usage: 23.5 MB, less than 100.00% of C++

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> hash;
        vector<int> res;
        int sum = 0, max = 0;
        traversal(root, &max, hash);
        for(auto p : hash){
        	if(p.second == max)
        		res.push_back(p.first);
        }
        return res;
    }

    int traversal(TreeNode* root, int *max, unordered_map<int, int>& hash){
    	if(root == NULL)
    		return 0;
    	int sum;
    	sum = traversal(root->left, max, hash) + traversal(root->right, max, hash) + root->val;
    	hash[sum] += 1;
    	if(hash[sum] > *max)
    		*max = hash[sum];
    	return sum;
    }
};