#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;



class DSU{ 
public:
    vector<int> parent, size;
    DSU(int n){
        parent.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
 
    int root(int i){
        while(parent[i] != i){
            parent[i] = parent[parent[i]];
            i = parent[i];
        }
        return i;
    }
 
    void join(int a, int b){
        a = root(a);
        b = root(b);
        if(a != b){
            if(size[a] < size[b]){
                swap(a, b);
            }
            parent[b] = a;
            size[a] += size[b];
        }
    }
};
 


int main(){
        return 0;
}