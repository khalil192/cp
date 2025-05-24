#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
 
// finding the nth parent of a node in a tree using binary lifting
// space - complexity O(NlogN) , time - O(NlogN + q*logN) -> q = no of queries
// first store all 2_powers parents of each node... 
// for n nodes .. logN parents for each node -> hence space  = O(NlogN)
 
class nTree{
    public:
    static const int MAX = (int)3e5 + 5;
    static const int LOGN = 25;
    vector<vector<int> > g;
    vector<vector<int> > parent;
    vector<int> dep;
    int n;
    nTree(int num){
        n = num;
        g.resize(n);
        dep.resize(n,0);
        parent.resize(n , vector<int>(LOGN,-1));
    }
    void addEdge(int i,int j){
        --i, --j;
        g[i].push_back(j);
        g[j].push_back(i);
    }
    void preprocess(){
        dfs(0,-1 , 0);
    }
    void dfs(int node, int par,int depth){
        parent[node][0] = par; // 2ˆ0 th parent
        dep[node] = depth;
        int last = par;
        for(int i = 1;i<LOGN;i++){
            if(parent[node][i-1] == -1){
                break;
            }
            parent[node][i] = parent[parent[node][i-1]][i-1];
        }
        for(int to : g[node]){
            if(to != par){
            dfs(to , node,depth+1);
            }
        }
    }
    int lca(int i,int j){
        --i,--j;
        if(dep[i] > dep[j]){swap(i,j);}
        int d = dep[j] - dep[i];
        for (int k = LOGN - 1; k >= 0; --k) {
            if ((d >> k) & 1) { 
                j = parent[j][k];
            }
        }

        if(i==j){return i;}
        for(int k = LOGN-1;k>=0;k--){
            if(parent[i][k] != -1 && parent[i][k] != parent[j][k] ){
                i = parent[i][k];
                j = parent[j][k];
            }
        }
        return parent[i][0];
    }
};
 
 
int n;
 
void solve(){
    int l,r,q;
    cin>>n>>q;
    nTree tree(n);
    for(int i = 1;i<n;i++){
        cin>>l;
        tree.addEdge(i+1,l);
    }
    tree.preprocess();
    while(q--){
        cin>>l>>r;
        int ans = tree.lca(l,r);
        cout<<ans+1<<endl;
    }
 
}
 
int main(){
    solve();
    return 0;
}
