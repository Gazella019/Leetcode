


class Solution {
public:

	int mx = INT_MIN;

    int maxPathSum(TreeNode* root) {
        
        int res;
        res = traversal(root);
        return mx;
    }

    int traversal(TreeNode* root){
    	
    	if(root == NULL)
    		return 0;

    	int l, r;

    	l = traversal(root->left);
    	r = traversal(root->right);
    	
    	mx = max(mx, root->val);
    	mx = max(mx, l + root->val);
    	mx = max(mx, r + root->val);
    	mx = max(mx, l + r + root->val);

    	return max(root->val, max(l, r) + root->val);
    }
};