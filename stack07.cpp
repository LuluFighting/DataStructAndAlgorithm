#include <iostream>
#include <vector>
using std::vector;
//数组栈
class Stack{
public:
    Stack(int size)
    :_size(size),_index(0),_items(new int[size]())
    {
        std::cout << "having create a stack " << std::endl;
    }
    bool push(int item){
        if(_index == _size){
            return false;
        }
        _items[_index++] = item;
        return true;
    }
    int pop(){
        if(_index == 0){
            return NULL;
        }
        return _items[--_index];
    }
private:
    int _size;  //栈的大小
    int _index; //目前的索引
    int *_items;
};
struct LNode{
    LNode(int val):_val(val),_next(NULL){}
    int _val;
    struct LNode* _next;
};
//链栈
class LinkStack{
public:
    LinkStack(int size)
    :_size(size),_count(0),_pHead(new LNode(0)){
        std::cout << "having create linkstack" << std::endl;
    }
    bool push(int item){
        if(_count==_size){
            return false;
        }
        LNode* pNew = new LNode(item);
        pNew->_next = _pHead->_next;
        _pHead->_next = pNew;
        _count++;
        return true;
    }
    int pop(){
        if(_count==0){
            return NULL;
        }
        LNode* pLast = _pHead->_next;
        _pHead->_next = pLast->_next;
        int retVal = pLast->_val;
        delete(pLast);
        return retVal;
    }

private:
    int _size;
    int _count;
    LNode* _pHead;
};
int main() {
    LinkStack a = LinkStack(10);
    a.push(1);
    a.push(3);
    std::cout << a.pop() << std::endl;
    std::cout << a.pop() << std::endl;
    std::cout << a.pop() << std::endl;
    return 0;
}