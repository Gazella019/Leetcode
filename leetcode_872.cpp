




struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        vector<int> v2;
        traversal(root1, v1);
        traversal(root2, v2);
        if(v1.size() != v2.size())
        	return false;
        for(int i=0;i<v1.size();i++){
        	if(v1[i] != v2[i])
        		return false;
        }
        return true;
    }

    void traversal(TreeNode* root, vector<int>& v){
    	if(root == NULL)
    		return;
    	if(root->left == NULL && root->right == NULL)
    		v.push_back(root->val);
    	traversal(root->left, v);
    	traversal(root->right, v);
    }
};