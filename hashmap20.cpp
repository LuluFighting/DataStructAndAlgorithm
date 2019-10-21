//
// Created by Admin on 2019/10/22.
//
#include <iostream>
#include <map>
using namespace std;
struct LinkNode{
    int key;
    int val;
    LinkNode *pre;
    LinkNode *next;
    LinkNode(int key_,int value):key(key_),val(value),pre(NULL),next(NULL){}
};
class LRUCache{
public:
    LRUCache(int capacity){
        _size = 0;
        _capacity = capacity;
        _head = new LinkNode(-1,-1);
        _tail = _head;
    }

    int get(int key){
        auto search = _hashmap.find(key);
        if(search == _hashmap.end()) return -1;
        LinkNode *pCur = search->second;
        if(pCur!=_tail) {
            LinkNode *pre = pCur->pre;
            pre->next = pCur->next;
            pCur->next->pre = pre;
            pCur->next = NULL;
            pCur->pre = NULL;
            _tail->next = pCur;
            pCur->pre = _tail;
            _tail = pCur;
        }
        return pCur->val;
    }

    void put(int key,int value){
        auto search = _hashmap.find(key);
        if(search == _hashmap.end()){
            if(_size == _capacity){
                LinkNode* tmp = _head->next;
                if(tmp->next == NULL) {
                    _head->next = NULL;
                    _tail = _head;
                }
                else{
                    tmp->next->pre = _head;
                    _head->next = tmp->next;
                }
                _hashmap.erase(tmp->key);
                delete tmp;
                _size--;
            }
            LinkNode *pNew = new LinkNode(key,value);
            _tail->next = pNew;
            pNew->pre = _tail;
            _hashmap.insert(pair<int,LinkNode*>(key,pNew));
            _tail = pNew;
            _size++;
        }else{
            LinkNode *pCur = search->second;
            pCur->val = value;
            if(pCur!=_tail) {
                LinkNode *pre = pCur->pre;
                pre->next = pCur->next;
                pCur->next->pre = pre;
                pCur->next = NULL;
                _tail->next = pCur;
                pCur->pre = _tail;
                _tail = pCur;
            }
        }

    }

private:
    int _capacity;
    int _size;
    map<int,LinkNode*> _hashmap;
    LinkNode *_head,*_tail;
};

int main(){
    LRUCache cache = LRUCache( 2 /* 缓存容量 */ );

    cache.put(2, 1);
    cache.put(2, 2);
    cache.get(2);       // 返回  1
    cache.put(1,1);
//    cache.get(2);
    cache.put(4,1);
    cache.get(2);
//    cache.put(3, 3);    // 该操作会使得密钥 2 作废
//    cache.get(2);       // 返回 -1 (未找到)
//    cache.put(4, 4);    // 该操作会使得密钥 1 作废
//    cache.get(1);       // 返回 -1 (未找到)
//    cache.get(3);       // 返回  3
//    cache.get(4);       // 返回  4

}
