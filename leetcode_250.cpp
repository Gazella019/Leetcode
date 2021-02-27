


class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {
        vector<int> res;
        res = count(root);
        return res[0];
    }

    vector<int> count(TreeNode* root){
    	if(root == NULL)
        	return {0, 1};
        int cnt;
        vector<int> l;
        vector<int> r;
        l = count(root->left);
        r = count(root->right);
        cnt = l[0] + r[0];
        if(l[1] == 1 && r[1] == 1){
        	if(root->left != NULL && root->left->val != root->val)
        		return {cnt, 0};
        	if(root->right != NULL && root->right->val != root->val)
        		return {cnt, 0};
        	return {cnt+1, 1};
        }
        else
        	return {cnt, 0};
    }
};