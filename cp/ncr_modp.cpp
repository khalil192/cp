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

lli power(lli x, lli y, lli p){ 
    lli pro = 1;
    x = x % p;    
    while (y > 0){ 
        if (y & 1) 
            pro= (pro*x) % p; 
        y = y>>1; 
        x = (x*x) % p; 
    } 
    return pro; 
} 
  
lli mod_inverse(lli n, lli p){ 
    return power(n, p-2, p); 
} 
lli fact[10000];
lli nCrModPFermat(lli n, lli r, lli p){ 
   if (r==0) 
      return 1;   
    return (fact[n]* mod_inverse(fact[r], p) % p * 
            mod_inverse(fact[n-r], p) % p) % p; 
} 
int main(){
    fact[0] = 1;
    for(int i=1;i<1000;i++){
        fact[i] = (fact[i-1]*i )%mod;
    }
    cout<<nCrModPFermat(231,23,mod);
    return 0;
}