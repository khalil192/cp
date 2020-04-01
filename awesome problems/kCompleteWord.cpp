




/*
we are given a string s of length n  and an integer k 

now the string is complete 
1.  it's a palindrome and 
2. for every i (i>=0 && i<n ) s[i] = s[i+k]
both the conditions have to be satisfied...

you can convert one character with another character , that costs one move

You need to find minimum no of moves you would be needing to make the string complete
sample input : 
t testcases  , for each test case :  
1st line :  n , k 
2nd line : string of length n 

output : single integer x , required answer.


Example
input : 
4
6 2
abaaba
6 3
abaaba
36 9
hippopotomonstrosesquippedaliophobia
21 7
wudixiaoxingxingheclp

output: 
2
0
23
16

*/


#include<stdio.h>
#include<iostream>
#include<map>
#define MAXI 200005
using namespace std;


int par[MAXI] , sz[MAXI];
map<char , int> listOfEachFamily[MAXI];
void ini(int n , string &s) {
    for(int i = 0;i< n;i++){
        par[i] = i;
        sz[i] = 1;
        listOfEachFamily[i].clear();
        listOfEachFamily[i][s[i]]=1;
    }
}
int root(int i){
    while(par[i]!=i){
        par[i] = par[par[i]];
        i = par[i];
    }
    return i;
}
void join(int i, int j){
    i = root(i) , j = root(j);
    if(i == j){return;}
    if(sz[i]  > sz[j]){
        par[j] = i;
        sz[i] += sz[j];
        for(pair<char , int> p : listOfEachFamily[j]){
            listOfEachFamily[i][p.first] += p.second;
        }
    }else{
        par[i] = j;
        sz[j] += sz[i];
        for(pair<char , int> p : listOfEachFamily[i]){
            listOfEachFamily[j][p.first] += p.second;
        }
    }
}

void solve(){
    int n , k ;
    cin>>n>>k;
    string s;
    cin>>s;
    ini(n,s);
    for(int i = 0;i < n;i++){
        if(i+k < n){
        join(i , i+k);
        }
        join( i , n-i-1);
    }
    int cnt = 0;
    for(int i = 0;i<n;i++){
        if(par[i] !=i){continue;}
        int maxi = 0;
        for(pair<char,int> p : listOfEachFamily[i]){
            maxi = max(maxi , p.second);
        }
        cnt += (sz[i] - maxi);        
    }
    cout<<cnt<<endl;
}

int main(){
    int t ;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}