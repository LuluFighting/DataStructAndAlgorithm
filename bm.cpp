//
// Created by Admin on 2019/10/29.
//
#include <string>
using namespace std;
void generateBC(string b,int m,int *bc){
    for(int i=0;i<256;++i){
        bc[i] = -1;
    }
    for(int i=0;i<b.size();i++){
        bc[(int)b[i]] = i;
    }
}
void generateGS(string b,int m,int* suffix, bool* prefix){
    for(int i=0;i<m;++i){
        suffix[i] = -1;
        prefix[i] = false;
    }
    for(int i=0;i<m-1;++i){
        int j=i,k=0;
        while(j>=0 && b[j] == b[m-1-k]){
            --j;
            ++k;
            suffix[k] = j+1;
        }
        if(j==-1) prefix[k] = true;
    }
}
int moveByGS(int j,int m,int *suffix,bool *prefix){
    int length = suffix[m-j-1];
    if(length!=-1){
        return j - suffix[m-j-1] + 1;
    }
    int r=j+2;
    while(r<m){
        if(prefix[m-r] == true) return r;
    }
    return m;
}
int bm(string a,int n,string b,int m){
    int *bc = new int[256]();
    generateBC(b,m,bc);
    int *suffix = new int[b.size()+1]();
    bool *prefix = new bool[b.size()+1]();
    generateGS(b,m,suffix,prefix);
    int i=0;
    while(i<=n-m){
        int j;
        for(j=m-1;j>=0;--j){
            if(a[i+j]!=b[j]) break;  //找到了坏字符
        }
        if(j<0){
            return i; //匹配成功，返回主串与模式串第一个匹配的字符的位置
        }
        int x = j - bc[(int)a[i+j]];
        int y=0;
        if(j<m-1){
            y = moveByGS(j,m,suffix,prefix);
        }
        i = i + max(x,y);
    }
    return -1;
}

