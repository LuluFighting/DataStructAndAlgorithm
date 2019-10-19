//
// Created by Admin on 2019/10/19.
//
#include <iostream>
using namespace std;

int binarySort(int* a,int n,int target){
    int left=0,right = n-1;
    while(left<=right){
        int mid = left + (right - left) / 2 ;  //不用（left+right）/ 2 的原因是可能left和right比较大导致溢出
        if(a[mid] == target){
            return mid;
        } else if(a[mid]>target)  right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}

//变体1：查找第一个值等于给定的值的元素
int binarySort1(int* a,int n,int target){
    int left=0,right=n-1;
    while(left<=right){
        int mid = left + ((right - left) >> 1);
        if(a[mid] > target)  left = mid + 1;
        else if(a[mid] < target) right = mid-1;
        else {
            if (mid == 0 || a[mid - 1] != target) return -1;
            right = mid - 1;
        }
    }
    return -1;
}
//变体2：查找最后一个值等于给定值的元素
int binarySort2(int* a,int n,int target){
    int left=0,right = n-1;
    while(left<=right){
        int mid = left + ((right-left)>>1);
        if(a[mid]>target) right = mid-1;
        else if(a[mid] < target)  left = mid+1;
        else{
            if(mid==n-1 || a[mid+1]!=target) return mid;
            left = mid+1;
        }
    }
    return -1;
}
//变体3：查找第一个大于等于给定值的元素
int binarySort3(int* a,int n,int target){
    int left=0,right = n-1;
    while(left<=right){
        int mid = left + ((right - left)>>1);
        if(a[mid>=target]){
            if(mid==0 || a[mid-1]<target) return mid;
            right = mid-1;
        }else left = mid+1;
    }
    return -1;
}

//变体4：查找最后一个小于等于给定值的元素
int binarySort4(int* a,int n,int target){
    int left=0,right= n-1;
    while (left<=right){
        int mid = left + ((right - left) >> 1);
        if(a[mid]<=target){
            if(mid==n-1 || a[mid+1]>target) return mid;
            else left = mid+1;
        }else right = mid-1;
    }
    return -1;
}

