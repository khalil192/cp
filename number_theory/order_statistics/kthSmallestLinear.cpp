#include<iostream>
#include<stdio.h>
#include <stdlib.h> 
#include<time.h> 
using namespace std;

void swap(int arr[], int l,int r){
    int val = arr[l];
    arr[l] = arr[r];
    arr[r] = val;
}
int partition(int arr[],int l,int r);
int randomPartition(int arr[],int l,int r);

int findKthSmallest(int arr[],int l,int r,int k){
    // if(l>r){return -1;}
    if(k<0 || k > (r-l+1) ){return INT_MAX;}
    int currPivotPos = randomPartition(arr,l,r);
    if(currPivotPos - l == k-1) 
         return arr[currPivotPos];
    if(currPivotPos-l > k-1){
        return findKthSmallest(arr,l,currPivotPos-1,k);
    }
    return findKthSmallest(arr,currPivotPos + 1,r,k-currPivotPos + l-1);
}   
int randomPartition(int arr[],int l,int r){
    int len = r-l+1;
    int offset = rand();
    // cout<<rand()<<" "<<len<<endl;
    offset = offset%len;
    swap(arr,l+offset,r);
    return partition(arr,l,r);
}
int partition(int arr[],int l,int r){
    // take last element as pivot...
    //arr[r] as pivot.....
    int lastAllocated = l,pivotEle = arr[r];
    for(int i = l;i<r;i++){
        if(arr[i] < pivotEle){
            swap(arr,lastAllocated,i);           
            lastAllocated ++;
        }
    }
    swap(arr,lastAllocated ,r);
    return lastAllocated;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<findKthSmallest(arr,0,n-1,3)<<endl;
    cout<<findKthSmallest(arr,0,n-1,6)<<endl;
    cout<<findKthSmallest(arr,0,n-1,1)<<endl;
    cout<<findKthSmallest(arr,0,n-1,12)<<endl;
    cout<<findKthSmallest(arr,0,n-1,1)<<endl;

    return 0;
}