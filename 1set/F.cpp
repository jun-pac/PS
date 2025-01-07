
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

vc<int> f_edges[N];
int fcnt[N];
ll DP[3000][3000];

vector<int> edges[N]; 
vector<int> r_edges[N];

int scc[N];
int order[N];
bool visited[N];
int cnt, scc_cnt; // Number of SCC's
ll n,m; // Number of actual nodes in graph


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

ll DP_DFS(int idx){ // scc_idx, f_edges¸¸ »ç¿ë
    for(auto next : f_edges[idx]){
        DP_DFS(next);
    }
    ll last=0;
    rng(i,0,m-1){
        ll temp=1;
        for(auto next : f_edges[idx]){
            temp=temp*DP[next][i]%MOD;
        }   
        last=(last+temp)%MOD;
        DP[idx][i]=last;
    }
    return DP[idx][m-1];
}

void Solve(){
    cin>>n>>m;
    rng(i,0,n-1){
        int p;
        cin>>p;
        r_edges[p-1].pb(i);
        edges[i].pb(p-1);
    }
    scc_cnt=0;
    get_scc();
    // rng(i,0,n-1) cout<<scc[i]<<'\n';

    rng(i,0,n-1){
        for(auto j : r_edges[i]){
            if(scc[i]==scc[j]) continue;
            f_edges[scc[i]].pb(scc[j]);
            // cout<<"fe : "<<scc[i]<<' '<<scc[j]<<'\n';
            fcnt[scc[j]]++;
        }
    }
    fill(visited,visited+scc_cnt,0);
    ll res=1;
    rng(i,0,scc_cnt-1) if(fcnt[i]==0){
        res=(res*DP_DFS(i))%MOD;
        // cout<<"DP : "<<DP_DFS(i)<<'\n';
    }
    cout<<(res+MOD)%MOD<<'\n';
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
