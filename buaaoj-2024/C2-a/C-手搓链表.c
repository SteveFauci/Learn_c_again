// 这个我投机取巧，没用链表。不过也不知为啥什么没通过，拿了及格分。
// 题解用了一些插入手段，能直接构造有序链表

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    int id;
    char name[105];
    int my_bool;
}book;
book books[105];
char temp[105];

int cmp(const void*pp1,const void *pp2){
    book*p1 = (book*)pp1;
    book*p2 = (book*)pp2;
    return p1->id > p2->id;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n;i++){
        int op;
        scanf("%d",&op);
        getchar();
        if(op==1){
            scanf("%d ",&books[i].id);
            fgets(books[i].name,105,stdin);
            books[i].name[strcspn(books[i].name, "\n")] = '\0';
        }else{
            fgets(temp,105,stdin);
            temp[strcspn(temp, "\n")] = '\0';
            for(int j = 0; j < i;j++){
                if(strcmp(temp, books[j].name)==0)
                    books[j].my_bool = 1;
            }
        }
    }
    qsort(books,n,sizeof(books[0]),cmp);
    for(int i = 0; i < 105;i++){
        if(!books[i].my_bool && books[i].name[0])
            printf("%d %s\n",books[i].id,books[i].name);
    }
}