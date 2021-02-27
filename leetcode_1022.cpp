


class Solution {
public:

    int res = 0;
    int sumRootToLeaf(TreeNode* root) {
        traversal(root, 0);
        return res;         
    }

    void traversal(TreeNode* root, int sum){
        if(root == NULL)
            return;
        if(root->left == NULL && root->right == NULL){
            sum = (sum*2) + root->val;
            res += sum;
            return;
        }
        sum = (sum * 2) + root->val;
        traversal(root->left, sum);
        traversal(root->right, sum);
    }
};