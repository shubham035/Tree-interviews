/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

/*
complete binary tree

2 nd last level completely filled
last level if not filled completely then node is from left to right:
if(last level is filled) yhen this called perfect binary tree:

each node except leaf node must have either 2 children or 0 children
*/

int helper_right(Tree * root , int level){

    while(root!=nullptr){
        root=root->right;
        level++;
    }
    return level;
}

int helper_left(Tree * root , int level){

    while(root!=nullptr){
        root=root->left;
        level++;
    }
    return level;
}

int solve(Tree* root) {
    // naive approach 
    // O(n) time complexity
    // bfs
    // queue<Tree*>q;
    // if(root==nullptr) return 0;
    // q.push(root);
    // int no=0;
    // while(!q.empty()){

    //     int n=q.size();
    //     no+=n;
    //     for(int i=0;i<n;i++){
    //         Tree* curr=q.front();
    //         q.pop();
    //         if(curr->left){
    //             q.push(curr->left);
    //         }
    //         if(curr->right){
    //             q.push(curr->right);
    //         }
    //     }
    // }
    // return no;
    // but we didn't use anything about complete binary tree:

// optimised approach:
// O(log(n)^2)

if(root==nullptr) return 0;

    int left=helper_left(root->left,1);
    int right=helper_right(root->right,1);

    if(left==right){
        // means level on both extremes are equal so must be a perfect binary tree

        return pow(2,(left))-1;
    }
    else{
        // not  perfect binary tree
        // we call for left and right children
       return solve(root->left)+solve(root->right)+1;
    }


}