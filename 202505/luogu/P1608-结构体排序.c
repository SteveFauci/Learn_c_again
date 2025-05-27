#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int id;
    int grade;
} student;
student stu[5005];
int     cmp(const void* p1, const void* p2) {
    student* pp1 = (student*)p1;
    student* pp2 = (student*)p2;
    if (pp1->grade > pp2->grade) {
        return -1;
    } else if (pp1->grade < pp2->grade) {
        return 1;
    } else {
        if (pp1->id > pp2->id) {
            return 1;
        } else if (pp1->id < pp2->id) {
            return -1;
        }
        return 0;
    }
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &stu[i].id, &stu[i].grade);
    }
    qsort(stu, n, sizeof(stu[0]), cmp);
    int threshold = stu[m * 3 / 2 - 1].grade;
    int num = 0;
    for (int i = 0; i < n; i++) {
        if (stu[i].grade >= threshold)
            num++;
    }
    printf("%d %d\n", threshold, num);
    for (int i = 0; i < num; i++) {
        printf("%d %d\n", stu[i].id, stu[i].grade);
    }
}