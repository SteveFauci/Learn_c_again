#include <stdio.h>
int vector[3];
struct {
    struct {
        int x, y, z;
    } r;
    long long int work;
} force[1005];

int main() {
    scanf("%d%d%d", &vector[0], &vector[1], &vector[2]);
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &force[i].r.x, &force[i].r.y, &force[i].r.z);
        force[i].work = force[i].r.x * vector[0] + force[i].r.y * vector[1] +
                        force[i].r.z * vector[2];
    }
    long long int max_work = force[0].work;
    for (int i = 0; i < n; i++) {
        if (max_work <= force[i].work)
            max_work = force[i].work;
    }
    for (int i = 0; i < n; i++) {
        if (force[i].work == max_work) {
            printf("%d %d %d\n", force[i].r.x, force[i].r.y, force[i].r.z);
        }
    }
}