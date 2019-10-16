//队列及循环队列
// Created by Borix on 2019/10/16.
//
#include <iostream>
class Queue{
public:
    Queue(int size)
    :_size(size),_head(0),_tail(0),_items(new int[size]()){
        std::cout << "having create queue" << std::endl;
    }
    ~Queue(){
        std::cout << "destroy queue" << std::endl;
    }
    bool enQueue(int item){
        if(_tail == _size){
            return false;
        }
        _items[_tail++] = item;
        return true;
    }
    int deQueue(){
        if(_head==_tail) return NULL;
        return _items[_head++];
    }

private:
    int _size;
    int _head;
    int _tail;
    int *_items;
};
struct LNode{
    int _val;
    struct LNode *_next;
    LNode(int val):_val(val),_next(NULL){}
};
class LinkQueue{
public:
    LinkQueue(int size)
    :_size(size),_pHead(new LNode(0)){
        _pTail = _pHead;
        this->_count = 0;
    }
    bool enQueue(int item){
        if(this->_count==_size){
            return false;
        }
        LNode *pNew = new LNode(item);
        _pTail->_next = pNew;
        _pTail = pNew;
        return true;
    }
    int deQueue(){
        if(_pHead == _pTail){
            return NULL;
        }
        LNode* pTemp = _pHead->_next;
        _pHead->_next = pTemp->_next;
        int ret = pTemp->_val;
        delete pTemp;
        return ret;
    }
private:
    int _count;
    int _size;
    LNode* _pHead;
    LNode* _pTail;
};

int main(){
    LinkQueue a = LinkQueue(10);
    for(int i=0;i<10;i++){
        a.enQueue(i);
    }
    for(int i=0;i<10;i++){
        std::cout << "dequeue " << a.deQueue() << std::endl;
    }
}



