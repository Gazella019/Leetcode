#include <stdio.h>
#include <stdlib.h>


// Recursive 版本 , 遞迴版本

struct TreeNode {

    int val;
    struct TreeNode *left;
    struct TreeNode *right;

};
 
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int TotalNode(struct TreeNode *root){

	if(root == NULL){
		return 0;
	}
	else{
		int num = 0;
		num = TotalNode(root->left) + TotalNode(root->right) + 1;
		return num; 
	}

}



void traverse(struct TreeNode *root, int *arr, int *index){

	if(root == NULL){
		return;
	}

	traverse(root->left, arr, index);
	*index = *index + 1;
	arr[*index] = root->val;
 	traverse(root->right, arr, index);

}


int* inorderTraversal(struct TreeNode* root, int* returnSize){

	*returnSize = -1;
	int size, i;
	size = TotalNode(root);
    printf("%d\n",size);
	int *arr = (int*)malloc(sizeof(int) * size);

	traverse(root, arr, returnSize);
    *returnSize += 1;
	return arr; 
    
}


void main(){



}