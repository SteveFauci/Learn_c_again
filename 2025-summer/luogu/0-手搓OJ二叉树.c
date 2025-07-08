#include<stdio.h>
#include<stdlib.h>
#define nullptr NULL
typedef struct my_struct{
    int val;
    struct my_struct *left;
    struct my_struct *right;
}TreeNode;

TreeNode* createNode(int val){
    TreeNode*temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->val = val;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}

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

TreeNode* my_que[1000005];
void level_order_traverse(TreeNode* root){
    int front = 0,rear = -1;
    my_que[++rear] = root;

    while(rear != front - 1){
        TreeNode*temp = my_que[front];
        if(temp->left) my_que[++rear] = temp->left;
        if(temp->right) my_que[++rear] = temp->right;
        printf("%d ",temp->val);
        front++;
    }
}
// 可选：释放内存
void free_tree(TreeNode* root) {
    if (root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

TreeNode* nodes[1000005];
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
        nodes[i]->right= nodes[r];
    }
    puts("Preorder:");
    preorder_traverse(nodes[1]);
    puts("");
    puts("Inorder:");
    inorder_traverse(nodes[1]);
    puts("");
    puts("Postorder:");
    postorder_traverse(nodes[1]);
    puts("");
    puts("Levelorder:");
    level_order_traverse(nodes[1]);
    puts("");
//  free_tree(nodes[1]);
    return 0;
}