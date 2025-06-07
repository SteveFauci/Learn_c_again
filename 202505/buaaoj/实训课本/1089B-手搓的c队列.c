#include <stdio.h>
#include<stdlib.h>
int map[10][10];
void readmap() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            scanf("%d", &map[i][j]);
        }
    }
}

//先手搓个stl容器

typedef struct my_que{
    int *val;
    int front;
    int back;
    int size;
}Queue;

Queue*init_que(int size){
    Queue *ptr = (Queue*)malloc(sizeof(Queue));
    ptr->back = ptr->front = -1;
    ptr->size = size;
    ptr->val = (int*)malloc(size*sizeof(int));
    return ptr;
}
int isEmpty(Queue*ptr){
    if(ptr->back == -1 && ptr->front == -1)return 1;
    return 0;
}
int isFull(Queue*ptr){
    if((ptr->back+1)%ptr->size == ptr->front)return 1;
    return 0;
}
int front(Queue*ptr){
    if(isEmpty(ptr))return -1;
    return ptr->val[ptr->front];
}
int back(Queue*ptr){
    if(isEmpty(ptr))return -1;
    return ptr->val[ptr->back];
}
void push(int val,Queue*ptr){
    if(isEmpty(ptr)){
        ++ptr->back;
        ++ptr->front;
        ptr->val[ptr->back] = val;
        return;
    }else if(isFull(ptr)){
        return;
    }else{
        ptr->back = (ptr->back+1)%ptr->size;
        ptr->val[ptr->back] = val;
        return;
    }
}
void pop(Queue *ptr){
    if(isEmpty(ptr))return;
    else if(ptr->front == ptr->back){
        ptr->front = ptr->back = -1;
    }
    else{
        ptr->front = (ptr->front+1)%ptr->size;
    }
}
void freeQ(Queue* ptr) {
    if (ptr != NULL) {
        free(ptr->val);   // 先释放 val
        ptr->val = NULL;  // 避免野指针（可选）
        free(ptr);        // 再释放结构体本身
    }
}

int main() {
    Queue *q = init_que(5);

    push(10, q);
    push(20, q);
    push(30, q);
    push(40, q);

    printf("Front: %d\n", front(q)); // 10
    printf("Back: %d\n", back(q));   // 40

    pop(q);
    printf("New Front: %d\n", front(q)); // 20

    push(50, q);
    push(60, q); // 队列满，不会插入

    while (!isEmpty(q)) {
        printf("%d ", front(q));
        pop(q);
    }

    freeQ(q);

    return 0;
}