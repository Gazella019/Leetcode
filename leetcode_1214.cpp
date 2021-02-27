


class Solution {
public:

	bool res = false;
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        
    	unordered_map<int, int> hash;
    	build(root1, hash, target);
    	check(root2, hash);
    	return res;
    }

    void build(TreeNode* root, unordered_map<int, int>& hash, int target){
    	if(root == NULL)
    		return;
    	build(root->left, hash, target);
    	hash[target-root->val] = 1;
    	build(root->right, hash, target);

    }
    void check(TreeNode* root, unordered_map<int, int>& hash){
    	if(res == true || root == NULL)
    		return;
    	if(hash[root->val] == 1){
    		res = true;
    		return;
    	}
    	check(root->left, hash);
    	check(root->right, hash);
    }
};