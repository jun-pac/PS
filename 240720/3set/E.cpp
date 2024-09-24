
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
//__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

#define N 300030
#define MOD 998244353
#define INF 1000000007 

vc<pll> edges[N];
ll dist[N];
void DFS(int idx, int p, ll d){
    dist[idx]=d;
    for(auto next : edges[idx]){
        if(next.fi==p) continue;
        DFS(next.fi,idx,d+next.se);
    }
}

void Solve(){
    int n;
    cin>>n;
    ll sum=0;
    rng(i,0,n-2){
        ll a,b,c;
        cin>>a>>b>>c;
        a--, b--;
        edges[a].pb({b,c});
        edges[b].pb({a,c});
        sum+=c;
    }
    int st=-1;
    rng(i,0,n-1) if(edges[i].size()==1){
        st=i;
        break;
    }
    st=0;
    DFS(st,-1,0);
    int mxidx=0;
    rng(i,0,n-1){
        if(dist[i]>dist[mxidx]) mxidx=i;
    }
    DFS(mxidx,-1,0);
    int mxmxidx=0;
    rng(i,0,n-1){
        if(dist[i]>dist[mxmxidx]) mxmxidx=i;
    }
    cout<<sum*2-dist[mxmxidx]<<'\n';
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

