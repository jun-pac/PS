
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
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

#define N 200030
#define MOD 998244353
#define INF 1000000007 

ll datas[N];
vc<int> edges[N];
vector<int> r_edges[N];
int scc[N];
int order[N];
vc<int> sccs[N];
pll DP[N];
int cnt, scc_cnt; // Number of SCC's
int n; // Number of actual nodes in graph

bool visited[N];

pll topo_sort(int sccidx){
    if(visited[sccidx]) return DP[sccidx];
    visited[sccidx]=1;
    //cout<<"dsfs "<<sccs[sccidx].size()<<'\n';
    pll cur={sccs[sccidx].size(),0}; // 개수, 값
    for(auto idx : sccs[sccidx]){
        cur.se+=datas[idx];
    }

    pll mx={-INF,0}; 
    for(auto idx : sccs[sccidx]){
        for(auto next : r_edges[idx]){
            if(scc[next]!=scc[idx]){
                auto temp=topo_sort(scc[next]);
                if(temp.fi>mx.fi) mx=temp;
                else if(temp.fi==mx.fi && temp.se<mx.se) mx=temp;
            }
        }
    }
    if(mx.fi<0) return DP[sccidx]=cur;
    cur.fi+=mx.fi;
    cur.se+=mx.se;
    return DP[sccidx]=cur;
}

pll get_topo_order(){ // int n
    fill(visited,visited+n,0);
    cnt=0;
    pll mx={-INF,0}; // mx len
    for(int i=0; i<n; i++) if(!visited[scc[i]]){
        auto temp=topo_sort(scc[i]); 
        if(temp.fi>mx.fi) mx=temp;
        else if(temp.fi==mx.fi && temp.se<mx.se) mx=temp;  
    }
    return mx;
}

void DFS(int idx){
    visited[idx]=true;
    for(int i=0; i<edges[idx].size(); i++) if(!visited[edges[idx][i]]) DFS(edges[idx][i]);
    order[cnt]=idx; cnt++;
}

void r_DFS(int idx){
    visited[idx]=true;
    scc[idx]=cnt;
    for(int i=0; i<r_edges[idx].size(); i++) if(!visited[r_edges[idx][i]]) r_DFS(r_edges[idx][i]);
}

// Kosaraju's algorithm. Set n, edges, r_edges before call this function.
void get_scc(){
    fill(visited, visited+n, false), cnt=0;
    for(int i=0; i<n; i++) if(!visited[i]) DFS(i);
    fill(visited, visited+n, false), cnt=0;
    for(int i=n-1; i>=0; i--) if(!visited[order[i]]) {r_DFS(order[i]); cnt++;}
    scc_cnt=cnt;
}



void Solve(){
    int m,a,b;
    cin>>n>>m;
    rep(i,n) cin>>datas[i];
    rep(i,n) edges[i].clear();
    rep(i,n) r_edges[i].clear();
    rng(i,0,m-1){
        cin>>a>>b;
        a--, b--;
        edges[a].pb(b);
        r_edges[b].pb(a);
    }
    get_scc(); // scc[idx]가 채워짐


    rng(i,0,scc_cnt-1) sccs[i].clear();
    rng(i,0,n-1) sccs[scc[i]].pb(i);
    // rng(i,0,scc_cnt-1){
    //     for(auto j : sccs[i]) cout<<j<<' ';
    //     cout<<endl;
    // } 
    auto mx=get_topo_order();
    cout<<(mx.fi<0?0:mx.fi)<<' '<<mx.se<<'\n';
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

