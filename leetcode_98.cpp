


class Solution {
public:
    bool isValidBST(TreeNode* root) {
    	
    	bool tf;
    	tf = valid(root, LONG_MIN, LONG_MAX);
    	return tf;
    }

    bool valid(TreeNode* root, long lower, long upper){

    	if(root == NULL)
    		return true;

    	if(root->val >= upper || root->val <= lower)
    		return false;
    	bool l, r;
    	l = valid(root->left, lower, root->val);
    	r = valid(root->right, root->val, upper);

    	return (l && r);
    }
};


