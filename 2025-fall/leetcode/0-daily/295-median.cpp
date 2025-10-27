#include<queue>
using namespace std;
class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
public:
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
        if((maxHeap.size() + minHeap.size())/2)return maxHeap.top();
        else return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};