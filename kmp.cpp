//
// Created by Admin on 2019/10/30.
//
#include <string>
using namespace std;
void generateNext(string b,int m,int* next){
    for(int i=0;i<m;++i){
        next[i] = -1;
    }
    int i=1,k=-1;
    for(i=1;i<m;i++){
        while(k!=-1 && b[k+1]!=b[i])
            k = next[k];
        if(b[k+1]==b[i])
            k++;
        next[i] = k;
    }
}
int kmp(string a,int n,string b,int m){
    int i,k;
    int *next = new int[m]();
    generateNext(b,m,next);
    for(i=0,k=-1;i<n;++i){
        while(k>=0 && a[i]!=b[k+1])
            k = next[k];
        if(b[k+1] == a[i]){
            k++;
        }
        if(k==m-1) return i-m-1;
    }
    return -1;
}