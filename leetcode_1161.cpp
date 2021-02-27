



struct TreeNode {
    int val; 
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
    	int i, depth, max, loc;
    	depth = maxDepth(root);
    	vector<int> v(depth, 0);
    	traversal(root, v, 0);
    	max = v[0];
    	loc = 0;
    	for(i=1;i<depth;i++){
    		if(v[i]>max){
    			max = v[i];
    			loc = i;
    		}
    	}
    	return loc+1;
    }
    int maxDepth(TreeNode* root){
    	if(root == NULL)
    		return 0;
    	return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

    void traversal(TreeNode* root, vector<int> &v, int level){
    	if(root == NULL)
    		return;
    	v[level] = v[level] + root->val;
    	traversal(root->left, v, level+1);
    	traversal(root->right, v, level+1);

    }
};