/**
* Leetcode Problem - https://leetcode.com/problems/design-circular-deque/
* Author - Shubham Nagaria
* Date - 5th Feb 2022
**/
class MyCircularDeque {
public:
    vector<int>cdq;
    int size=0;
    int capacity;
    int front =0;
    int rear = 0;
    
    MyCircularDeque(int k) {
        capacity = k;
        size = 0;
        front = 0;
        rear = 0;
        cdq.resize(capacity,0);
    }
    
    bool insertFront(int value) {
        if(size < capacity){
            cdq[front]=value;
            front = (capacity+ front -1)%capacity;
            size++;
            return true;
        }
        return false;
    }
    
    bool insertLast(int value) {
        if(size< capacity){
            rear = (rear+1)%capacity;
            cdq[rear]= value;
            size++;
            return true;
        }
        return false;
    }
    
    bool deleteFront() {
        if(size==0)
            return false;
       front=(front+1)%capacity;
        size--;
        return true;
    }
    
    bool deleteLast() {
        if(size==0)
            return false;
        rear= (capacity + rear-1)%capacity;
        size--;
        return true;
    }
    
    int getFront() {
        if(size==0)
            return -1;
        return cdq[(front+1)%capacity];
    }
    
    int getRear() {
        if(size==0)
            return -1;
        return cdq[rear];
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
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
