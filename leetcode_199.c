


struct TreeNode {

	int val;
    struct TreeNode *left;
    struct TreeNode *right;

};

 
int maxDepth(struct TreeNode* root){

	if(root == NULL)
		return 0;
	int maxlen, rlen, llen;
	rlen = maxDepth(root->right);
	llen = maxDepth(root->left);
	if(rlen > llen)
		maxlen = rlen;
	else{
		maxlen = llen;
	}

	maxlen = maxlen + 1;

	return maxlen;

}




int traversal(struct TreeNode* root, int* value, int nowDepth, int depth){

	int isFound = 0;
 	if(root == NULL)
 		return 0;

 	if(nowDepth != depth){

 		//找右子樹
 		isFound = traversal(root->right, value, nowDepth + 1, depth);

 		//找右子樹
 		if(isFound == 0){

 			isFound = traversal(root->left, value, nowDepth + 1, depth);
                    
            if(isFound == 0){
                return 0;
            }
        }			

        return 1;
 	}

 	else if(nowDepth == depth){

 		*value = root->val;
 		return 1;
        
 	}
    
    //當初漏掉這個 無法return
    return 0;
}


int* rightSideView(struct TreeNode* root, int* returnSize){
    
    int depth, x, i, value = 0;

    depth = maxDepth(root);
    int *arr = (int *)malloc(sizeof(int) * depth);

    for(i=1;i<=depth;i++){
    	x = traversal(root, &value, 1, i);
    	arr[i-1] = value;
    }
    
    *returnSize = depth;
    return arr;

}

