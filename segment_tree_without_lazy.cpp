/******************************************************************************
segment trees without lazy updates

*******************************************************************************/
#include <stdio.h>
#include<iostream>
using namespace std;
int get_mid(int l,int r){
    return l + (r-l)/2;
}

int create_tree(int arr[],int seg[],int l,int r,int pos){
    if(l==r){
        seg[pos] = arr[l];
        return seg[pos];
    }
    int mid = get_mid(l,r);
    seg[pos] = create_tree(arr,seg,l,mid,pos*2 + 1) + create_tree(arr,seg,mid+1,r,2*pos+2);
    return seg[pos];
}

int query(int seg[],int l,int r,int pl,int pr,int pos){
    //if doesn't overlap returns 0;
    if(r<pl || l>pr){
        return 0;
    }
    //if  pl and pr  completely overlaps then return the value in the node
    if(pl>=l && pr<=r){
        return seg[pos];
    }
    // this is the case of partial overlapping
    //go both directions and return the respective result...
    int mid = get_mid(pl,pr);
    return query(seg,l,r,pl,mid,2*pos+1) + query(seg,l,r,mid+1,pr,2*pos+2);
}
void update_value(int seg[],int idx,int pl,int pr,int pos,int diff){
    //if completely out of range then return from this .....
    if(idx>pr || idx<pl){
        return;
    }
    //do the update here and then traverse down as it is a single update...
    seg[pos]+= diff;
    if(pl!=pr){
        int mid = get_mid(pl,pr);
        update_value(seg,idx,pl,mid,2*pos+1,diff);
        update_value(seg,idx,mid+1,pr,2*pos+2,diff);  
    }
}

int main()
{
     int arr[] = {1,2,3,4};
     int seg[20];
     create_tree(arr,seg,0,3,0);
     cout<<query(seg,0,2,0,3,0)<<endl;
     update_value(seg,1,0,3,0,100);
          cout<<query(seg,0,2,0,3,0)<<endl;

    //  cout<<query(seg,1,3,0,3,0)<<endl;
    //  cout<<query(seg,2,3,0,3,0)<<endl;

    return 0;
}

