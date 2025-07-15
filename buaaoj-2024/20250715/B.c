#include<stdio.h>
#include<math.h>

double x[1005];
double y[1005];
int main(){
    int n;
    scanf("%d",&n);
    double sum_x = 0,sum_y = 0;
    for(int i = 0; i<n;i++){
        scanf("%lf",&x[i]);
        sum_x += x[i];
    }
    for(int i = 0; i<n;i++){
        scanf("%lf",&y[i]);
        sum_y += y[i];
    }
    double x_ave = sum_x / n;
    double y_ave = sum_y / n;

    double a = 0,b=0,c=0;
    for(int i = 0; i<n;i++){
        a += (x[i]-x_ave)*(y[i]-y_ave);
        b += (x[i]-x_ave)*(x[i]-x_ave);
        c += (y[i]-y_ave)*(y[i]-y_ave);
    }
    printf("%.2lf",a/sqrt(b*c));
    return 0;
}