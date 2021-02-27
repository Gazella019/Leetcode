




struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
    	if(d == 1){
    		TreeNode *newNode = new TreeNode(v);
    		newNode->left = root;
    		return newNode;
    	}
    	int level = 1;
        traversal(root, level, v, d);
        return root;
    }

    void traversal(TreeNode* root, int level, int v, int d){
    	if(root == NULL)
    		return;
    	if(level == d-1){
    		TreeNode *l, *r;
    		l = root->left;
    		r = root->right;
    		TreeNode *newR = new TreeNode(v);
    		TreeNode *newL = new TreeNode(v);
    		newL->left = l;
    		newR->right = r;
    		root->left = newL;
    		root->right = newR;
    	}

    	traversal(root->left, level+1, v, d);
    	traversal(root->right, level+1, v, d);
    }
};