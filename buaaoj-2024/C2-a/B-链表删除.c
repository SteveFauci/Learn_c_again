#include <stdio.h>
#include <stdlib.h>
typedef struct _Node // 链表结构体
{
    int           data;
    struct _Node* next; // 指向下一个结点的指针
} Node, *List;

List read_list(int n) // 按输入格式读取链表
{
    List head = (List)malloc(sizeof(Node));
    List tail = head;
    for (int i = 0; i < n; ++i) {
        List node = (List)malloc(sizeof(Node));
        scanf("%d", &node->data);
        tail->next = node;
        tail = node;
    }
    tail->next = NULL;
    return head;
}

void del_by_index(List list, int k) {
    List ptr = list;
    for(int i = 1; i < k && ptr; i++){
        ptr = ptr->next;
    }
    if(ptr && ptr->next){
        List temp = ptr->next;
        ptr->next = temp->next;
        free(temp);
        puts("Success!");
        return;
    }else{
        puts("Fail!");
        return;
    }
}

void del_by_data(List list, int v) {
    List fast = list, slow = list;
    fast = list->next;
    while(fast){
        if(fast->data==v)break;
        fast = fast->next;
        slow = slow->next;
    }
    if(fast && fast->next){
        List temp = slow->next;
        slow->next = temp->next;
        free(temp);
        puts("Success!");
    }else{
        puts("Fail!");
    }
}

void print_list(List list) {
    for (List p = list->next; p; p = p->next)
        printf("%d ", p->data);
    putchar('\n');
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    List list = read_list(n);
    while (m--) {
        int op, x, data;
        scanf("%d%d", &op, &x);
        if (op == 1)
            del_by_index(list, x);
        else
            del_by_data(list, x);
    }
    print_list(list);
    return 0;
}