
/*

this code is written for competitve programming purposes. so the code quality and readability is compromised for easy use and quick modifications

suffix array class with built-in functions of preparing suffix_array in O(nlogn) time
and lcp array with O(N) time
after construction of above arrays you can solve numerous string based problems

*/


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
#define lli int
#define ll long long int
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
#define ROH 100005
#define deb(x) cout<<(#x)<<" "<<x<<endl
using namespace std;
lli mod = 1e9 +7,test; 
lli max(lli a,lli b){return a>b?a:b;}
lli min(lli a,lli b){return a>b?b:a;}



class suffix_array_class{
    public : 

    vector<lli> prepare_lcp(vector<lli>& sa , string & s){
    lli n = s.length();
    vi pos(n) , lcp(n);
    fo(i,n){    pos[sa[i]] = i;}
    //pos[i] - > position in suffix array of ith suffix from start
    lli k = 0;
    fo(i,n-1){
        lli p = pos[i];
        lli j = sa[p-1];  // we took ith suffix and j = prev of ith suffix in sa
        while(s[i+k] == s[j+k]){k++;}
        lcp[p] = k;
        k = max(k-1, 0);
    }
    return lcp;
}


    void count_sort(vector<pair<pi , lli> >& ds ,string sort_num){
        lli n = ds.size();
        vi cnt(n);
        fo(i,n){
            lli x = ds[i].first.second;
            if(sort_num == "first"){
            x =  ds[i].first.first;
            }
            cnt[x]++;
        }
        vi pos(n);
        pos[0] = 0;
        FO(i,1,n){
            pos[i] = pos[i-1] + cnt[i-1];
        }
        vector<pair<pi , lli> > ds_new(n);
        fo(i,n){
            lli x = ds[i].first.second;
            if(sort_num == "first"){
            x =  ds[i].first.first;
            }     
            ds_new[pos[x]] = ds[i];
            pos[x]++; 
        }
        ds = ds_new;
    }

    void radix_sort(vector<pair<pi , lli> >& ds){
        count_sort(ds,"second");
        count_sort(ds,"first");
    }
    

    vi prepare_suffix_array(string& s){
        s += '$';
        lli n = s.size();
        vi rank(n);
        vector<pair< pi , lli > > ds(n);
        fo(i,n){
            ds[i] = (mp(mp(s[i] , s[i]) , i));
        }
        sort(ds.begin()  ,ds.end());
        lli idx = 0;
        fo(i,n){
            rank[ds[i].second] = idx;
            if(i+1< n && (ds[i+1].first.first != ds[i].first.first ||ds[i+1].first.second != ds[i].first.second )){
                idx++;
            }
        }
        lli k = 0;
        while((1<<k) <= n){
            lli offset = (1<<k);
            fo(i,n){
                ds[i] = mp(mp(rank[i] , rank[ (i+offset)%n ]),i);
            }
            radix_sort(ds);
            lli idx =  0;
            fo(i,n){
                rank[ds[i].second] = idx;
                if(i+1< n && (ds[i+1].first.first != ds[i].first.first ||ds[i+1].first.second != ds[i].first.second )){
                idx++;
                }    
            }
            k++;
        }
        vi sa(n);
        fo(i,n){
            sa[rank[i]] = i;
        }
        return sa;
    }

};






int main(){
    ULTRA_INSTINCT;
    string s;
    cin>>s;
    suffix_array_class sac = suffix_array_class();
    vi sa = sac.prepare_suffix_array(s);
    vi lcp = sac.prepare_lcp(sa , s);
    
    return 0;

}
