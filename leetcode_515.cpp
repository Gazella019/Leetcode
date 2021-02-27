



// Runtime: 12 ms, faster than 95.94% of C++ 
// Memory Usage: 20.8 MB, less than 100.00% of C++
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        int level = 0;
        traversal(root, res, level);
        return res;
    }

    void traversal(TreeNode* root, vector<int>& res ,int level){
    	if(root == NULL)
    		return;
    	if(res.size() <= level)
    		res.push_back(root->val);
    	else{
    		if(res[level] < root->val)
    			res[level] = root->val;
    	}
    	traversal(root->left, res, level+1);
    	traversal(root->right, res, level+1);
    }
};