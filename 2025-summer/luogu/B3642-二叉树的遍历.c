#include<stdio.h>
#include<stdlib.h>
#define nullptr NULL
typedef struct my_node{
    int val;
    struct my_node* left;
    struct my_node* right;
}TreeNode;

TreeNode * createNode(int val){
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->val = val;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}

TreeNode * nodes[1000005];

void preorder_traverse(TreeNode *root){
    if(root)printf("%d ",root->val);
    if(root->left)preorder_traverse(root->left);
    if(root->right)preorder_traverse(root->right);
}
void inorder_traverse(TreeNode *root){
    if(root->left)inorder_traverse(root->left);
    if(root)printf("%d ",root->val);
    if(root->right)inorder_traverse(root->right);
}
void postorder_traverse(TreeNode *root){
    if(root->left)postorder_traverse(root->left);
    if(root->right)postorder_traverse(root->right);
    if(root)printf("%d ",root->val);
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        nodes[i] = createNode(i);
    }
    for(int i = 1; i <= n; i++){
        int l,r;
        scanf("%d%d",&l,&r);
        nodes[i]->left = nodes[l];
        nodes[i]->right = nodes[r];
    }
    preorder_traverse(nodes[1]);
    puts("");
    inorder_traverse(nodes[1]);
    puts("");
    postorder_traverse(nodes[1]);
    puts("");
    return 0;
}
