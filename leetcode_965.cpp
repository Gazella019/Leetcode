





struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
    	if(root == NULL)
    		return true;
        return traversal(root, root->val);
    }

    bool traversal(TreeNode* root, int value){
    	if(root == NULL)
    		return true;
    	if(root->val != value)
    		return false;
    	bool r, l;
    	r = traversal(root->right, value);
    	l = traversal(root->left, value);
    	if(r && l)
    		return true;
    	return false;
    }
};