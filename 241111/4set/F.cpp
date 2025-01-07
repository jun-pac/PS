
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
const ll INF=1000000000000007;

vc<pll> edges[303];
array<ll,3> es[90000];
bool blocked[90000];
ll min_dist[303][303];
bool dij_done[303];
ll n,m;
bool inQ[303][303];
ll conn[303][303];

void floyd_warshall(){
    rng(i,0,n-1) fill(min_dist[i],min_dist[i]+n,INF);
    rng(i,0,n-1){
        min_dist[i][i]=0;
    }
    rng(i,0,n-1){
        for(auto temp: edges[i]){
            int next=temp.fi;
            ll d=temp.se;
            min_dist[i][next]=d;
        }
    }
    // Main itertion
    rng(k,0,n-1){ // After k-th step, min_dist[][] considers all of the minimun path which is not contain x(>k) th node, excluding start and end points
        rng(i,0,n-1){
            rng(j,0,n-1) min_dist[i][j]=min(min_dist[i][j],min_dist[i][k]+min_dist[k][j]);
        }
    }
}

void Solve(){
    ll q;
    cin>>n>>m>>q;
    rng(i,0,n-1) edges[i].clear();
    rng(i,0,n-1) edges[i].reserve(n);
    
    rng(i,0,m-1){
        ll u,v,c;
        cin>>u>>v>>c;
        u--, v--;
        es[i]={u,v,c};
        edges[u].pb({v,c});
        edges[v].pb({u,c});
        conn[u][v]=c;
        conn[v][u]=c;
    }
    fill(blocked,blocked+m,0);
    floyd_warshall();

    rng(i,0,q-1){
        int a;
        cin>>a;
        if(a==1){
            int b;
            cin>>b;
            b--;
            blocked[b]=1;
            array<ll,3> dele=es[b];
            conn[dele[0]][dele[1]]=0;
            conn[dele[1]][dele[0]]=0;
            edges[dele[0]].clear();
            edges[dele[1]].clear();
            rng(j,0,n-1){
                if(conn[dele[0]][j]!=0){
                    edges[dele[0]].pb({j,conn[dele[0]][j]});
                }
            }
            rng(j,0,n-1){
                if(conn[dele[1]][j]!=0){
                    edges[dele[1]].pb({j,conn[dele[1]][j]});
                }
            }
            floyd_warshall();
        }
        else{
            int b,c;
            cin>>b>>c;
            b--, c--;
            cout<<(min_dist[b][c]==INF?-1:min_dist[b][c])<<'\n';
        }
    }

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

