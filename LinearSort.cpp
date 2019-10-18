//
// Created by Admin on 2019/10/18.
//
#include <iostream>
using namespace std;

class Interface{
public:
    virtual void sort(int* a,int n)=0;
};

class CountSort
        :public Interface{
public:
    void sort(int* a,int n){
        int max = 0;
        for(int i=0;i<n;++i){
            if(a[i]>max){
                max=a[i];
            }
        }
        int* cnt = new int[max+1]();
        int* tmp = new int[n]();
        //计数
        for(int i=0;i<n;++i){
            cnt[a[i]]++;
        }
        //累加
        for(int i=0;i<max;++i){
            cnt[i+1] = cnt[i+1] + cnt[i];
        }
        for(int i=0;i<n;++i){
            tmp[cnt[a[i]]-1] = a[i];
            cnt[a[i]] -= 1;
        }
        for(int i=0;i<n;++i){
            a[i] = tmp[i];
        }
        delete []tmp;
        delete []cnt;
    }
};
int main(){
    Interface* a = new CountSort();
    int b[5] = {3,2,4,1,5};
    a->sort(b,5);
    for(auto item:b){
        cout << item << endl;
    }
    return 0;
}
