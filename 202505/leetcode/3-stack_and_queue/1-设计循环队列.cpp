#include <vector>
using namespace std;
/*
初始指针          front = rear = -1
加入第一个元素    front = rear 指向该元素角标(其实就是0)
再加入元素        front不动 rear = (rear+1)%size
加满             (rear 1)%size == front
出队             rear不动 front = (front+1)%size
最后一个元素      front == rear 指向该元素角标
最后一个元素出队   front = rear = -1
*/
class MyCircularQueue {
  public: // 用构造函数初始化
    MyCircularQueue(int k) {
        queue.reserve(k);
        size = k;
        head = -1;
        tail = -1;
    }

    bool enQueue(int value) {
        if (isEmpty()) {//特判:空队列
            head++;
            tail++;
            queue[tail] = value;
            return true;
        } else if (isFull())
            return false;
        tail = (tail + 1) % size;
        queue[tail] = value;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        } else if (head == tail) {//特判:只有一个元素
            head = -1;
            tail = -1;
            return true;
        }
        head = (head + 1) % size;
        return true;
    }

    int Front() {
        if (isEmpty())
            return -1;
        return queue[head];
    }

    int Rear() {
        if (isEmpty())
            return -1;
        return queue[tail];
    }

    bool isEmpty() {
        if (head == -1 && tail == -1)
            return true;
        return false;
    }

    bool isFull() {
        if ((tail + 1) % size == head)
            return true;
        return false;
    }

  private:
    vector<int> queue;
    int head;
    int tail;
    int size;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */