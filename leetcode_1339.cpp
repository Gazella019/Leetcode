

class Solution {
public:

	long res = 0;
	long modulo = 1000000007;

    int maxProduct(TreeNode* root) {
        
    	long total;
    	total = treeSum(root);
    	traversal(root, total);
    	res = res%modulo;
    	return res;
    }

    long traversal(TreeNode* root, long total){
    	if(root == NULL)
    		return 0;
    	long product, sum;
    	sum = traversal(root->left, total)+traversal(root->right, total)+root->val;
    	product = (total-sum) * sum;
    	res = max(res, product);
    	//res = res%modulo;   ERROR is here!!!!

    	return sum;
    }

    long treeSum(TreeNode* root){
    	if(root == NULL)
    		return 0;
    	return treeSum(root->left) + treeSum(root->right) + root->val; 
    }
};