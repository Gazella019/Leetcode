




struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
    	if(preorder.size() == 0)
    		return NULL;
    	int i;
    	TreeNode* root = new TreeNode(preorder[0]);
    	for(i=1;i<preorder.size();i++){
    		root = constructTree(root, preorder[i]);
    	}

    	return root;
    }

    TreeNode* constructTree(TreeNode* root, int value){

    	if(root == NULL){
    		TreeNode* newNode = new TreeNode(value);
    		return newNode;
    	}

    	if(value > root->val)
    		root->right = constructTree(root->right, value);
    	else
    		root->left = constructTree(root->left, value);
    	return root;
    }	
};



class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
    	int i=0;
    	TreeNode* root = new TreeNode(preorder[i]);
    	i ++;
     	constructTree(root, preorder, &i);
     	return root;
    }

    void constructTree(TreeNode* parent, vector<int>& preorder, int *i){

    	if(i >= preorder.size())
    		return;
    	int n = *i;
    	if(preorder[n] < parent->val){
    		TreeNode* newNode = new TreeNode(preorder[i]);
    		parent->left = newNode;
    		*i = n + 1;
    		constructTree(newNode, preorder, i);
    	}
    	n = *i;
		if(preorder[n] > parent->val)    	
    		TreeNode& newNode = new TreeNode(preorder[i]);
    		parent->right = newNode;
    		*i = n + 1;
    		constructTree(newNode, preorder, i);
    	}

    }
};

