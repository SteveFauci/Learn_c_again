#include <stdio.h>
#include <stdlib.h>
typedef struct _Node // 链表结构体
{
    int data;
    struct _Node* next;  // 指向下一个结点的指针
} Node, *List;

List read_list(int n) // 按输入格式读取链表
{
    List head = (List)malloc(sizeof(Node));
    List tail = head;
    for(int i = 0; i < n; ++i)
    {
        List node = (List)malloc(sizeof(Node));
        scanf("%d", &node->data);
        tail->next = node;
        tail = node;
    }
    tail->next = NULL;
    return head;
}

void insert_by_index(List list, int k, int data) // 在链表的第k个元素后插入值为data的新元素
{
    List p = list;
    for(int i = 0; p && i < k; ++i)
        p = p->next;
    // 此时指针 p 指向了链表中的第 k 个元素
    if(p != NULL)
    {
        // 插入新节点
        List temp = (List)malloc(sizeof(List));
        temp->next = p->next;
        p->next = temp;
        temp->data = data;
        puts("Success!");
    }
    else
        puts("Fail!");
}

void insert_by_data(List list, int v, int data) // 在链表的第一个值为v的元素后插入值为data的新元素
{
    // 先将指针 p 指向了链表中的第一个值为v的元素
    List p = list;
    while(p){
        if(p->data == v){
            break;
        }
        p = p->next;
    }
    // 若找到值为v的元素，则插入新结点，输出"Success!"；否则，只需输出"Fail!"
    if(p){
        List temp = (List)malloc(sizeof(List));
        temp->next = p->next;
        p->next = temp;
        temp->data = data;
        puts("Success!");
    }else{
        puts("Fail!");
    }
}

void print_list(List list)
{
    for(List p = list->next; p; p = p->next)
        printf("%d ", p->data);
    putchar('\n');
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    List list = read_list(n);
    while(m--)
    {
        int op, x, data;
        scanf("%d%d%d", &op, &x, &data);
        if(op == 1)
            insert_by_index(list, x, data);
        else
            insert_by_data(list, x, data);
    }
    print_list(list);
    return 0;
}