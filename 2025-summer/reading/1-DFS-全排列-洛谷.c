#include <stdio.h>
// void dfs(int step){
//     if(到达目的地){//返回条件的判定
//          输出解;
//          返回;
//     }
//     合理的剪枝操作;
//     for(int i = 1; i <= 枚举数; i++){
//         if(满足条件){
//              更新状态位;
//              dfs(step+1);
//              恢复状态位;
//         }
//     }
// }
int  n, arr[10], book[10];
void dfs(int step) {
    if (step == n) { // 返回条件的判定。搜索到最下一层输出arr
        for (int i = 0; i < n; i++) {
            printf("%5d", arr[i]);
        }
        puts("");
        return;
    }
    for (int i = 1; i <= n; i++) {//长得有点像二叉树的中序遍历
        if (book[i] == 0) {
            arr[step] = i;  //从i=0遍历，哪个数没用过，就把他放进arr
            book[i] = 1;    //标记一下这个数用过了，book[4]==1表示4用过了
            dfs(step + 1);//往下一层搜索
            book[i] = 0;    
        }
    }
}
int main() {
    scanf("%d", &n);
    dfs(0);
    return 0;
}