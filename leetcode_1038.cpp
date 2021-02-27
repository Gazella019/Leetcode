

// Runtime: 0 ms, faster than 100.00% of C++ 
// Memory Usage: 9.2 MB, less than 100.00% of C++ 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
    	if(root == NULL)
    		return NULL;
    	int sum = 0;
        traversal(root, &sum);
        return root;
    }

    void traversal(TreeNode* root, int* sum){
    	if(root == NULL)
    		return;
    	traversal(root->right, sum);
    	*sum = *sum + root->val;
    	root->val = *sum;
    	cout << *sum << " ";
    	traversal(root->left, sum);
    }
};