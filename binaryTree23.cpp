//
// Created by Admin on 2019/10/22.
//
#include <iostream>
#include <stack>
using namespace std;
struct Node{
    int val;
    Node *left,*right;
    Node(int value):val(value),left(NULL),right(NULL){}
};

struct postNode{
    Node* btNode;
    bool isFirst;
    postNode(Node* p):isFirst(true),btNode(p){}
};

class traverse{
public:
    void preOrder(Node* root){
        stack<Node*> myStack;
        Node* pcur = root;
        while(pcur){
            cout << pcur->val << endl;
            if(pcur->right){
                myStack.push(pcur->right);
            }
            if(pcur->left)
                pcur = pcur->left;
            else{
                if(myStack.empty()) break;
                pcur = myStack.top();
                myStack.pop();
            }

        }
    }
    void inOrder(Node* root){
        stack<Node*> myStack;
        Node* pcur = root;
        while(pcur || !myStack.empty()){
            if(pcur){
                while(pcur){
                    myStack.push(pcur);
                    pcur = pcur->left;
                }
            }else{
                pcur = myStack.top();
                myStack.pop();
                cout << pcur->val << endl;
                pcur = pcur->right;
            }
        }
    }
    void postOrder(Node* root){
        stack<postNode*> myStack;
        Node* pcur = root;
        while(pcur || !myStack.empty()){
            while(pcur){
                myStack.push(new postNode(pcur));
                pcur = pcur->left;
            }
            if(!myStack.empty()){
                if(myStack.top()->isFirst){
                    myStack.top()->isFirst = false;
                    pcur = myStack.top()->btNode->right;
                }else {
                    cout << myStack.top()->btNode->val << endl;
                    myStack.pop();
                    pcur = NULL;
                }
            }
        }

    }
};

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    traverse tra;
    tra.postOrder(root);
}

