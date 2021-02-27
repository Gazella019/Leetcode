#include <stdio.h>
#include <stdlib.h>


// 用減的方式

struct TreeNode {

	int val;
	struct TreeNode *left;
    struct TreeNode *right;

};

void searchTree(struct TreeNode* root, int num, bool *TF){

	// 要注意 root == NULL 情況
	if(root != NULL){

		if(root->right == NULL && root->left == NULL){	//Is a leaf
		if(root->val == num){
			*TF = true;
			return ; 
			}
		}
		else{

			int result, l, r;
			result = num - root->val;
			searchTree(root->left, result, TF);
			searchTree(root->right, result, TF);
		}
	}
	
}

bool hasPathSum(struct TreeNode* root, int sum){

	bool tf;
	searchTree(root, sum, &tf);
	return tf;

}





void main(){




}