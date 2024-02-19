
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

#define N 3030
#define MOD 998244353
#define INF 1000000007 

vc<int> edges[N];
vc<int> r_edges[N];
int dist[N];
bool visited[N];
vc<int> batch[N]; // i�� �Ÿ��� ������ batch

void r_DFS(int idx){
    visited[idx]=1;
    for(auto next : r_edges[idx]){
        if(!visited[next]) r_DFS(next);
    }
}

void r_BFS(int idx){
    queue<pii> q;
    q.push({idx,0});
    while(!q.empty()){
        pii cur = q.front();
        q.pop();
        if(visited[cur.fi]) continue;
        visited[cur.fi]=1;
        dist[cur.fi]=cur.se;
        for(auto next : r_edges[cur.fi]){
            if(!visited[next]) q.push({next,cur.se+1});
        }
    }
}

void Solve(){
    int n,m,a,b;
    cin>>n>>m;
    rng(i,0,n-1) edges[i].clear();
    rng(i,0,n-1) r_edges[i].clear();
    rng(i,0,m-1){
        cin>>a>>b;
        a--,b--;
        edges[a].pb(b);
        r_edges[b].pb(a);
    }
    fill(visited,visited+n,0);
    r_DFS(0);
    rng(i,0,n-1) if(!visited[i]){
        cout<<"INFINITE\n";
        return;
    }

    fill(visited,visited+n,0);
    fill(dist,dist+n,0);
    r_BFS(0);
    int mxd=0;
    rng(i,0,n-1) batch[i].clear();
    int res=0;
    rng(i,0,n-1){
        mxd=max(mxd,dist[i]);
        batch[dist[i]].pb(i);
        res+=dist[i]+1;
    }

    // rng(i,0,mxd){
    //     cout<<"dist "<<i<<':';
    //     rng(j,0,(int)batch[i].size()-1) cout<<batch[i][j]+1<<' ';
    //     cout<<'\n';
    // }
    cout<<"FINITE\n";
    cout<<res<<'\n';
    rng(i,0,mxd){
        gnr(j,mxd,i){
            rng(k,0,(int)batch[j].size()-1) cout<<batch[j][k]+1<<' ';
        }
    }
    cout<<'\n';

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

