#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void my_gets(char* s, int limit) {
    fgets(s, limit, stdin);
    s[strcspn(s, "\n")] = '\0';
}
typedef struct Book {
    int          id;
    char         name[105];
    struct Book* next;
} Book;
Book* head = NULL; // 链表头指针，初始为空。
// 在有序链表中插入新的结点
void insert_book(int id, char* name) {
    Book* new_book = (Book*)malloc(sizeof(Book));
    new_book->id = id;
    strcpy(new_book->name, name);
    new_book->next = NULL;
    // 头结点不存在时，或者需要插入到头结点之前
    if (head == NULL || head->id > id) {
        new_book->next = head;
        head = new_book;
        return;
    }
    Book* curr = head;
    while (curr->next != NULL && curr->next->id < id) {
        curr = curr->next;
    }
    new_book->next = curr->next;
    curr->next = new_book;
}
// 删除指定结点
void delete_book(char* name) {
    Book* curr = head;
    Book* prev = NULL;
    while (curr != NULL) {
        if (strcmp(curr->name, name) == 0) {
            // 单独讨论头结点为要删除结点的情况
            if (prev == NULL) {
                head = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr); // 记得释放内存
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

// 按照要求输出链表中的所有结点
void print_books() {
    Book* curr = head;
    while (curr != NULL) {
        printf("%d %s\n", curr->id, curr->name);
        curr = curr->next;
    }
}
// oj上无硬性要求，但还是养成free的习惯
void free_books() {
    Book* curr = head;
    while (curr != NULL) {
        Book* temp = curr;
        curr = curr->next;
        free(temp);
    }
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int  id;
            char name[105];
            scanf("%d", &id);
            getchar(); // 吃掉换行符
            my_gets(name,105);
            insert_book(id, name);
        } else if (op == 2) {
            char name[105];
            getchar(); // 吃掉换行符
            my_gets(name,105);
            delete_book(name);
        }
    }
    print_books();
    free_books();
    return 0;
}
