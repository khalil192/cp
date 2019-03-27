/******************************************************************************
flipping coins codechef question...
we have two types of operations 
1: flip all the coins between l ..r indices 
2: query of no of heads between two indices  l...r .intially all the coins tossed up
0 represents toss and 1 represents heads..
*******************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define lli long long int
#define fo(i,n) for(lli i=0;i<(n);i++)
#define pf printf
#define pb push_back
#define sf scanf
#define vi vector<lli>
#define nl pf("\n")
using namespace std;
lli test;
lli mod = 1e9 +7; 
lli inp(){
    sf("%lld",&test);
    return test;
}
lli get_mid(lli l,lli r){
    return l+(r-l)/2;
}
//each segment in the tree stores the number of heads in the range
//now we need to implement two functions :: for update and one for query 
//l ,r -- required indices...pl, pr ---present indices...pos is present index position in segment tree
void lazy_update(lli seg[],lli lazy[],lli l,lli r,lli pl,lli pr,lli pos){
    //if there is any pending update then  do it..
    //observations ::
    //1.if a range is flipped twice we get the same value only do the flip if the delayed is an odd number
    if(lazy[pos]!=0){
            seg[pos] = ((pr-pl+1) - seg[pos]) * (lazy[pos]%2) + seg[pos] * ((lazy[pos]+1) %2);
            //if not a leaf node then update the children
            if(pl!=pr){
                lazy[2*pos+1]+=lazy[pos];
                lazy[2*pos+2]+=lazy[pos];
            }
            lazy[pos]=0;
        }
    //if out of range then return..
    if(pr<l || r< pl|| pl>pr){
        return;
    }
    //if completely in range then updaTE THE current and return..
    if(pl>= l && pr<= r){
        seg[pos] = (pr-pl+1) - seg[pos];
        //if it is not a leaf node then lazy it's childrens update...
        if(pl!=pr){
            lazy[2*pos+1]+=1;
            lazy[2*pos+2]+=1;
        }
        return;
    }
    // now is the case of partial overlapping we have to recurse to children and update the present pos later ..
    lli mid = get_mid(pl,pr);
    lazy_update(seg,lazy,l,r,pl,mid,2*pos+1);  lazy_update(seg,lazy,l,r,mid+1,pr,2*pos+2);
        seg[pos] = seg[2*pos+1] + seg[2*pos+2];
        //now update is completed ..
    }

// given a pair of indices we have to return then number of heads int that range....

lli lazy_query(lli seg[],lli lazy[],lli l,lli r,lli pl,lli pr,lli pos){
// if the current node is not empty update it..
if(lazy[pos]!=0){
            seg[pos] = ((pr-pl+1) - seg[pos]) * (lazy[pos]%2) + seg[pos] * ((lazy[pos]+1) %2);
            //if not a leaf node then update the children
            if(pl!=pr){
                lazy[2*pos+1]+=lazy[pos];
                lazy[2*pos+2]+=lazy[pos];
            }
            lazy[pos]=0;
        }
    //if completely out of range then return 0;;
    if(l>r || pl > r || l>pr){return 0;}
    // IF completely falls in the present range the  the current value in the node:::
    if(pl>=l && pr<=r){
        return seg[pos];
    }
    // at this step it must be partially overlapping ...then recurse to children and return the sum of children's nodes...
    int mid = get_mid(pl,pr);
    return lazy_query(seg,lazy,l,r,pl,mid,2*pos+1) + lazy_query(seg,lazy,l,r,mid+1,pr,2*pos+2);
}
//0 -- toss::::  1---heads
void solve(){
 lli n = inp(),q = inp();
 lli arr[n],seg[5*n],lazy[5*n];
 fo(i,n){
     arr[i] =0;
 }
 lli num = 5*n;
 fo(i,num){seg[i]=0;lazy[i]=0;}
 
 lli Q,l,r;
 fo(i,q){
     sf("%lld%lld%lld",&Q,&l,&r);
     if(Q==0){
       lazy_update(seg,lazy,l,r,0,n-1,0);
     }else{
         pf("%lld",lazy_query(seg,lazy,l,r,0,n-1,0));nl;
     }
 }
 
}
int main()
{
    solve();
    return 0;
}

