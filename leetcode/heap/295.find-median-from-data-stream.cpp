/*295. 数据流的中位数

https://leetcode.cn/problems/find-median-from-data-stream/?envType=study-plan-v2&envId=top-100-liked

思路：维护一个最大堆和最小堆；满足 最大堆堆顶不大于最小堆堆顶 且 两个堆的元素个数相等或者差1；中位数等于堆顶元素，或堆顶元素均值
*/
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

class MedianFinder
{
public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (maxHeap.empty() || num <= maxHeap.top())
        {
            maxHeap.push(num);
        }
        else
        {
            minHeap.push(num);
        }

        // minHeap.size() - maxHeap.size(): unsigned long - unsigned long, maybe overflow
        while (minHeap.size() > maxHeap.size() + 1)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        while (maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }

    double findMedian()
    {
        if (minHeap.size() == maxHeap.size())
        {
            return (minHeap.top() + maxHeap.top()) / 2.0;
        }
        else if (minHeap.size() > maxHeap.size())
        {
            return minHeap.top();
        }
        else
        {
            return maxHeap.top();
        }
    }

private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main(int argc, char const *argv[])
{
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    cout << mf.findMedian() << endl;
    mf.addNum(3);
    cout << mf.findMedian() << endl;
    return 0;
}
