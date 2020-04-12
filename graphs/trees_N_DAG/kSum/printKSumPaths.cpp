#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

//print all downward paths in binary tree which sum to k
// can start at any node and end at node as long as the path is downward


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
void printVector(vector<int>&path , int start){
    for(int i = start;i<path.size();i++){
        cout<<path[i]<<" ";
    }
    cout<<endl;
}
void printKSumPath(struct node* root,vector<int> &path,int k){
    if(root==NULL){return;}
    path.push_back(root->val);
    printKSumPath(root->left , path,k);
    printKSumPath(root->right ,path,k);

    int currPathSum = 0;
    for(int i = path.size()-1;i>=0;i--){
        currPathSum += path[i];
        if(currPathSum == k){
            printVector(path ,i);
        }
    }
    path.pop_back();
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
    printKSumPath(root,path,k);
    return 0;
}