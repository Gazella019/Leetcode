


class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        
        vector<int> v;
        preorder(root, v);
        TreeNode *head;
        head = balacned(v, 0, v.size()-1);
        return head;
    }

    TreeNode* balacned(vector<int>& v, int l, int r){
    	if(r < l)
    		return NULL;
    	int mid = (l+r)/2;
    	TreeNode *node = new TreeNode(v[mid]);
    	node->left = balacned(v, l, mid-1);
    	node->right = balacned(v, mid+1, r);
    	return node;
    }


    void preorder(TreeNode* root, vector<int>& v){
    	if(root == NULL)
    		return;
    	preorder(root->left, v);
    	v.push_back(root->val);
    	preorder(root->right, v);
    }
};