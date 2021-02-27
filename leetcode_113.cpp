




struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

	void traversal(TreeNode* root, int num, int target, int level, int depth, vector<int> &v, vector<vector<int>> &vec){

    	if(root == NULL)
    		return;
    	// Leaf
    	if(root->left == NULL && root->right == NULL){
    		if(num + root->val == target){
    			v[level-1] = root->val;
    			if(level < depth){
    				vector<int> temp;
    				for(int i=0;i<level;i++){
    					temp.push_back(v[i]);
    				}
    				vec.push_back(temp);
    			}
    			else{
    				vec.push_back(v);
    			}
    		}
    		return;
    	}
    	v[level-1] = root->val;
    	traversal(root->left, num+root->val , target, level+1, depth, v, vec);
    	traversal(root->right, num+root->val , target, level+1, depth, v, vec);

    }

    int maxDepth(TreeNode* root){
    	if(root == NULL)
    		return 0;
    	int r, l;
    	l = maxDepth(root->left);
    	r = maxDepth(root->right);

    	return max(r, l) + 1;
    }


    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
        int depth;
        depth = maxDepth(root);
        vector<int> v(depth,0);
        vector<vector<int>> vec;
        traversal(root, 0, sum, 1, depth, v, vec);
        return vec;
    }
};