




class Solution {
public:
	int prev = 0, res = INT_MAX;

    int minDiffInBST(TreeNode* root) {
        
    	traversal(root);
    	return res;
    }

    void traversal(TreeNode* root){
    	if(root == NULL)
    		return;

    	traversal(root->left);
    	if(prev != 0)
    		res = min(res, abs(root->val-prev));
    	prev = root->val;
    	traversal(root->right);
    }


};
