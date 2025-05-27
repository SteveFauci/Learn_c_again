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
int  n, r, arr[10];
void dfs(int step) {
    if (step > r) {
        for (int i = 1; i <= r; i++) {
            printf("%3d", arr[i]);
        }
        puts("");
        return;
    }

    for (int i = arr[step - 1] + 1; i <= n; i++) {
        arr[step] = i;
        dfs(step + 1);
    }
}

int main() {
    scanf("%d%d", &n, &r);
    dfs(1);
    return 0;
}