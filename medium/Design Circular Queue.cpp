/**
* Leetcode Problem - https://leetcode.com/problems/design-circular-queue/
* Author - Shubham Nagaria
* Date - 5th Feb 2022
**/
class MyCircularQueue {
public:
    vector<int>cq;
    int rear =-1;
    int front =-1;
    int capacity;
    int size=0;
    
    MyCircularQueue(int k) {
        front =-1;
        rear =-1;
        capacity=k;
        cq.resize(capacity,0);
        size=0;
    }
    
    bool enQueue(int value) {
        if(size < capacity){
            rear=(rear+1)%capacity;
            cq[rear]=value;
            size++;
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(size==0)
            return false;
        size--;
        front = (front+1)%capacity;
        return true;
    }
    
    int Front() {
        if(size==0)
            return -1;
       return cq[(front+1)%capacity];
    }
    
    int Rear() {
        if(size==0)
            return -1;
        return cq[rear];
    }
    
    bool isEmpty() {
        if(size==0)
            return true;
        return false;
    }
    
    bool isFull() {
        if(size==capacity)
            return true;
        return false;
    }
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
