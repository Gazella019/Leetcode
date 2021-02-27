#include <stdio.h>
#include <stdlib.h>



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



void main(){
	


}
