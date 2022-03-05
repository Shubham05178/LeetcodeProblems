/**
* Leetcode Problem -  https://leetcode.com/problems/find-median-from-data-stream/
* Author - Shubham Nagaria
* Date - 5th March 2022
**/
class MedianFinder {
public:
    priority_queue<int>maxHeap;
    priority_queue<int,vector<int>,greater<int>>minHeap;
    MedianFinder() {
        while(minHeap.size()>0)
            minHeap.pop();
        while(maxHeap.size()>0)
            maxHeap.pop();
    }
    
    void addNum(int num) {
        if(maxHeap.size() == 0){
            maxHeap.push(num);
        }
        else{
            if(num <= maxHeap.top()){
                maxHeap.push(num);
                if(maxHeap.size() - minHeap.size() > 1){
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                }
            }
            else{
                minHeap.push(num);
                if(minHeap.size() > maxHeap.size()){
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                }
            }
        }
    }
    
    double findMedian(){
        if(maxHeap.size()== minHeap.size())
            return (maxHeap.top()+minHeap.top())/2.0;
        return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
