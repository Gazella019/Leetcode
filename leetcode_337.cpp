

class Solution {
public:

    int rob(TreeNode* root) {
        
        vector<int> res;
        res = traversal(root);
        return max(res[0], res[1]);
    }

    vector<int> traversal(TreeNode* root){

    	if(root == NULL)
    		return {0, 0};
    	vector<int> l;
    	vector<int> r;
    	int noRoot, hasRoot;
    	l = traversal(root->left);
    	r = traversal(root->right);

    	hasRoot = root->val + l[0] + r[0];
    	noRoot = max(l[0], l[1]) + max(r[0], r[1]);
    	return {noRoot, hasRoot};
    }
};




class Solution {
public:
    int rob(TreeNode* root) {
        
        int res;
        int i, j;
        i = traversal(root, true);
        j = traversal(root, false);
        res = max(i, j);
        cout << "hasRoot:" << j << " noRoot:" << i; 
        return res;
    }

    int traversal(TreeNode* root, bool hasRoot){

    	if(root == NULL)
    		return 0;
    	int l, r, nol, nor;
    	if(hasRoot == true){
    		nol = traversal(root->left, hasRoot);
    		nor = traversal(root->right, hasRoot);
    		l = traversal(root->left, !hasRoot);
    		r = traversal(root->right, !hasRoot);
    		return max(nol, l) + max(nor, r);
    	}
    	if(hasRoot == false){
    		l = traversal(root->left, !hasRoot);
    		r = traversal(root->right, !hasRoot);
    		return l+r+root->val;
    	}

    	return 0;
    }
};