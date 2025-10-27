#include <stdio.h>
int my_heap[200005];
int size = 0;
int left(int index) {
    return 2 * index + 1;
}
int right(int index) {
    return 2 * index + 2;
}
int parent(int index) {
    return (index - 1) / 2;
}
int peek() {
    return my_heap[0];
}
void my_swap(int i_a, int i_b) {
    int c = my_heap[i_a];
    my_heap[i_a] = my_heap[i_b];
    my_heap[i_b] = c;
}
void siftUp(int i) {
    while (1) {
        int p = parent(i);
        if (p < 0 || my_heap[i] <= my_heap[p])
            break;
        my_swap(i, p);
        i = p;
    }
}
void siftDown(int i) {
    while (1) {
        int l = left(i);
        int r = right(i);
        int largest = i;
        if (l < size && my_heap[l] > my_heap[largest]) {
            largest = l;
        }
        if (r < size && my_heap[r] > my_heap[largest]) {
            largest = r;
        }
        if (largest == i)
            break;
        my_swap(i, largest);
        i = largest;
    }
}
void push(int val) {
    my_heap[size++] = val;
    siftUp(size - 1);
}
void pop() {
    if (size <= 0)
        return;
    my_heap[0] = my_heap[--size];
    siftDown(0);
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        push(num);
    }
    for (int i = 0; i < q; i++) {
        int num = my_heap[0];
        pop();
        my_heap[size] = num;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", my_heap[i]);
    }
    puts("");
    while (size > 0) {
        int num = my_heap[0];
        pop();
        my_heap[size] = num;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", my_heap[i]);
    }
    puts("");
}