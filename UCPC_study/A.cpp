// 1260
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
__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

#define N 300030
#define MOD 998244353
#define INF 1000000007 

vector<int> edges[N];
bool visited[N];

void DFS(int idx){
    cout<<idx+1<<' ';
    visited[idx]=1;
    for(auto next : edges[idx]){
        if(!visited[next]) DFS(next);
    }
}

void Solve(){
    int n,m,v;
    cin>>n>>m>>v;
    v--;
    rng(i,0,m-1){
        int a,b;
        cin>>a>>b;
        a--, b--;
        edges[a].pb(b);
        edges[b].pb(a);
    }
    rng(i,0,n-1) sort(all(edges[i]));
    // DFS
    DFS(v);
    cout<<'\n';


    // BFS
    queue<int> q;
    fill(visited,visited+n,0);
    q.push(v);
    while(!q.empty()){
        int idx=q.front();
        q.pop();
        if(visited[idx]) continue;
        cout<<idx+1<<' ';
        visited[idx]=1;
        for(auto next : edges[idx]){
            if(!visited[next]){
                q.push(next);
            }
        }
    }
    cout<<'\n';
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

