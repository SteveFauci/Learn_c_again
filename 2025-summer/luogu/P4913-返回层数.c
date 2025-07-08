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
// 用队列非递归
TreeNode* my_que[1000005];
int return_depth(TreeNode* root){
    int depth = 0;
    int front = 0,rear = -1;
    my_que[++rear] = root;

    while(rear != front - 1){
        int sz  = rear - front + 1;
        for(int i = 0; i < sz; i++){
            TreeNode*temp = my_que[front];
            if(temp->left) my_que[++rear] = temp->left;
            if(temp->right) my_que[++rear] = temp->right;
            front++;
        }
        depth++;
    }
    return depth;
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
    printf("%d\n",return_depth(nodes[1]));
    free_tree(nodes[1]);
    return 0;
}