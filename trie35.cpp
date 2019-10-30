//
// Created by Admin on 2019/10/30.
//

#include <iostream>
#include <string>
using namespace std;
struct TrieNode{
    char ch;
    int cnt;
    bool isEndingChar;
    TrieNode* child[26];
    TrieNode(char character):ch(character),cnt(1),isEndingChar(false){
        for(int i=0;i<26;i++)
            child[i] = NULL;
    }
};
class Trie{
public:
    Trie(){
        this->root = new TrieNode('/');
    }
    void insert(string a) //将a插入字典树中
    {
        TrieNode *pcur = this->root;
        for(int i=0;i<a.size();++i){
            char tmp = a[i];
            int index = tmp - 'a';
            if(pcur->child[index]) {
                pcur->child[index]->cnt++;
                pcur = pcur->child[index];
            }
            else{
                TrieNode* pNew = new TrieNode(tmp);
                pcur->child[index] = pNew;
            }
        }
        pcur->isEndingChar = true;
    }
    bool find(string a){ //查找a是否在字典树中
        TrieNode *pcur = this->root;
        for(int i=0;i<a.size();++i){
            int index = a[i] - 'a';
            if(pcur->child[index]){
                pcur = pcur->child[index];
            }else return false;
        }
        return pcur->isEndingChar;
    }
private:
    TrieNode* root;
};

