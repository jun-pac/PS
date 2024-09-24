
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
#define MOD 998244353
#define INF 1000000007 
__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

vc<int> edges[N];
ll mx=0, n;
vc<pii> mm;
int cnt=0;
ll in[N], out[N];

int DFS(int idx, int p){
    if(in[idx]!=-1){
        return in[idx];
    }
    in[idx]=cnt++;
    int mn_rec=in[idx];
    for(auto next : edges[idx]){
        if(next==p) continue;
        if(in[next]==-1){
            int temp=DFS(next,idx);
            if(in[next]>in[idx] && temp==in[next]){
                mx=max(mx,(out[next]-in[next])*(n-(out[next]-in[next])));
            }
            mn_rec=min(mn_rec,temp);
        }
        else{
            int temp=DFS(next,idx);
            mn_rec=min(mn_rec,temp);
        }
    }
    out[idx]=cnt;
    return mn_rec;
}

void Solve(){
    int m;
    cin>>n>>m;
    rng(i,0,n-1) edges[i].clear();
    rng(i,0,m-1){
        int a,b;
        cin>>a>>b;
        a--, b--;
        mm.pb({a,b});
        edges[a].pb(b);
        edges[b].pb(a);
    }
    fill(in,in+n,-1);
    fill(out,out+n,-1);
    cnt=0, mx=0;
    DFS(0,-1);
    cout<<(n*(n-1))/2-mx<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

