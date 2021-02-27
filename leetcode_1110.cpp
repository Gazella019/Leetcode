

class Solution {
public:
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        vector<TreeNode*> res;
        bool insert = true;
        for(int i=0;i<to_delete.size();i++){
        	if(to_delete[i] == root->val)
        		insert = false;
        }
        if(insert)
        	res.push_back(root);
        del(root, to_delete, res);
        return res;
    }

    TreeNode* del(TreeNode* root, vector<int>& to_delete, vector<TreeNode*>& res){
    	if(root == NULL)
    		return NULL;
    	TreeNode *l, *r;
    	l = del(root->left, to_delete, res);
    	r = del(root->right, to_delete, res);
    	root->left = l;
    	root->right = r;
    	for(int i=0;i<to_delete.size();i++){
    		if(to_delete[i] == root->val){
    			if(l != NULL)
    				res.push_back(l);
    			if(r != NULL)
    				res.push_back(r);
    			return NULL;
    		}
    	}
    	return root;
    }
};