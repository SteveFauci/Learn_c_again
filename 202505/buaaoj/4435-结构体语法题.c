#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int l;
    int r;
}cor;

int cmp(const void*p1,const void*p2){
    cor*pp1 = (cor*)p1;
    cor*pp2 = (cor*)p2;
    if((pp1->l-pp2->l)!=0){
        return pp1->l-pp2->l;
    }else{
        return pp1->r-pp2->r;
    }
}

cor arrs[1005];
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d%d",&arrs[i].l,&arrs[i].r);
    }
    qsort(arrs,n,sizeof(arrs[0]),cmp);\
    for(int i = 0;i<n;i++){
        printf("%d %d\n",arrs[i].l,arrs[i].r);
    }
    return 0;
}