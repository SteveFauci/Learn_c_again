#include <stdio.h>
#include <stdlib.h>

typedef struct prob {
    int          num;
    struct prob* next;
} List;
int main() {
    List *head, *c, *del;
    int   n, m;

    head = (List*)malloc(sizeof(List));
    //   head->next = NULL;
    c = head;

    scanf("%d%d", &n, &m);
    if (m == 1) {
        printf("%d\n", 1);
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        c->num = i;
        if (i < n) {
            c->next = (List*)malloc(sizeof(List));
            c = c->next;
        }
    }
    c->next = head;

    c = head;
    while (c->next != c) {
        for (int i = 1; i < m - 1; i++) {
            c = c->next;
        }
        del = c->next;
        c->next = del->next;
        c = c->next;
        free(del);
    }
    printf("%d\n", c->num);
    free(c);
}
// int m;
// int f(int i) {
//     if (i == 1)
//         return 0;
//     else
//         return (f(i - 1) + m) % i;
// }
// int main() {
//     int i;
//     scanf("%d%d", &i, &m);
//     printf("%d", f(i) + 1);
// }