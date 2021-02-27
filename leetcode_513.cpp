



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int depth, num;
        bool isFind = false;
        depth = maxDepth(root);
        find(root, 1, depth, &num, &isFind);
        return num;
    }

    int maxDepth(TreeNode* root){
    	if(root == NULL)
    		return 0;

    	return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

    void find(TreeNode* root, int level, int depth, int *num, bool *isFind){
    	if(root == NULL)
    		return;
    	if(level == depth){
    		if(*isFind == false)
    			*num = root->val;
    		*isFind = true;
    		return;
    	}
    	find(root->left, level+1, depth, num, isFind);
    	find(root->right, level+1, depth, num, isFind);
    }
};