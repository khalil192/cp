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


/* 
fenwick trees are 1 based indexed array...
note that the original array should be 1 based indexed as well as the tree
*/
lli original_arr[ROH],Btree[ROH],n;

lli lsb(lli i){
    return i&-i;
}

void initialise(){
for(lli i=0;i<n;i++)    Btree[i] = original_arr[i];
for(lli i=1;i<=n;i++){
    lli j = i+lsb(i);
    if(j<=n)    Btree[j] += Btree[i];
}
}

lli prefix_query(lli i){
    lli sum = 0;
    while(i>0){
        sum += Btree[i];
        i -= lsb(i);
    }
    return sum;
}
lli range_query(lli i,lli j){ 
    return prefix_query(j) - prefix_query(i-1);
    }
void update(lli i,lli val){
     while(i<=n){
        Btree[i] += val;
        i+=lsb(i);
    }
}

int main(){

return 0;
}