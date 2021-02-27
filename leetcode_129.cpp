



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0, res = 0;
        traversal(root, sum, &res);
        return res;
    }

    void traversal(TreeNode* root, int sum, int* res){
    	if(root == NULL)
    		return;
    	if(root->left == NULL && root->right == NULL){
    		sum = (sum * 10) + root->val;
    		*res = *res + sum;
    		return;
    	}
    	traversal(root->left, sum*10 + root->val, res);
    	traversal(root->right, sum*10 + root->val, res);
    }
};