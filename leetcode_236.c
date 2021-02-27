#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int pows(int x){

    int result=1;
    for(int i=1;i<=x; i++){
        result = result * 2;
    }
    return result;
}
 
int maxDepth(struct TreeNode* root){

    if(root == NULL)
        return 0;

    int r,l,max;
    
    r = maxDepth(root->right);
    l = maxDepth(root->left);

    if( r > l ){
        max = r;
    }
    else{
        max = l;
    }

    return max + 1;
}

struct TreeNode* Traversal(struct TreeNode* root, int target){

    struct TreeNode* ancestor = NULL;
    if(root == NULL)
        return NULL;
    if(root->val == target)
        ancestor = root;
    else{
        ancestor = Traversal(root->left, target);
        if(ancestor == NULL)
            ancestor = Traversal(root->right, target);
    }

    return ancestor;
}


void constructArr(struct TreeNode* root, int *arr, int *loc, int index, int pval, int qval){

    if(root == NULL)
        return;

    arr[index] = root->val;

    if(root->val == pval){
        loc[0] = index;
    }
    else if(root->val == qval){
        loc[1] = index;
    }
    constructArr(root->left, arr, loc, index*2, pval, qval);
    constructArr(root->right, arr, loc, index*2 + 1, pval, qval);

}


struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    
    int depth, i, size = 0, pval, qval, big, small, result, temp;
    struct TreeNode *ancestor = NULL;
    pval = p->val;
    qval = q->val;
    depth = maxDepth(root);

    for(i=1;i<=depth;i++){
        size = size + pows(i);
    }

    int *arr = (int *) malloc((size+1)* sizeof(int));
    int *loc = (int *) malloc( 2* sizeof(int));

    constructArr(root, arr , loc, 1, pval ,qval);

    //printf("p in %d, q in %d\n", loc[0], loc[1]);

    if(loc[0]>loc[1]){
        big = loc[0];
        small = loc[1];
    }else{
        big = loc[1];
        small = loc[0];
    }

    // 找出兩個 node 的 ancestor index, 存進 result
    while(1){
        if(big/2 == small/2){
            result = (big/2);
            break;
        }
        else if(big/2 == small){
            result = small;
            break;
        }
        if(big/2 < small){
            temp = small;
            small = big / 2;
            big = temp; 
        }
        else{
            big = big / 2 ;
        }
    }
    

    //printf("The ancestor node is %d\n", arr[result]);
    ancestor = Traversal(root, arr[result]);
    //printf("Answer is %d\n", ancestor->val);

    return ancestor;
}



