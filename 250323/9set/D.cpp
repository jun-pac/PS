
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
// random_device rd; 
// mt19937 gen(rd());
// uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

vc<pll> edges[100];
ll mx;
ll n;

void DFS(int idx, ll visited, ll cur){
    visited=(visited|(1<<idx));
    // cout<<"vi cur "<<idx<<' '<<visited<<' '<<cur<<' '<<n<<'\n';
    if(visited&(1<<(n-1))){
        mx=min(mx,cur);
        return;
    }
    for(auto temp: edges[idx]){
        int next=temp.fi;
        ll w=temp.se;
        // cout<<"ed "<<idx<<' '<<next<<' '<<w<<'\n';
        if(!(visited&(1<<next))){
            DFS(next,visited|(1<<next),cur^w);
        }
    }
}

void Solve(){
    int m;
    cin>>n>>m;
    rng(i,0,m-1){
        ll a,b,w;
        cin>>a>>b>>w;
        a--, b--;
        edges[a].pb({b,w});
        edges[b].pb({a,w});
    }
    mx=(1LL<<61);
    DFS(0,0,0);
    cout<<mx<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

