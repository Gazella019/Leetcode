



class Solution {
public:

	int res = 0;

    int longestConsecutive(TreeNode* root) {
        
        if(root == NULL)
        	return 0;
        traversal(root, 1);

        return res;
    }


    void traversal(TreeNode* root, int count){

    	if(root == NULL){
    		res = max(res, count);
    		return;
    	}

    	if(root->left != NULL && root->left->val == root->val+1){
    		traversal(root->left, count+1);
    	}
    	else
    		traversal(root->left, 1);

    	if(root->right != NULL && root->right->val == root->val+1){
    		traversal(root->right, count+1);
    	}
    	else
    		traversal(root->right, 1);
    	res = max(res, count);
    }
};