



class Solution {
public:
	int res = 0;
    int longestZigZag(TreeNode* root){

    	if(root == NULL)
    		return 0;
        traversal(root, 1, 0);

        return res;
    }

    void traversal(TreeNode* root, int prev, int cnt){
    	if(root == NULL){
    		res = max(res, cnt-1);
    		return;
    	}
    	if(prev == 1){
    		traversal(root->left, 1, 1);
    		traversal(root->right, 2, cnt+1);
    	}
    	else if(prev == 2){
    		traversal(root->left, 1, cnt+1);
    		traversal(root->right, 2, 1);
    	}
    }
};