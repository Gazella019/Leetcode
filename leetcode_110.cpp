



class Solution {
public:
	bool res = true;
    bool isBalanced(TreeNode* root) {
        
    	length(root);
    	return res;
    }

    int length(TreeNode* root){
    	if(root == NULL)
    		return 0;
    	int l, r;
    	l = length(root->left);
    	r = length(root->right);
    	if(abs(l-r) >= 2)
    		res = false;
    	return max(l, r) + 1;
    }
};