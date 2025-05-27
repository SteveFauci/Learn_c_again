#include <stdio.h>
#include <stdlib.h>
typedef struct my_stru {
    union {
        char name[20];
        int  grade[5];
    } info;
    struct my_stru* next;
} TSI;

void free_list(TSI* head) {
    TSI* tmp;
    while (head != NULL) {
        tmp = head;        // 保存当前节点
        head = head->next; // 移动到下一个节点
        free(tmp);         // 释放当前节点
    }
}
int main() {
    int  N, i, j;
    char id;
    TSI *t_c, *t_head;
    TSI *s_c, *s_head;

    t_head = (TSI*)malloc(sizeof(TSI));
    t_head->next = NULL;
    t_c = t_head;

    s_head = (TSI*)malloc(sizeof(TSI));
    s_head->next = NULL;
    s_c = s_head;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf(" %c", &id);
        if (id == 'S') {
            for (int j = 0; j < 5; j++)
                scanf("%d", &(s_c->info.grade[j]));
            s_c->next = (TSI*)malloc(sizeof(TSI));
            s_c = s_c->next;
            s_c->next = NULL;
        } else if (id == 'T') {
            scanf(" %s", t_c->info.name);
            t_c->next = (TSI*)malloc(sizeof(TSI));
            t_c = t_c->next;
            t_c->next = NULL;
        }
    }

    t_c = t_head;
    s_c = s_head;

    while (s_c->next != NULL) {
        for (int i = 0; i < 5; i++) {
            printf("%d ", s_c->info.grade[i]);
        }
        puts("");
        s_c = s_c->next;
    }
    while (t_c->next != NULL) {
        puts(t_c->info.name);
        t_c = t_c->next;
    }
    free_list(s_head);
    free_list(t_head);
}