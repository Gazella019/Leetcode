

class Solution {
public:
	
    int maxSumBST(TreeNode* root) {
        int res = 0;
        dfs(root, &res);
        return res;
    }
    // sum isbst min max
    vector<int> dfs(TreeNode* root, int *res){
    	if(root == NULL)
    		return {0, 1, 40001, -40001};
    	int lmin, lmax, rmin, rmax, sum, cur;
    	auto l = dfs(root->left, res);
    	auto r = dfs(root->right, res);
    	cur = root->val;
    	rmin = r[2], rmax = r[3];
    	lmin = l[2], lmax = l[3];
    	sum = l[0] + r[0] + cur;
    	if(cur > lmax && cur < rmin && l[1] && r[1]){
    		*res = max(*res, sum);
    		return {sum, 1, min(cur, lmin), max(cur, rmax)};
    	}
    	return {0, 0, min(cur, lmin), max(cur, rmax)};
    }    
};



// TLE
class Solution {
public:
	int res = 0;
    int maxSumBST(TreeNode* root) {
        traversal(root);
        return res;
    }

    void traversal(TreeNode* root){
    	if(root == NULL)
    		return;
    	if(isBST(root, INT_MAX, INT_MIN)){
    		res = max(res, treeSum(root));
    	}
    	traversal(root->left);
    	traversal(root->right);
    }

    bool isBST(TreeNode* root, int upper, int lower){
    	if(root == NULL)
    		return true;
    	if(root->val > lower && root->val < upper){
    		return isBST(root->left, root->val, lower) && isBST(root->right, upper, root->val);
    	}
    	else
    		return false;
    }

    int treeSum(TreeNode* root){
    	if(root == NULL)
    		return 0;
    	return treeSum(root->left) + treeSum(root->right) + root->val;
    } 
};