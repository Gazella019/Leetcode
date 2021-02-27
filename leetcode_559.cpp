



class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int maxDepth(Node* root) {
    	int max = 0;
    	traversal(root, 1, &max);
    	return max;   
    }

    void traversal(Node* root, int depth, int *max){
    	if(root == NULL)
    		return;
    	if(depth > *max)
    		*max = depth;
    	for(int i=0;i<root->children.size();i++){
    		traversal(root->children[i], depth + 1, max);
    	}
    }
};