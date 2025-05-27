#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define eps 1e-6
int XGreaterThanY(double x,double y){
	return x-y>eps;
}
int XLessThanY(double x,double y){
	return x-y<-eps;
}
int XEqualToY(double x,double y){
	return fabs(x-y)<eps;
}
typedef struct {
    char name[55];
    int id;
    double score;
    struct time{
        int h;
        int m;
        int s;
        int sec;
    } t;
} my_stru;
int cmp(const void*p1,const void*p2){
    my_stru *pp1 = (my_stru*) p1;
    my_stru *pp2 = (my_stru*) p2;
    if(XGreaterThanY(pp1->score , pp2->score)){
        return -1;
    }else if(XLessThanY(pp1->score , pp2->score)){
        return 1;
    }else if(XEqualToY(pp1->score , pp2->score)){
        if(pp1->t.sec > pp2->t.sec){
            return 1;
        }else if(pp1->t.sec < pp2->t.sec){
            return -1;
        }else{
            return pp1->id - pp2->id;
        }
    }else{
        return 0;
    }
}
int main(){
    my_stru stu[1005];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s %d %lf %d:%d:%d",
            stu[i].name,
            &stu[i].id,
            &stu[i].score,
            &stu[i].t.h,
            &stu[i].t.m,
            &stu[i].t.s);
        stu[i].t.sec = stu[i].t.h*60*60+stu[i].t.m*60+stu[i].t.s;
    }
    qsort(stu,n,sizeof(stu[0]),cmp);
    for(int i=0;i<n;i++){
        printf("%s %d %.2lf %02d:%02d:%02d\n",
            stu[i].name,
            stu[i].id,
            stu[i].score,
            stu[i].t.h,
            stu[i].t.m,
            stu[i].t.s);
    }
}