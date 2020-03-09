//the tree format is taken as adjacency list..
//the id of tree is the number on node

#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

struct node{
    int id;
    struct node *left,*right;
};

string getSerialCodeString(struct node* root){
    string currCode = ""; 
    if(root == NULL){return currCode;}
    // cout<<"came to "<<root->id<<endl;
    string leftCode  = getSerialCodeString(root->left);
    string rightCode = getSerialCodeString(root->right);
    if(leftCode.length() > rightCode.length()){
        currCode = leftCode+rightCode;
    }else{
        currCode = rightCode+leftCode;
    }
    return '('+ currCode + ')';
}
struct node* newNode(int id){
    struct node* temp = new node();
    temp->id = id;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node* fillTree1(struct node* root){
    root = newNode(0);
    root->left = newNode(1);
    root->left->left = newNode(2);
    root->left->left->left = newNode(3);
    root->left->left->right = newNode(4);
    root->left->right = newNode(5);
    root->right = newNode(6);
    root->right->left = newNode(7);
    root->right->left->right = newNode(8);
    root->right->left->left = newNode(9);
    root->right->right = newNode(10);
    root->right->right->right = newNode(11);
    return root;
}
struct node* fillTree2(struct node* root){
    root = newNode(11);
    root->left = newNode(4);
    root->left->left = newNode(5);
    root->left->left->left = newNode(7);
    root->left->left->right = newNode(1);
    root->left->right = newNode(3);
    root->left->right->left = newNode(6);
    root->right = newNode(2);
    root->right->right = newNode(8);
    root->right->left = newNode(9);
    root->right->left->left= newNode(0);
    root->right->left->right = newNode(10);
    return root;
}
int main(){
    struct node* tree1,*tree2;
    tree1 = fillTree1(tree1);
    tree2 = fillTree2(tree2);
    string serialCode1 = getSerialCodeString(tree1);
    string serialCode2 = getSerialCodeString(tree2);
    if(serialCode1 == serialCode2){
        cout<<"the trees are isomorphic...\n";
    }else{
        cout<<"the trees are not isomorphic...\n";       
    }
    return 0;
}