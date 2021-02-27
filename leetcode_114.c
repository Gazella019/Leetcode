




struct TreeNode {
	int val;
    struct TreeNode *left;
    struct TreeNode *right;
}; 


struct TreeNode* getBottom(struct TreeNode* root){

	struct TreeNode *node;

	if(root->right == NULL){
		return root;
	}
	else{

		node = getBottom(root->right);
	}

	return node;
}


void printTree(struct TreeNode* root){

	if(root == NULL)
		return;

	printf("%d ", root->val);
	printTree(root->right);
	
}


void flatten(struct TreeNode* root){

	if(root == NULL)
		return;
	// Leaf
	if(root->left == NULL && root->right == NULL)
		return;

	if(root->left != NULL){
		flatten(root->left);
	}
	if(root->right != NULL){
		flatten(root->right);
	}

	struct TreeNode *lBottom, *lnode;


    // 左子樹不是null
	if(root->left != NULL){

		lBottom = getBottom(root->left);
		lBottom->right = root->right;
		root->right = root->left;
		root->left = NULL;
	}

	//printTree(root);
}



