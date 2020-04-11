#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;


// the func in the segmentTree class controls the segment tree.
//simply changing 2 lines the segment tree can be manipulated into ...
// sum , product , range min , range max .

class segmentTree{

    public :
        vector<int> segTree;
        int n;
        segmentTree(vector<int>&a){
            n = a.size();
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
        void update(int currIdx , int treeLeft , int treeRight ,int pos, int diff){
            if(treeLeft > pos || treeRight < pos){  return; }
            if(treeLeft == treeRight){
                segTree[currIdx] += diff;
                return;
            }
            int mid = (treeLeft+treeRight)/2;
            update(currIdx*2+1 , treeLeft ,mid ,pos,diff);
            update(currIdx*2+2 , mid+1,treeRight,pos,diff);
            segTree[currIdx] = func(segTree[currIdx*2+1] , segTree[currIdx*2+2]);
        }
        void pointUpdate(int pos , int diff){
            update(0,0,n-1,pos,diff);  
            }
        int func(int x,int y){
            return min(x,y);
        }
        int singleNonOverlappingReturn(){
            return INT_MAX;
        }
};

int main(){

    vector<int> a;
    a.push_back(1);
    a.push_back(-2);
    a.push_back(3);
    a.push_back(1);
    a.push_back(-2);
    a.push_back(-3);

    segmentTree st =  segmentTree(a);
    int c =2,l,r;
    while(c--){
        cin>>l>>r;
        cout<<st.rangeQuery(l,r)<<endl;
    }
    cout<<"enter update pos , val"<<endl;
    cin>>l>>r;
    st.pointUpdate(l,r);
    c =2;
    while(c--){
        cin>>l>>r;
        cout<<st.rangeQuery(l,r)<<endl;
    }

    return 0;
}
