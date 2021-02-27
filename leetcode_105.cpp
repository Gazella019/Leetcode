





struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    	if(inorder.size() == 0)
    		return NULL;
    	TreeNode *root = new TreeNode(preorder[0]);
    	int p = 1, i;
    	for(i=0;i<inorder.size();i++){
    		if(inorder[i] == preorder[0])
    			break;
    	}
    	root->left = build(root, preorder, inorder, 0, i-1, &p);
    	root->right = build(root, preorder, inorder, i+1, inorder.size()-1, &p);
    	return root;
    }

    TreeNode* build (TreeNode* root, vector<int>& preorder,  vector<int>& inorder, int l, int r, int* p){
    	//cout << "l = " << l << " r= " << r << " p= "<< *p << endl;
    	if(l>r || *p >= inorder.size())
    		return NULL;
    	if(l == r){
    		TreeNode *newNode = new TreeNode(inorder[l]);
    		*p = *p + 1;
    		return newNode;
    	}
    	int i;
    	TreeNode *newNode;
    	for(i=l;i<=r;i++){
    		if(inorder[i] == preorder[*p]){
    			//cout << "root is " << inorder[i] << endl;
    			newNode = new TreeNode(inorder[i]);
    			*p = *p + 1;
    			newNode->left = build(newNode, preorder, inorder, l, i-1, p);
    			newNode->right = build(newNode, preorder, inorder, i+1, r, p);
    			break;
    		}
    	}
    	return newNode;
    }
};