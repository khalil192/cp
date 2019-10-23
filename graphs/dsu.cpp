/*
well Disjoint set union has always been one my favourite DS
it's simplicity and yet powerful applications are worth knowing and appreciating..
*/

#include<stdio.h>
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
#define MAXI 1000
int par[MAXI],sz[MAXI];
//par[i] array contains parent of ith node
// sz[i] contains if i is the  parent of i then size of the ith family...

int root(int i){
    while(par[i]!=i)
        par[i] = par[par[i]], i = par[i]; 
    return i;
}
// you have to be careful while joining two nodes..
//it really depends on the problem when to join two nodes..
void join(int i,int j){ // this is weighted join method which is done of time-optimisation
    i = root(i),j = root(j);
    if(i==j){return;} //if both have same parents then they are already joined..
    if(sz[i]>sz[j])
        sz[i] += sz[j] ,par[j] = i;
    else
        sz[j] += sz[i], par[i] = j;
}
void ini(){
    for(int i=0;i<MAXI;i++)
        par[i] = i,sz[i] = 1;
}

int main(){
    ini();
    return 0;
}