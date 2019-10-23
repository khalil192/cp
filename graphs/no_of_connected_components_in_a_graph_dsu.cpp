/*
often we have to calculate the no of strongly connected components in a
graph..
which obviously has numerous application in real-life too..
like counting no of islands in a map..  
*/
#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
#define MAXI 1000
int par[MAXI],sz[MAXI];
int n = MAXI;
//par[i] array contains parent of ith node
// sz[i] contains if i is the  parent of i then size of the ith family...
vector<int > graph[MAXI];
int root(int i){
    while(par[i]!=i)
        par[i] = par[par[i]], i = par[i]; 
    return i;
}
void join(int i,int j){ // this is weighted join method which is done of time-optimisation
    i = root(i),j = root(j);
    if(i==j){return;} //if both have same parents then they are already joined..
    if(sz[i]>sz[j])
        sz[i] += sz[j] ,par[j] = i;
    else
        sz[j] += sz[i], par[i] = j;
}
void ini(){ // this method initialises the required arrays 
    for(int i=0;i<MAXI;i++){
        par[i] = i;//initially every i has i as its parent
        sz[i] = 1; // as each i has only family memeber...itself
    }
}
int find_no_of_connected_components(){
    //for every edge we are performing the join operation..
    //because they are supposed to be in same family..
    for(int node=0;node<n;node++){
        for(int curr : graph[node]){
            join(node,curr);
        }
    }
    int visi[n],no_of_connected_components =0;
    for(int  i=0;i<n;i++) visi[i] = 0;
    for(int i=0;i<n;i++){
        int j = root(i);
        if(visi[j] == 0){
            visi[j] =1;
            no_of_connected_components++;
        }
    }
 
        return no_of_connected_components;
}
void add_edge(int i,int j){
    graph[i].push_back(j);
    graph[j].push_back(i);
}
int main(){
    // after initialising the graph...
    //we will have to find no of connected components in the graph..
    ini();
    n = 10;
    add_edge(0,1);
    add_edge(1,2);
    add_edge(2,3);
    add_edge(1,3);
    add_edge(3,4);
    add_edge(5,6);
    add_edge(5,7);
    add_edge(8,9);
    
    int no_of_connected_components = find_no_of_connected_components();
    cout<< "the no of connected components in the graph are "
        <<no_of_connected_components<<endl;
    return 0;
}