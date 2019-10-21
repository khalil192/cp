/*
USEFUL comments along with sample usage are yet to be added......
fenwick trees use case : 
benifits ..........
*/

#include<stdio.h>
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
#define MAXI 1000
/* 
fenwick trees are 1 based indexed array...
note that the original array should be 1 based indexed as well as the tree
*/
int original_arr[MAXI],Btree[MAXI],n;

int lsb(int i){
    return i&-i;
}

void initialise(){
for(int i=0;i<n;i++)    Btree[i] = original_arr[i];
for(int i=1;i<=n;i++){
    int j = i+lsb(i);
    if(j<=n)    Btree[j] += Btree[i];
}
}
int prefix_query(int i){
    int sum = 0;
    while(i>0){
        sum += Btree[i];
        i -= lsb(i);
    }
    return sum;
}
int range_query(int i,int j){ 
    return prefix_query(j) - prefix_query(i-1);
    }
void update(int i,int val){
     while(i<=n){
        Btree[i] += val;
        i+=lsb(i);
    }
}

int main(){

return 0;
}