/*
USEFUL comments along with sample usage are yet to be added......
fenwick trees use case : 
benifits ..........
*/

#include<iostream>
#include<string.h>
#include<vector>
#include<math.h>
#include<queue>
#include<stack>
#include<algorithm>
#include<iterator>
#include<map>
#include <sstream>
#include<set>
#define lli long long int
#define mp make_pair
#define ULTRA_INSTINCT ios_base::sync_with_stdio(false); cin.tie(0)
#define fo(i,n) for(lli i=0;i<(n);i++)
#define FO(i,x,n) for(lli i=(x);i<(n);i++)
#define pb push_back
#define vi vector<lli>
#define pi pair<lli,lli>
#define vii vector<pi >
#define Endl "\n"
#define ITA 200005
#define ROH 200003
#define MAXI 200003
using namespace std;
lli mod = 1e9+7 ;
lli gcd(lli a, lli b){
    if (b == 0) return a;
    return gcd(b, a % b); 
}
/* 
fenwick trees are 1 based indexed array...
note that the original array should be 1 based indexed as well as the tree

*/
class bitree{
    public :
    vi tree; 
    lli n;
    bitree(vi vec){ // pass a one based array
        n = vec.size()-1; // why -1 ? 
        tree = vec;
        initialise();
    }
    bitree(lli num){
        n = num;
        tree.resize(n+1,0); // look at this
    }
    void initialise(){
        FO(i,1,n+1){
            int j = i+lsb(i);
            if(j<=n){
                tree[j] += tree[i];
            }
        }
    }
    lli lsb(lli i){ return i&-i;    }

    lli prefix_query(lli i){
        lli sum = 0;
        while(i>0){
            sum += tree[i];
            i -= lsb(i);
        }
        return sum;
    }
    lli range_query(lli i,lli j){ 
        return prefix_query(j) - prefix_query(i-1);
    }
    void update(int i,int val){
        while(i<=n){
            tree[i] += val;
            i+=lsb(i);
        }
    }

};


int main(){

return 0;
}