#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define eps 10e-8
typedef struct {
    char name[25];
    struct {
        double x;
        double y;
        double z;
        double r;
    } r;
} star;
int XGreaterThanY(double x, double y) {
    return x - y > eps;
}
int XLessThanY(double x, double y) {
    return x - y < -eps;
}
int XEqualToY(double x, double y) {
    return fabs(x - y) < eps;
}
int cmp(const void* p1, const void* p2) {
    star* pp1 = (star*)p1;
    star* pp2 = (star*)p2;
    if (XGreaterThanY(pp1->r.r, pp2->r.r)) {
        return 1;
    } else if (XLessThanY(pp1->r.r, pp2->r.r)) {
        return -1;
    } else {
        return strcmp(pp1->name, pp2->name);
    }
}
star stars[500005];
int  main() {
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        scanf("%s%lf%lf%lf", stars[i].name, &stars[i].r.x, &stars[i].r.y,
               &stars[i].r.z);
        stars[i].r.r =
            sqrt(stars[i].r.x * stars[i].r.x + stars[i].r.y * stars[i].r.y +
                  stars[i].r.z * stars[i].r.z);
    }
    qsort(stars, n, sizeof(stars[0]), cmp);
    for (int i = 0; i < n; i++) {
        printf("%s\n", stars[i].name);
    }
    return 0;
}