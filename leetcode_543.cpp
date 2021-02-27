


class Solution {
public:

	int maxVal = 0;

	int diameter(TreeNode* root){

		if(root == 0)
			return -1;

		int l, r;

		l = diameter(root->left)+1;
		r = diameter(root->right)+1;

		maxVal = max(l+r, maxVal);

		return max(l, r);
	}

    int diameterOfBinaryTree(TreeNode* root) {

        int res = diameter(root);
        return maxVal;
    }
};








class Solution {
public:

	int maxVal = 0;

	int diameter(TreeNode* root){
		if(root->left == NULL && root->right == NULL)
			return 0;
		int l=-1, r=-1, val;
		if(root->left != NULL)
			l = diameter(root->left);
		if(root->right != NULL)
			r = diameter(root->right);
		maxVal = max(maxVal, l+r+2);

		return max(l, r)+1;
	}

    int diameterOfBinaryTree(TreeNode* root) {

    	if(root == NULL)
    		return 0;
        int res;
        res = diameter(root);
        return maxVal;
    }
};
