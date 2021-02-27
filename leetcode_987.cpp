




class Solution {
public:
	int lMost = 0, rMost, depth;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
    	
    	vector<vector<int>> res;
    	unordered_map<int, unordered_map<int, vector<int>>> hash;
    	traversal(root, hash, 0, 0);

    	for(int i=lMost;i<=rMost;i++){
    		vector<int> v;
    		for(int j=0;j<=depth;j++){
    			if(hash[i][j].size() > 0){
    				sort(hash[i][j].begin(), hash[i][j].end());
 					for(int k=0;k<hash[i][j].size();k++){
 						v.push_back(hash[i][j][k]);
 					}
    			}
    		}
    		res.push_back(v);
    	}
    	return res;
    }

    void traversal(TreeNode* root, unordered_map<int, unordered_map<int, vector<int>>>& hash, int x, int y){
    	if(root == NULL)
    		return;
    	hash[x][y].push_back(root->val);
    	lMost = min(lMost, x);
    	rMost = max(rMost, x);
    	depth = max(depth, y);
    	traversal(root->left, hash, x-1, y+1);
    	traversal(root->right, hash, x+1, y+1);

    }
};