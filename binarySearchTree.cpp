//
// Created by Admin on 2019/10/23.
//
#include <iostream>
using  namespace std;
typedef int DataType;
struct TreeNode{
    DataType val;
    TreeNode *left,*right;
    TreeNode(DataType value):val(value),left(NULL),right(NULL){}
};
class BinarySearchTree{
private:
    TreeNode *root;
    int num;
public:
    BinarySearchTree()
    :root(new TreeNode(0)),num(0) {}
    bool find(DataType it,TreeNode *root){
        TreeNode *pcur = root;
        while(pcur){
            if(pcur->val==it) return true;
            else if(pcur->val > it) pcur = pcur -> left;
            else pcur = pcur -> right;
        }
        return false;
    }
    bool find_data(DataType it){
        return this->find(it,this->root);
    }
    DataType get_max(){
        if(NULL == root) return NULL;
        TreeNode *pcur = root;
        while(pcur->right){
            pcur = pcur->right;
        }
        return pcur->val;
    }
    DataType get_min(){
        if(NULL == root) return NULL;
        TreeNode *pcur = root;
        while(pcur->left){
            pcur = pcur->left;
        }
        return pcur->val;
    }
    void insert_data(DataType it){
        if(0 == num){
            root->val = it;
            num++;
            return;
        }
        TreeNode *pcur = root;
        while(pcur){
            if(pcur->val<=it){
                if(NULL == pcur->right){
                    pcur->right = new TreeNode(it);
                    num++;
                    break;
                }
                pcur = pcur->right;
            }else {
                if (NULL == pcur->left) {
                    pcur->left = new TreeNode(it);
                    num++;
                    break;
                }
                pcur = pcur->left;
            }
        }
    }
    void delet(DataType it){
        if(NULL == root) return;
        TreeNode *parent=NULL,*pcur = root;
        while(pcur){
            if(pcur->val == it) break;
            parent = pcur;
            if(pcur->val > it) pcur = pcur->left;
            else pcur = pcur->right;
        }
        if(pcur->right && pcur->left){
            TreeNode *tmp = pcur->right,*pTmp = pcur;
            while(tmp->left) {
                pTmp = tmp;
                tmp = tmp->left;
            }
            pcur->val = tmp->val;
            parent = pTmp;
            pcur = tmp;
        }
        TreeNode *child;
        if(pcur->left) child = pcur->left;
        else if(pcur->right) child = pcur->right;
        else child = NULL;
        if(NULL == parent) root = child;
        else if(pcur == parent->left){
            parent->left = child;
        }else parent->right = child;
        delete pcur;
    }
    DataType get_prenode(DataType it){
        if(NULL == root) return NULL;
//        if(it == root->val) return NULL;
        TreeNode *pcur = root,*parent = NULL;
        bool isExist = false;
        while(pcur){
            if(it == pcur->val) {
                isExist = true;
                break;
            }
            parent = pcur;
            if(pcur->val > it) pcur = pcur->left;
            else pcur = pcur->right;
        }
        if(!isExist) return NULL;
        return parent->val;
    }
    DataType get_postnode(DataType it){
        if(NULL == root) return NULL;
        TreeNode *pcur = root;
        while(pcur){
            if(it == pcur->val) break;
            else if(it > pcur->val) pcur = pcur->right;
            else pcur = pcur->left;
        }
        if(NULL == pcur) return NULL;
        if(pcur->left) return pcur->left->val;
        else if(pcur->right) return pcur->right->val;
        else return NULL;
    }
    int get_high(TreeNode *root){
        if(NULL == root) return 0;
        int lhigh,rhigh;
        lhigh = get_high(root->left);
        rhigh = get_high(root->right);
        return (lhigh>rhigh? (lhigh+1) : (rhigh+1));
    }
    int high(){
        if(NULL == root) return 0;
        return get_high(root);
    }
};
int main() {
    BinarySearchTree my_tree;

    // must input in the order of layers
    my_tree.insert_data(33);
    my_tree.insert_data(16);
    my_tree.insert_data(50);
    my_tree.insert_data(13);
    my_tree.insert_data(18);
    my_tree.insert_data(34);
    my_tree.insert_data(58);
    my_tree.insert_data(15);
    my_tree.insert_data(17);
    my_tree.insert_data(25);
    my_tree.insert_data(51);
    my_tree.insert_data(66);
    my_tree.insert_data(19);
    my_tree.insert_data(27);
    my_tree.insert_data(55);

    if (my_tree.find_data(25)) {
        cout << "找到了数字25" << endl;
    } else {
        cout << "没有找到数字25" << endl;
    }
    my_tree.delet(13);
    my_tree.delet(18);
    my_tree.delet(55);
    cout << "Max:  " << my_tree.get_max() << endl;
    cout << "Min:  " << my_tree.get_min() << endl;
    cout << "pre node of 17 is " << my_tree.get_prenode(17) << endl;
    cout << "pre node of 51 is " << my_tree.get_prenode(51) << endl;
    cout << "pre node of 33 is " << my_tree.get_prenode(33) << endl;

    cout << "post node of 19 is " << my_tree.get_postnode(19) << endl;
    cout << "post node of 25 is " << my_tree.get_postnode(25) << endl;
    cout << "post node of 58 is " << my_tree.get_postnode(58) << endl;
    cout << "post node of 58 is " << my_tree.get_postnode(51) << endl;
    cout << "high of tree is " << my_tree.high() << endl;
    return 0;
}

