



class Solution {
public:
	
	int res;
	vector<long long> leftMost;
    int widthOfBinaryTree(TreeNode* root) {

    	int i;
        dfs(root, 1, 0);

        return res;
    }

    void dfs(TreeNode* root, long long n, int depth){
    	if(root == NULL)
    		return;
    	if(leftMost.size() == depth){
    		leftMost.push_back(n);
    	}
    	if(res < n-leftMost[depth]+1)
    		res = n-leftMost[depth]+1;
    	dfs(root->left, n*2, depth+1);
    	dfs(root->right, (n*2)+1, depth+1);

    }
};