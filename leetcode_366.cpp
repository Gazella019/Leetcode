





class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
                
        int h;	
        h = height(root);
        vector<vector<int>> res(h);
        minHeight(root, res);
        return res;
    }

    void minHeight(TreeNode* root, vector<vector<int>>& res){
    	if(root == NULL)
    		return;
    	int index;
    	index = height(root);
    	res[index-1].push_back(root->val);
    	minHeight(root->left, res);
    	minHeight(root->right, res);
    }

    int height(TreeNode *root){
    	if(root == NULL)
    		return 0;
    	return max(height(root->left), height(root->right))+1;
    }

};