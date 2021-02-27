#include<stdio.h>
#include<stdlib.h>


 struct TreeNode {

    int val;
    struct TreeNode *left;
    struct TreeNode *right;

 };



struct TreeNode* invertTree(struct TreeNode* root){
    
    if(root == NULL){
		return;
	}
	else{

		struct TreeNode *temp;

		temp = root->right;
		root->right = root->left;
		root->left = temp;
	}

	invertTree(root->left);
	invertTree(root->right);
	
    return root;
}


void main(){


}
