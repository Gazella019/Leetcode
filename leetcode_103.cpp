



struct TreeNode {
	int val;
    TreeNode *left;    
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:

	void treeTraversal(TreeNode* root, int level, vector<int> &v, vector<vector<int>> &vec){

		if(root == NULL)
			return;
		cout << "node: "<< root->val;
		if(level%2 == 1){
			treeTraversal(root->right, level+1, v, vec);
			treeTraversal(root->left, level+1, v, vec);
		}
		else{
			treeTraversal(root->left, level+1, v, vec);
			treeTraversal(root->right, level+1, v, vec);
		}

	}

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> v;
        treeTraversal(root, 1, v, vec);
        return v;
    }
};