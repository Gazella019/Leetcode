


class Solution {
public:
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
    	
    	if(root == NULL)
    		return {NULL, NULL};
    	vector<TreeNode*> res = {NULL, NULL};
    	vector<TreeNode*> temp;

    	if(root->val > V){
    		res[1] = root;
    		temp = splitBST(root->left, V);
    		res[1]->left = temp[1];
    		res[0] = temp[0];
    	}
    	else if(root->val <= V){
    		res[0] = root;
    		temp = splitBST(root->right, V);
    		res[0]->right = temp[0];
    		res[1] = temp[1];
    	}
    	return res;
    }
};


class Solution {
public:
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
    
    	vector<TreeNode*> res;

    	if(root == NULL)
    		return {NULL, NULL};

    	if(root->val == V){
    		TreeNode* node = root->right;
    		root->right = NULL;
    		res.push_back(root);
    		res.push_back(node);
    		return res;
    	}

    	TreeNode *small = NULL, *big = NULL;
    	TreeNode *h1, *h2;
    	traversal(res, h1, h2, small, big, root, V);
    	return res;
    }

    void traversal(vector<TreeNode*> &res, TreeNode *h1, TreeNode *h2, TreeNode *small, TreeNode *big, TreeNode *root, int V){
    	
    	if(root == NULL){

    		if(big != NULL)
    			big->left = NULL;
    		if(small != NULL)
    			small->right = NULL;
    		res.push_back(h1);
    		res.push_back(h2);
    		return;
    	}

    	if(V < root->val){
    		if(big != NULL){
    			big->left = root;
    			big = big->left;
    		}
    		else{
    			big = root;
    			h2 = big;
    		}
    		traversal(res, h1, h2, small, big, root->left, V);
    	}
    	else if(V > root->val){
    		if(small != NULL){
    			small->right = root;
    			small = small->right;
    		}
    		else{
    			small = root;
    			h1 = small;
    		}
    		traversal(res, h1, h2, small, big, root->right, V);
    	}
    	else if(V == root->val){

    		if(big == NULL){
    			big = root->right;
    			h2 = big;
    		}
    		else
    			big->left = root->right;
    		root->right = NULL;
    		if(small == NULL){
    			small = root;
    			h1 = small;
    		}
    		else
    			small->right = root;
    		res.push_back(h1);
    		res.push_back(h2);
    		return;
    	}
    }   
};