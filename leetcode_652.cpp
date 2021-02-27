


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    	vector<TreeNode*> v;    
    	queue<TreeNode*> q;
    	TreeNode* node;
    	if(root == NULL)
    		return v;
    	traversal(v, root->left, root);
    	traversal(v, root->right, root);
    	for(int i=0;i<v.size();i++){
    		addSub(v, v[i]->left);
    		addSub(v, v[i]->right);
    	}
    	for(int i=0;i<v.size();i++){
    		for(int j=i+1;j<v.size();j++){
    			if(isSame(v[i], v[j])){
    				v.erase(v.begin()+j, v.begin()+j+1);
    				j = j-1;
    			}
    		}
    	}
    	return v;
    }

    void traversal(vector<TreeNode*>& v, TreeNode* node, TreeNode* root){
    	if(node == NULL || root == NULL)
    		return;
    	int count = 0;
    	findSub(root, node, &count);
    	if(count >= 2){
    		v.push_back(node);
    		return;
    	}
    	traversal(v, node->left, root);
    	traversal(v, node->right, root);
    }

    void findSub(TreeNode* root, TreeNode* sub, int *count){
    	if(root == NULL)
    		return;
    	if(isSame(root, sub))
    		*count = *count + 1;
    	findSub(root->left, sub, count);
    	findSub(root->right, sub, count);
    }

    bool isSame(TreeNode* t1, TreeNode* t2){
    	if(t1 == NULL && t2 == NULL)
    		return true;
    	if(t1 == NULL || t2 == NULL)
    		return false;
    	if(t1->val == t2->val){
    		if(isSame(t1->right, t2->right) && isSame(t1->left, t2->left))
    			return true;
    	}
    	return false;
    }

    void addSub(vector<TreeNode*>& v, TreeNode* root){
    	if(root == NULL)
    		return;
    	v.push_back(root);
    	addSub(v, root->left);
    	addSub(v, root->right);
    }
};