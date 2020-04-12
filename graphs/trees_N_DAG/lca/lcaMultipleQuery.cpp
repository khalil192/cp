#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;



class segmentTree{
    public :
        vector<int> segTree;
        vector<int>depth;
        int n;
        segmentTree(){}
        segmentTree(vector<int>&a , vector<int>&d){
            n = a.size();
            depth = d;
            segTree.resize(4*n+1);
            buildSegTree(a,0,0,n-1);
        }
        void buildSegTree(vector<int>&a,int currIdx , int left , int right){
            if(left == right){segTree[currIdx] = a[left];return;}
            int middle = (left + right)/2;
            buildSegTree(a,currIdx*2+1 , left , middle);
            buildSegTree(a,currIdx*2+2 , middle+1 ,right);
            segTree[currIdx] = func(segTree[currIdx*2+1] , segTree[currIdx*2+2]);
        }
        int query(int currIdx , int treeLeft , int treeRight,int left , int right){
            if(right < treeLeft || left > treeRight){   return singleNonOverlappingReturn();} // not overlapping
            if(treeLeft >= left && treeRight <= right){ return segTree[currIdx];    } // completely overlapping
            int mid = (treeLeft + treeRight)/2;
            return  func(query(currIdx*2+1,treeLeft,mid ,left,right) ,
                         query(currIdx*2+2 ,mid+1,treeRight,left,right));
        }
        int rangeQuery(int l,int r){
            return query(0,0,n-1,l,r);
        }
        //add diff at pos in the original array...
        int func(int x,int y){
            if(x==INT_MAX){return y;}
            if(y==INT_MAX){return x;}
            return depth[x] < depth[y] ? x:y;
        }
        int singleNonOverlappingReturn(){
            return INT_MAX;
        }
};

class lcaFinder{
    public:
        int n , timeCounter = 0;
        vector<int>eulerPath;
        vector<int>depth;
        vector<int> first;
        segmentTree segTree;
        lcaFinder(vector<vector<int> >&adj){
            n = adj.size();
            depth.resize(n,-1);
            first.resize(n);
            timeCounter = 0;
            fillEulerTour(0,0,adj);
            cout<<"euler path is :";
            for(int i : eulerPath){
                cout<<i<<" "; 
            }
            cout<<endl;
             segTree = segmentTree(eulerPath,depth);
            //after finding euler tour...
            // now we need to construct the sparseTable / segment Tree
        }
        void fillEulerTour(int node ,int currDepth,vector<vector<int> >&adj){
            depth[node] = currDepth;
            eulerPath.push_back(node);
            cout<<"first of "<<node<<" is "<<timeCounter<<endl;
            first[node] = timeCounter++;
            for(int to : adj[node]){
                if(depth[to] == -1){
                    fillEulerTour(to,currDepth+1,adj);
                    eulerPath.push_back(node);
                    timeCounter++;
                }
            }
        }
        int lca(int node1,int node2){
            cout<<"looking in  "<<first[node1]<<" "<<first[node2]<<endl;
            int l = min(first[node1] , first[node2]);
            int r =  max(first[node1] , first[node2]);
           return segTree.rangeQuery(l , r);
        }
};

void addEdge(int i ,int j , vector<vector<int> >&adj){
    adj[i].push_back(j);
    adj[j].push_back(i);
}


int main(){
    int n = 7;
    vector<vector<int> >adj(n);
    addEdge(0,1,adj);
    addEdge(0,5,adj);
    addEdge(1,2,adj);
    addEdge(1,3,adj);
    addEdge(2,4,adj);
    addEdge(6,5,adj);
    lcaFinder lc = lcaFinder(adj);

    int c = 3;
    while(c--){
        int l,r;
        cin>>l>>r;
        cout<<lc.lca(l,r)<<endl;
    }
    return 0;
}
