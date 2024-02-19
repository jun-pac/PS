
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define rep(i,b) rng(i,0,b-1)  
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
#define per(i,b) gnr(i,b-1,0)
#define pb push_back
#define eb emplace_back
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define si(x) int(x.size())
template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;
typedef long long ll;
using pii=pair<int,int>;
using vi=vc<int>;
using uint=unsigned;
using ull=unsigned long long;
using pil=pair<int,ll>;
using pli=pair<ll,int>;
using pll=pair<ll,ll>;
using t3=tuple<int,int,int>;

#define N 300030
#define INF 1000000007 

pii qs[100];
vc<int> edges[100];

int chromatic_number(int n){ // n is # of vertices of the graph
    // Minimum number of colors require to satisty "Graph Coloring Problem"
    assert(n<20); // O(3^N) algorithm
    int DP[(1<<n)];
    DP[0]=1; // Convinient in DP process 
    for(int k=0; k<n; k++){
        for(int j=0; j<(1<<k); j++){
            int num=(1<<k)+j, res=INF; // num indicates current subset
            bool indep=0;
            if(DP[j]==1){ // Check independence
                indep=1;
                for(auto next : edges[k]){
                    if(j&(1<<next)){
                        indep=0;
                        break;
                    }
                }
            }
            if(indep) res=1;
            else{
                for(int t=num; t>0; t=(t-1)&num){
                    // t swaps all the subsets of num
                    if(num==t) continue;
                    res=min(res, DP[t]+DP[num-t]);   
                }
            }
            DP[num]=res;
        }
    }
    return DP[(1<<n)-1];
}

void Solve(){
    ll p,b,n,m; // n+1개의 점이 있는 셈
    cin>>p>>b>>n>>m; // Buck는 단 한순간도 중요하지 않다.
    rng(i,0,m-1){
        int l,r;
        cin>>l>>r;
        l--, r--;
        edges[l].pb(r+1);
        edges[r+1].pb(l);
    }
    int num=chromatic_number(n+1);
    cout<<(num<=p?"Yes\n":"No\n");
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

