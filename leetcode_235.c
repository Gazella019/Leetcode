


//Its a BST !!!!!!!!!!;
//Its a BST !!!!!!!!!!;
//Its a BST !!!!!!!!!!;

struct TreeNode {
    int val;
    struct TreeNode *left;
   	struct TreeNode *right;
};


struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    
    int big, small;
    struct TreeNode* ancestor = NULL;

    if(root == NULL || p == NULL || q ==NULL)
    	return NULL;

    if(p->val > q->val){
    	big = p->val;
    	small = q->val;
    }
    else{
    	big = q->val;
    	small = p->val;
    }

    // p, q 都在左邊
    if(root->val > big){
    	ancestor = lowestCommonAncestor(root->left, p, q);
    }
    else{

    	// 一個在左 一個在右
    	if(root->val > small){
    		if(q == root)
    			ancestor = q;
    		else if(p == root)
    			ancestor = p;
    		else{
    			ancestor = root;
    		}
    	}
    	// 都在右邊
    	else{
    		if(q == root)
    			ancestor = q;
    		else if(p == root)
    			ancestor = p;
    		else{
    			ancestor = lowestCommonAncestor(root->right, p, q);
    		}
    	}
    }

    return ancestor;
}