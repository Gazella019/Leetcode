


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// sol 二維陣列版本 DFS
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
    	int depth, i, j;
    	double sum;
    	depth = maxDepth(root);
    	vector<double> res;
        vector<vector<double>> s(depth);
        traversal(s, root, 0);
        for(i=0;i<depth;i++){
        	sum = 0;
        	for(j=0;j<s[i].size();j++){
        		sum = sum + s[i][j];
        	}
        	sum = sum / s[i].size();
        	res.push_back(sum);
        }
        return res;
    }

    void traversal(vector<vector<double>>& s, TreeNode* root, int level){
    	
    	if(root == NULL)
    		return;
    	s[level].push_back(root->val);
    	traversal(s, root->left, level+1);
    	traversal(s, root->right, level+1);

    }

    int maxDepth(TreeNode* root){
    	if(root == NULL)
    		return 0;
    	return max(maxDepth(root->right), maxDepth(root->left)) + 1;
    }

};


// sol 兩個一維陣列 DFS

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
    	int depth, i, j;
    	double sum;
    	depth = maxDepth(root);
    	vector<double> res;
        vector<double> s(depth, 0);
        vector<double> nums(depth, 0);

        traversal(s, nums, root, 0);
        for(i=0;i<depth;i++){
        	res.push_back(s[i]/nums[i]);
        }
        return res;
    }

    void traversal(vector<double>& s, vector<double>& nums, TreeNode* root, int level){
    	
    	if(root == NULL)
    		return;
    	s[level] = s[level] + root->val;
    	nums[level] = nums[level] + 1;
    	traversal(s, nums, root->left, level+1);
    	traversal(s, nums, root->right, level+1);

    }

    int maxDepth(TreeNode* root){
    	if(root == NULL)
    		return 0;
    	return max(maxDepth(root->right), maxDepth(root->left)) + 1;
    }

};


// BFS (not mine)

vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode *> q;
        vector<double> vc;
        double count, sum, storeCount;
        TreeNode *temp;
        q.push(root);
        
        while (!q.empty()) {
            count = q.size();
            storeCount = count;
            sum = 0;
            while (count--) {
                temp = q.front();
                q.pop();
                sum += temp->val;
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            vc.push_back(sum/storeCount);
        }
        return vc;
}