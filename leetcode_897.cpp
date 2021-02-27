




struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
    	if(root == NULL)
    		return NULL;
        vector<int> v;
        traversal(root, v);
        TreeNode* node = new TreeNode(v[0]);
        TreeNode* head = node;
        for(int i=1;i<v.size();i++){
        	node->right = new TreeNode(v[i]);
        	node = node->right;
        }
        return head;
    }

   void traversal(TreeNode* root, vector<int>& v){
   		if(root == NULL)
   			return;
   		traversal(root->left, v);
   		v.push_back(root->val);
   		traversal(root->right, v);
   }
};