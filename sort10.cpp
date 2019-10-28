//
// Created by Admin on 2019/10/17.
//
#include <iostream>
using namespace std;

class Interface{
public:
    virtual void sort(int* a,int n)=0;
};

class BubbleSort
        :public Interface{
public:
    void sort(int* a,int n) {
        if (n <= 0) return;
        bool flag = false;
        for (int i = n; i > 0; --i) {
            flag = false;
            for (int j = 0; j < i; ++j) {
                if (a[j] > a[j + 1]) {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                    flag = true;
                }
            }
            if (!flag) break;
        }
    }
};

class InsertSort
        :public Interface{
public:
    void sort(int* a,int n){
        if(n<=0) return;
        for(int i=1;i<n;++i){
            int temp = a[i],j;
            for(j=i-1;j>=0&&a[j]>temp;j--)
                a[j+1] = a[j];
            a[j+1] = temp;
        }
    }
};
class SelectSort
        :public Interface{
public:
    void sort(int* a,int n){
        if(n<=0) return;
        for(int i=0;i<n;++i){
            int minNum = a[i],minIndex=i;
            for(int j=i;j<n;++j){
                if(a[j]<minNum){
                    minNum = a[j];
                    minIndex = j;
                }
            }
            int temp = a[minIndex];
            if(minIndex!=i){
                a[minIndex] = a[i];
                a[i] = temp;
            }
        }
    }
};

class MergeSort
        :public Interface{
public:
    void sort(int* a,int n){
        if(n<=0) return;
        _merge_sort_c(a,0,n-1);
    }
private:
    void _merge_sort_c(int *a,int left,int right){
        if(left>=right) return;
        int mid = left + (right-left)/2;
        _merge_sort_c(a,left,mid);
        _merge_sort_c(a,mid+1,right);
        merge(a,left,mid,right);
    }
    void merge(int *a,int left,int mid ,int right){
        int * tmp = new int[right-left+1]();
        int k=0,i,j;
        for(i=left,j=mid+1;i<=mid&&j<=right;){
            if(a[i]<=a[j]) tmp[k++] = a[i++];
            else tmp[k++] = a[j++];
        }
        while(i<=mid) tmp[k++] = a[i++];
        while(j<=right) tmp[k++] = a[j++];
        k=0;
        for(int i=left;i<=right;i++){
            a[i] = tmp[k++];
        }
        delete []tmp;
    }
};
class QuickSort
        :public Interface{
public:
    void sort(int* a,int n){
        if(n<=0) return;
        _quick_sort_c(a,0,n-1);
    }

private:
    int partition(int* a,int left,int right){
        int pivot = a[right];
        int i=left,j=left;
        for(j=left;j<right;++j) {
            if (a[j] < pivot) {
                int tmp = a[j];
                a[j] = a[i];
                a[i] = tmp;
                i++;
            }
        }
        a[right] = a[i] ;
        a[i] = pivot;
        return i;
    }
    void _quick_sort_c(int* a,int left,int right){
        if(left>=right)
            return;
        int k = partition(a,left,right);
        _quick_sort_c(a,left,k-1);
        _quick_sort_c(a,k+1,right);
    }
};

class HeapSort
        :public Interface{
public:
    void sort(int* a,int n){
        _build_heap(a,n);
        for(int i=1;i<n;++i){
            int tmp = a[1];
            a[1] = a[n-i+1];
            a[n-i+1] = tmp;
            _sift_down(a,1,n-i);
        }
    }
private:
    void _build_heap(int *a,int n){
        for(int i=n/2;i>=1;i--){
            _sift_down(a,i,n);
        }
    }
    void _sift_down(int *a ,int start,int n){
        int i = start,j= 2*start;
        while(j<=n){
            if(j+1 <= n && a[j+1]>a[j]) j++;
            if(a[i]>a[j]) break;
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i=j;
            j=2*i;
        }
    }

};

int main(){
    Interface* a = new HeapSort();
    int b[6] = {0,3,2,4,1,5};
    a->sort(b,5);
    for(auto item:b){
        cout << item << endl;
    }
    return 0;
}

