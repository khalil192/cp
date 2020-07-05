#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<queue>
#include<deque>
#include<stack>
#include<algorithm>
#include<iterator>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#define lli long long int
#define mp make_pair
#define ULTRA_INSTINCT ios_base::sync_with_stdio(false); cin.tie(0)
#define fo(i,n) for(lli i=0;i<(n);i++)
#define FO(i,x,n) for(lli i=(x);i<(n);i++)
#define pb push_back
#define FI first
#define SE second
#define vi vector<lli>
#define pi pair<lli,lli>
#define vii vector<pi >
#define Endl endl
#define ITA 200005
#define ROH 100005
#define deb(x) cout<<(#x)<<" "<<x<<endl
using namespace std;
lli mod = 1e9 +7,test; 


// the func in the segmentTree class controls the segment tree.
//simply changing 2 lines the segment tree can be manipulated into ...
// sum , product , range min , range max .




class segmentTree{
    public :
        vector<lli> segTree;
        lli n;
        segmentTree(vector<lli>&a){
            n = a.size();
            segTree.resize(4*n+1);
            buildSegTree(a,0,0,n-1);
        }
        void buildSegTree(vector<lli>&a,lli currIdx , lli left , lli right){
            if(left == right){segTree[currIdx] = a[left];return;}
            lli middle = (left + right)/2;
            buildSegTree(a,currIdx*2+1 , left , middle);
            buildSegTree(a,currIdx*2+2 , middle+1 ,right);
            segTree[currIdx] = func(segTree[currIdx*2+1] , segTree[currIdx*2+2]);
        }
        lli query(lli currIdx , lli treeLeft , lli treeRight,lli left , lli right){
            if(right < treeLeft || left > treeRight){   return singleNonOverlappingReturn();} // not overlapping
            if(treeLeft >= left && treeRight <= right){ return segTree[currIdx];    } // completely overlapping
            lli mid = (treeLeft + treeRight)/2;
            return  func(query(currIdx*2+1,treeLeft,mid ,left,right) ,
                         query(currIdx*2+2 ,mid+1,treeRight,left,right));
        }
        lli rangeQuery(lli l,lli r){
            return query(0,0,n-1,l,r);
        }
        //add diff at pos in the original array...
        void update(lli currIdx , lli treeLeft , lli treeRight ,lli pos, lli diff){
            if(treeLeft > pos || treeRight < pos){  return; }
            if(treeLeft == treeRight){
                segTree[currIdx] += diff;
                return;
            }
            lli mid = (treeLeft+treeRight)/2;
            update(currIdx*2+1 , treeLeft ,mid ,pos,diff);
            update(currIdx*2+2 , mid+1,treeRight,pos,diff);
            segTree[currIdx] = func(segTree[currIdx*2+1] , segTree[currIdx*2+2]);
        }
        void pointUpdate(lli pos , lli diff){
            update(0,0,n-1,pos,diff);  
            }
        lli func(lli x,lli y){
            return min(x,y);
        }
        lli singleNonOverlappingReturn(){
            return INT_MAX;
        }
};

int main(){

    vector<lli> a;
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
