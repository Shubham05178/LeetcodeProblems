/**
* Leetcode Problem - https://leetcode.com/problems/lru-cache/
* Author - Shubham Nagaria
* Date - 29th Jan 2022
**/
class LRUCache {
public:
    struct Node{
        int key;
        int val;
        Node *prev;
        Node *next;
        Node(int x){
            key=x;
        }
    };
    Node *head, *tail;
    int cap,currentsize;
    unordered_map<int, Node *>HM;
    LRUCache(int capacity) {
        cap=capacity;
        currentsize=0;
        HM.clear();
        head = new Node(-1);
        tail = new Node(-1);
        head->next = tail;
        tail->prev = head;
    }
    void addtoTail( Node * p){
        p->next = tail;
        p->prev = tail->prev;
        tail->prev->next = p;
        tail->prev = p;
    }
    int get(int key) {
        if(HM.find(key) == HM.end())
            return -1;
        Node *temp = HM[key];
        temp->prev->next = temp->next;
        temp->next->prev= temp->prev;
        addtoTail(temp);
        return temp->val;
    }
    void put(int key, int value) {
     if(HM.find(key) != HM.end()){
         Node *temp = HM[key];
         temp->next->prev= temp->prev;
         temp->prev->next = temp->next;
         temp->val = value;
         addtoTail(temp);
     }else{
         if(currentsize == cap){
             HM.erase(head->next->key);
             Node* temp=head->next;
             temp->next->prev = temp->prev;
             temp->prev->next = temp->next;
             delete(temp);
             currentsize--;
         }
         Node * p = new Node(key);
         p->val = value;
         HM[key] = p;
         addtoTail(p);
         currentsize++;
     }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
