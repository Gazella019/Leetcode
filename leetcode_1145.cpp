



class Solution {
public:
	int sum;
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        
        TreeNode *xNode;
        xNode = findNode(root, x);

    	sum = 0;
    	treeSum(root, x);
    	if(sum > n-sum)
    		return true;

    	sum = 0;
    	treeSum(xNode->left, x);
    	if(sum > n-sum)
    		return true;

    	sum = 0;
    	treeSum(xNode->right, x);
    	if(sum > n-sum)
    		return true;
    	return false;
    }

    TreeNode* findNode(TreeNode* root, int x){
    	TreeNode *l, *r;
    	if(root == NULL)
    		return NULL;
    	if(root->val == x)
    		return root;
    	l = findNode(root->left, x);
    	r = findNode(root->right, x);
    	if(l == NULL && r == NULL)
    		return NULL;
    	if(l == NULL)
    		return r;
    	return l;
    }

    void treeSum(TreeNode* root, int x){
    	if(root == NULL || root->val == x)
    		return;
    	sum += 1;
    	treeSum(root->left, x);
    	treeSum(root->right, x);
    }

};