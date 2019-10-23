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
int par[MAXI],sz[MAXI],n;
//par[i] array contains parent of ith node
// sz[i] contains if i is the  parent of i then size of the ith family...
vector<int> graph[MAXI];
// graph is a array of vectors .. which is adjacency list version of the graph


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
int detect_cycle(){
    ini();
    int i,j;
    for(int node=0;node<n;node++){
        i = root(node);
        for(int curr : graph[node]){
            j =root(j);
            if(i==j){ return 1; }
            join(i,j);
        }
    }
    return 0;
}

void add_edge(int i,int j){//adds undirected egde btwn node i,j
    graph[i].push_back(j), graph[j].push_back(i);
}

int main(){
    n = 5; // initialise n's value i as max(nodes) +1;
    add_edge(0,1);
    add_edge(1,2);
    add_edge(2,4);
    add_edge(4,1);
    // add_edge(0,1);
    int ans = detect_cycle();
    if(ans)
        cout<<"there is a cycle in the graph..\n";
    else
        cout<<"there is no cycle in the graph...\n";
    
    return 0;
}