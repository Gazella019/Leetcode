

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    	if(K == 0)
    		return {target->val};
    	vector<vector<int>> graph(501);
    	vector<int> res;
    	vector<int> visited(501, 0);
    	int node = target->val;
    	bulid(root, graph);
    	visited[node] = 1;
    	dfs(graph, res, visited, node, 1, K);
    	return res;
    }

    void bulid(TreeNode* root, vector<vector<int>>& graph){
    	if(root == NULL)
    		return;
    	if(root->left != NULL){
    		graph[root->val].push_back(root->left->val);
    		graph[root->left->val].push_back(root->val);
    		bulid(root->left, graph);
    	}
    	if(root->right != NULL){
    		graph[root->val].push_back(root->right->val);
    		graph[root->right->val].push_back(root->val);
    		bulid(root->right, graph);
    	}
    }

    void dfs(vector<vector<int>>& graph, vector<int>& res, vector<int>& visited, int n, int dist, int depth){
    	for(int i=0;i<graph[n].size();i++){
    		if(dist == depth && visited[graph[n][i]] == 0)
    			res.push_back(graph[n][i]);
    		else if(visited[graph[n][i]] == 0){
    			visited[graph[n][i]] = 1;
    			dfs(graph, res, visited, graph[n][i], dist+1, depth);
    		}
    	}
    }
};



class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    	vector<int> res;
    	int depth;
    	depth = findDepth(root, target, 0);
    	cout << "depth is " << depth << endl;
    	traversal(root, target, res, K-depth);
    	return res;
    }

    int findDepth(TreeNode* root, TreeNode* target, int depth){
    	if(root == NULL)
    		return 0;
    	if(root == target)
    		return depth;
    	int l, r;
    	l = findDepth(root->left, target, depth+1);
    	r = findDepth(root->right, target, depth+1);
    	return max(l, r);
    }

    void traversal(TreeNode* root, TreeNode* target, vector<int>& res, int dist){
    	if(root == NULL)
    		return;
    	find(root, target, res, dist, 0);
    	if(root == target)
    		return;
    	traversal(root->left, target, res, dist+1);
    	traversal(root->right, target, res, dist+1);
    	
    }

    void find(TreeNode* root, TreeNode* target, vector<int>& res, int depth, int dist){
    	if(root == NULL || depth < 0 || root == target)
    		return;
    	if(dist == depth){
    		res.push_back(root->val);
    		return;
    	}
    	find(root->left, target, res, depth, dist+1);
    	find(root->right, target, res, depth, dist+1);
    }
};

