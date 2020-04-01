#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

//count all downward paths in binary tree which sum to k
// can start at any node and end at node as long as the path is downward
// we can do this O(n) where n is number of nodes
// doing a preorder traversal and as an  

struct node{
    int val;
    struct node *left , *right;
};
struct node* newNode(int val){
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp->val   = val;
    temp->left  = NULL;
    temp->right = NULL;
    return temp;
}

void countKSumPath(struct node* root ,unordered_map<int,int> sumsMap,int pastSum,int k,int &cnt ){
    if(!root){  return; }
    
    if(pastSum + root->val == k){
        cnt += 1;
    }
    cnt += sumsMap[pastSum + root->val -k];
}



int main(){
    struct node* root = newNode(3);
    root->left = newNode(5);
    root->left->left = newNode(6);
    root->left->right = newNode(0);
    
    root->right = newNode(3);
    root->right->left = newNode(-1);

    root->right->right = newNode(5);
    root->right->right->left = newNode(3);
    root->right->right->right = newNode(4);
    root->right->right->right->right = newNode(1);
    int k = 11;
    vector<int> path;
    // printKSumPath(root,path,k);
    return 0;
}
