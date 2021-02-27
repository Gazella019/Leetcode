



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
    	if(root == NULL)
    		return false;
    	int h1 = -1, f1 = -1, h2 = -1, f2 = -1;
    	find(root, x, 0, -1, &h1, &f1);
    	find(root, y, 0, -1, &h2, &f2);
    	if(h1 == h2 && f1 != f2)
    		return true;
    	return false; 
    }

    void find(TreeNode* root, int target, int level, int parent, int *h, int *f){
    	if(root == NULL)
    		return;
    	if(root->val == target){
    		*h = level;
    		*f = parent;
    	}
    	find(root->left, target, level+1, root->val, h, f);
    	find(root->right, target, level+1, root->val, h, f);
    }
};