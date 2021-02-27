



struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


int maxDepth(struct TreeNode* root){

	if(root == NULL)
		return 0;

	int r,l,max;
	
	r = maxDepth(root->right);
	l = maxDepth(root->left);

	if( r > l ){
		max = r;
	}
	else{
		max = l;
	}

	return max + 1;
}


void levelNode(struct TreeNode* root, int level, int **array, int* returnColumnSizes){

	if(root == NULL)
		return ;

	printf("%d, level = %d\n", root->val, level);
    
	returnColumnSizes[level - 1] ++;
    printf("level = %d, colsize = %d\n", level, returnColumnSizes[level -1]);
	
	array[level - 1][0] = root->val;

	levelNode(root->left, level + 1, array ,returnColumnSizes);
	levelNode(root->right, level + 1, array ,returnColumnSizes);

}


int** levelOrderBottom(struct TreeNode* root, int* returnSize, int* returnColumnSizes){

	if(root == NULL)
		return NULL;

	int row;
	row = maxDepth(root);
	*returnSize = row;

	int **arr = (int**) malloc(row * sizeof(int*));
	for(int i=0;i<row;i++){
		arr[i] = (int*) malloc(2000 * sizeof(int));
	}

	(*returnColumnSizes) = (int*) malloc(row * sizeof(int));


	levelNode(root, 1, arr, *returnColumnSizes);

    printf("The value is :%d",arr[2][0]);
	return arr;
   
}

