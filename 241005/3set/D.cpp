
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
random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

vc<int> edges[N];
vc<int> del; // ¾ø¾îÁú
bool visited[N], dels[N];

int DFS(int idx, int p){
    visited[idx]=1;
    int res=0;
    for(int next : edges[idx]){
        if(next==p) continue;
        res+=DFS(next,idx);
    }
    if(res>0) res++;
    else if(dels[idx]) res++;
    return res;
}

void Solve(){
    int n,k;
    cin>>n>>k;
    rng(i,0,n-2){
        int a,b;
        cin>>a>>b;
        a--,b--;
        edges[a].pb(b);
        edges[b].pb(a);
    }
    rng(i,0,k-1){
        int x;
        cin>>x;
        x--;
        dels[x]=1;
        del.pb(x);
    }
    fill(visited,visited+n,0);
    cout<<DFS(del[0],-1)<<'\n';
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

