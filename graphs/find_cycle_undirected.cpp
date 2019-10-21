#include<stdio.h>
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
#define MAXI 100
vector<int> graph_directed[MAXI];
int visi_directed[MAXI];
int par[MAXI];
int cycle_start=-1,cycle_end=-1,n; // n is no of nodes
bool dfs_directed(int node,int node_par){
    cout<<node<<" ";
    visi_directed[node]=1;
    for(int curr : graph_directed[node]){
        if(curr == node_par){continue;}
        if(visi_directed[curr]==2){continue;}
        if(visi_directed[curr]==1){
           //gray node
           cycle_start = node;
            return true;        
        }
        par[curr] = node;
        // now we have non visited curr
        if(dfs_directed(curr,node)){
            return true;
        }
    }   
    visi_directed[node] =2;
    return false;
}
void print_cycle(int curr){
    if(curr!=-1){
        print_cycle(par[curr]);
        cout<<curr<<" ";
        return;
    }
    cout<<endl;
}
void find_cycle_directed(){
for(int i=0;i<n;i++){
    visi_directed[i] = 0;
    par[i] = -1;
}
for(int i=0;i<n;i++){
    if(visi_directed[i]==0){
    if(dfs_directed(i,-1)){
        break;
    }   
    }
}
if(cycle_start ==-1){
    cout<<"the graph is asyclic.."; return;
}
cout<<cycle_start<<endl;
cout<<endl;
for(int i=0;i<n;i++){
    cout<<par[i]<<" ";
}
print_cycle(cycle_start);
}

int main(){
n = 8;
graph_directed[0].push_back(1);
graph_directed[0].push_back(4);
graph_directed[1].push_back(0);
graph_directed[4].push_back(0);

graph_directed[1].push_back(2);
graph_directed[2].push_back(1);

graph_directed[2].push_back(4);
graph_directed[2].push_back(7);
graph_directed[4].push_back(2);
graph_directed[7].push_back(2);


graph_directed[4].push_back(5);
graph_directed[5].push_back(4);
graph_directed[5].push_back(0);
graph_directed[0].push_back(5);
graph_directed[5].push_back(6);
graph_directed[6].push_back(5);
graph_directed[0].push_back(6);

graph_directed[6].push_back(0);
// graph_directed[0].push_back(1);

find_cycle_directed();

}

