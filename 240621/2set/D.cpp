
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
int col[N]; //[w,r,b]
int depth[N], pred[N];

int DFS(int idx, int p, int d){
    depth[idx]=d;
    pred[idx]=p;
    for(int next : edges[idx]){
        if(next==p) continue;
        DFS(next,idx,d+1);
    }
}

void Solve(){
    int n,a,b;
    cin>>n>>a>>b;
    a--, b--;
    rng(i,0,n-1) edges[i].clear();
    fill(col,col+n,0);
    rng(i,0,n-2){
        int x,y;
        cin>>x>>y;
        x--, y--;
        edges[x].pb(y);
        edges[y].pb(x);
    }
    col[a]++;
    if(col[b]==1) col[b]++; // always this way.
    // 2*(n-1) - max_depth만큼 a가 방문하는데 시간이 필요. b는 
    DFS(a,-1,0);
    int mx=0;
    rng(i,0,n-1) mx=max(mx,depth[i]);
    if(a==b){
        cout<<2*(n-1)-mx<<'\n';
        return;
    }
    int disty=depth[b];
    rng(i,0,((disty+1)/2)-1) b=pred[b];
    //cout<<"b"<<b+1<<'\n';
    DFS(b,-1,0);
    mx=0;
    rng(i,0,n-1) mx=max(mx,depth[i]);
    //cout<<"mx "<<mx<<'\n';
    int res=(disty+1)/2+2*(n-1)-mx;
    cout<<res<<'\n';
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

