#include <stdio.h>
int map[30][30];
int visited[30];
int my_queue[1005];
int q_front,q_rear;
int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        char src, des;
        scanf(" %c->%c", &src, &des);
        map[src - 'A'][des - 'A'] = 1;
    }
    char src, des;
    scanf(" %c %c", &src, &des);
    // bfs
    my_queue[q_rear++] = src - 'A';
    visited[src-'A'] = 1;
    while(q_rear >= q_front){
        int temp = my_queue[q_front++];
        for(int i = 0; i < 26; i++){
            if(map[temp][i] && !visited[i]) {
                visited[i] = 1;
                my_queue[q_rear++] = i;
            }
        }
    }
    if(visited[des-'A'])puts("Don't stay up too late!");
    else puts("Sorry!");
    return 0;
}