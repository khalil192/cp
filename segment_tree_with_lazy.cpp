/******************************************************************************

segment trees with lazy propagation and lazy updates queries
goals: prepare a segment trees 
 lazy updates
 lazy updated queries
 voila ->
*******************************************************************************/
#include <stdio.h>
#include<iostream>
using namespace std;
int get_mid(int l,int r){
    return l+(r-l)/2;
}
void create_tree(int arr[],int seg[],int l,int r,int pos){
    if(l==r){
      //this is the position of leaf node in segment tree...
          seg[pos] = arr[l];
        return;
    }
    int mid = get_mid(l,r);
    //complete preparing children nodes and recurse to top...
    create_tree(arr,seg,l,mid,2*pos+1);
    create_tree(arr,seg,mid+1,r,2*pos+2);
    seg[pos] = seg[2*pos+1] + seg[2*pos+2];
}
//update the segment tree in lazy format;;
void lazy_update(int seg[],int lazy[],int l,int r,int pl,int pr,int pos,int diff){
    //complte the pending lazy update and then proceed..
    if(lazy[pos]!=0){
        //that means there is a pending update...
        //sum up the pending update to the current node in segment tree and then keep the updates to the children as lazy.....
        seg[pos] += (pr-pl+1)*lazy[pos];
        if(pl!=pr){
            lazy[2*pos+1] += lazy[pos];
            lazy[2*pos+2] += lazy[pos];
        }
        lazy[pos]=0;
    }
    //now that lazy pending update part is completed...
    
    //but if the current indexes are out of range of the needed indices then return with out any updation......
    if(pl> r || l>pr || pl>pr){
        return;
    }
    
    //if the present indices completely overlaps with the required ones then ....
    //add the diff to cuurent in segment tree and delay the children's updates in lazy tree...
    if(pl>=l && pr<=r){
        seg[pos] += (pr-pl+1)*diff;
        //if not leaf node then store the children's updates in lazy tree...
        if(pl!=pr){
            lazy[2*pos+1] += diff;
            lazy[2*pos+2] += diff;
        }
        return;
    }
    
    //if the current indices partially overlaps with the required indices then recurse the children and update the present..
    int mid = get_mid(pl,pr);
    lazy_update(seg,lazy,l,r,pl,mid,2*pos+1,diff);
    lazy_update(seg,lazy,l,r,mid+1,pr,2*pos+2,diff);
    seg[pos] = seg[2*pos+1] + seg[2*pos+2];
}

int lazy_query(int seg[],int lazy[],int l,int r,int pl,int pr,int pos){
    //check for pending updates if any then update the current node in segment_tree...
    if(lazy[pos] !=0 ){
        seg[pos] = (pr-pl+1)* lazy[pos];
        //if the current is not a leaf node then we need to delay the children's update in the lazy _tree....
        if(pl!=pr){
            lazy[2*pos+1] +=lazy[pos];
            lazy[2*pos+2] +=lazy[pos];
        }
        lazy[pos]=0;
    }
    //if the present indices are out of the required then return 0
    if(r<pl || l>pr || pl>pr){
        return 0;
    }
    //if completely overlapped then we need to send the whole value in present 
    if(pl>=l && pr<=r){
        return seg[pos];
    }
    int mid = get_mid(pl,pr);
    return lazy_query(seg,lazy,l,r,pl,mid,2*pos+1) + lazy_query(seg,lazy,l,r,mid+1,pr,2*pos+2);
     
}
int main()
{
    int arr[5] = {1,2,3,4,5};
    //lazy tree and segment tree should be of same size as they are parallel...means one index in both arrays represent same range in main array....
    int seg[30],lazy[30];
    for(int i=0;i<30;i++){
        lazy[i] =0;
    }
    int n = 5;
    create_tree(arr,seg,0,n-1,0);
        cout<<lazy_query(seg,lazy,0,3,0,n-1,0)<<endl;

    lazy_update(seg,lazy,1,3,0,n-1,0,-1);
    
    cout<<lazy_query(seg,lazy,0,3,0,n-1,0)<<endl;
    
    
    return 0;
}


