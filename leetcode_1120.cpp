




class Solution {
public:
	double mx = 0;
    double maximumAverageSubtree(TreeNode* root) {
        
    	dfs(root);
    	return mx;
    }

    pair<int, int> dfs(TreeNode* root){
    	if(root == NULL)
    		return {0, 0};
    	auto l = dfs(root->left);
    	auto r = dfs(root->right);
    	double val;
    	val = double(l.first + r.first + root->val) / double(l.second + r.second + 1);
		mx = max(mx, val);
		return {l.first + r.first + root->val, l.second + r.second + 1}; 
    }
};