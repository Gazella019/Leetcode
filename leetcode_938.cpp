


class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        
    	int res;
    	res = dfs(root, L, R);
    	return res;
    }

    int dfs(TreeNode* root, int l, int r){
    	if(root == NULL)
    		return 0;
 		if(root->val >= l && root->val <= r){
 			return dfs(root->left, l, r) + dfs(root->right, l, r) + root->val;
 		}
    	else if(root->val > r)
    		return dfs(root->left, l, r);
    	else if(root->val < l)
    		return dfs(root->right, l, r);
    	return root->val;
    }
};