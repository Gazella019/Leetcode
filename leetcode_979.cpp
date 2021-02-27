


class Solution {
public:
	int res;
    int distributeCoins(TreeNode* root) {
        if(root == NULL)
        	return 0;
        int total;
        total = traversal(root);
        return res;
    }

    int traversal(TreeNode* root){

    	if(root == NULL)
    		return 0;
    	int l, r, num;
    	l = traversal(root->left);
    	r = traversal(root->right);
    	res = res + abs(l) + abs(r);
    	
    	return l+r+root->val-1;
    }
};



class Solution {
public:
	int res;
    int distributeCoins(TreeNode* root) {
        if(root == NULL)
        	return 0;
        int total;
        total = traversal(root);
        return res;
    }

    int traversal(TreeNode* root){

    	if(root == NULL)
    		return 0;
    	int l, r, num;
    	l = traversal(root->left);
    	r = traversal(root->right);
    	num = l+r;
    	res = res + abs(l) + abs(r);
    	if(root->val == 0)
    		return num-1;
    	if(root->val >= 2)
    		return num + (root->val-1);
    	return num;
    }
};