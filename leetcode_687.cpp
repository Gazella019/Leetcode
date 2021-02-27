


class Solution {
public:
	int mx = 0;
    int longestUnivaluePath(TreeNode* root) {
        
    	longest(root);
    	return max(0, mx-1);
    }

    int longest(TreeNode* root){
    	if(root == NULL)
    		return 0;
    	int l , r;
    	l = longest(root->left);
    	r = longest(root->right);
    	if(root->left == NULL || root->left->val != root->val)
    		l = 0;
    	if(root->right == NULL || root->right->val != root->val)
    		r = 0;
    	cout << root->val << " " << l << " " << r << endl;
    	mx = max(mx, l+r+1);
    	return max(l+1, r+1);
    }
};