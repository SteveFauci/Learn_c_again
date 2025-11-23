#include <functional>
#include<queue>
using namespace std;
class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    void addNum(int num) {
        if(maxHeap.size() == minHeap.size()){
            maxHeap.push(num);
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }else{
            minHeap.push(num);
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size())return maxHeap.top() + minHeap.top() / 2.0;
        return minHeap.top();
    }
};