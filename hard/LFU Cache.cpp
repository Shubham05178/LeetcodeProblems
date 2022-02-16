/**
* Leetcode Problem - https://leetcode.com/problems/lfu-cache/
* Author - Shubham Nagaria
* Date - 16th Feb 2022
**/
struct Node{
    int key;
    int val;
    Node *prev;
    Node *next;
    Node(int k, int v){
        key = k;
        val = v;
        prev = NULL;
        next = NULL;
    }
};
class LFUCache {
public:
    unordered_map<int,int>counter;
    
    unordered_map<int,pair<pair<Node*,Node*>,int>>freqLinkList;
    unordered_map<int,Node*>addressofkey;
    int ss=0;
    int cap;
    int minfreq;
    void assignHeadandTail(int Freq){
        Node * head = new Node(-1,-1);
        Node * tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
        freqLinkList[Freq]=make_pair(make_pair(head,tail),0);
    }
    void InsertatHead(int Freq,int key, int val){
        if(freqLinkList.find(Freq) == freqLinkList.end()) assignHeadandTail(Freq);
        Node * head = freqLinkList[Freq].first.first;
        Node * n = new Node(key,val);
        n->next = head->next;
        n->prev = head;
        head->next->prev = n;
        head->next = n;
        freqLinkList[Freq].second++;
        counter[key]++;
        addressofkey[key]=n;
    }
   void UpdateCountofNode(int key,int val){
        freqLinkList[counter[key]].second--;
        if(freqLinkList[minfreq].second == 0) minfreq++;
        Node* n = addressofkey[key];
        n->next->prev = n->prev;
        n->prev->next = n->next;
       
        counter[key]++;
        if(freqLinkList.find(counter[key]) == freqLinkList.end()) 
            assignHeadandTail(counter[key]);
        
        n->val= val;
        Node* head = freqLinkList[counter[key]].first.first;
        n->next = head->next;
        n->prev = head;
        head->next->prev = n;
        head->next = n;
        freqLinkList[counter[key]].second++;
    }
    LFUCache(int capacity) {
        counter.clear();
        addressofkey.clear();
        freqLinkList.clear();
        ss=0;
        minfreq=0;
        cap = capacity;
    }
    
    int get(int key) {
        if(cap==0) return -1;
        if(addressofkey.count(key) == 0) return -1;
        Node* n = addressofkey[key];
        int val = n->val;
        UpdateCountofNode(key,val);
        return val;
    }
    
    void put(int key, int value) {
        if(cap ==0 ) return;
        if( addressofkey.find(key) != addressofkey.end()){
            UpdateCountofNode(key, value);
        }
        else if(ss < cap){
                InsertatHead(1,key,value);
                minfreq=1;
                ss++;
            }
        
      else if(ss == cap){
             int i = minfreq;
             freqLinkList[i].second--;
             Node *tail =freqLinkList[i].first.second;
             Node *temp = tail->prev;
             temp->prev->next = tail;   
             tail->prev = temp->prev; 
             addressofkey.erase(temp->key);
             counter.erase(temp->key);
             delete(temp);
             InsertatHead(1,key,value);
            minfreq=1;
         }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
