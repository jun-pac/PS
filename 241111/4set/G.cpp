
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
#define MOD2 1000000007
#define INF 1000000007 

vector<pll> edges[N]; // {idx, dist}
long long min_dist[N], mins[N], mint[N];
array<ll,3> es[N];
int n;
void dijkstra(int s){
    priority_queue<pair<long long,long long>> pq;
    fill(min_dist,min_dist+n,-1);
	pq.push({0,s});
    while(!pq.empty()){
		long long dist=-pq.top().first, idx=pq.top().second;
		pq.pop();
		if(min_dist[idx]!=-1) continue;
		min_dist[idx]=dist;
		for(int i=0; i<edges[idx].size(); i++){
			long long next=edges[idx][i].first, n_dist=dist+edges[idx][i].second;
			if(min_dist[next]==-1) pq.push({-n_dist,next});
		}
	}
}

vc<int> val_edges[N],val_redges[N];
int cand[N];
bool visited[N],visited2[N];
ll num[N], num2[N];
ll rnum[N], rnum2[N];

ll DFS(int idx){
    if(visited[idx]) return num[idx];
    visited[idx]=1;
    ll res=0;
    for(auto next: val_redges[idx]){
        res=(res+DFS(next))%MOD;
    }
    return num[idx]=res;
}
ll rDFS(int idx){
    if(visited[idx]) return rnum[idx];
    visited[idx]=1;
    ll res=0;
    for(auto next: val_edges[idx]){
        res=(res+rDFS(next))%MOD;
    }
    return rnum[idx]=res;
}


ll DFS2(int idx){
    if(visited2[idx]) return num2[idx];
    visited2[idx]=1;
    ll res=0;
    for(auto next: val_redges[idx]){
        res=(res+DFS2(next))%MOD2;
    }
    return num2[idx]=res;
}
ll rDFS2(int idx){
    if(visited2[idx]) return rnum2[idx];
    visited2[idx]=1;
    ll res=0;
    for(auto next: val_edges[idx]){
        res=(res+rDFS2(next))%MOD2;
    }
    return rnum2[idx]=res;
}

void Solve(){
    int m;
    cin>>n>>m;
    rng(i,0,m-1){
        ll u,v,c;
        cin>>u>>v>>c;
        u--, v--;
        es[i]={u,v,c};
        edges[u].pb({v,c});
        edges[v].pb({u,c});
    }
    dijkstra(0);
    rng(i,0,n-1) mins[i]=min_dist[i];
    dijkstra(n-1);
    rng(i,0,n-1) mint[i]=min_dist[i];
    
    ll dd=min_dist[0];

    rng(i,0,m-1){
        ll u=es[i][0],v=es[i][1],c=es[i][2];
        if(mins[u]+c+mint[v]==dd){
            cand[i]=1;
            val_edges[u].pb(v);
            val_redges[v].pb(u);
        }
        else if(mins[v]+c+mint[u]==dd){
            cand[i]=2;
            val_edges[v].pb(u);
            val_redges[u].pb(v);
        }
    }
    num[0]=1;
    fill(visited,visited+n,0);
    visited[0]=1;
    rng(i,0,n-1){
        if(!visited[i]) DFS(i);
    }
    rnum[n-1]=1;
    fill(visited,visited+n,0);
    visited[n-1]=1;
    rng(i,0,n-1){
        if(!visited[i]) rDFS(i);
    }

    num2[0]=1;
    fill(visited2,visited2+n,0);
    visited2[0]=1;
    rng(i,0,n-1){
        if(!visited2[i]) DFS2(i);
    }
    rnum2[n-1]=1;
    fill(visited2,visited2+n,0);
    visited2[n-1]=1;
    rng(i,0,n-1){
        if(!visited2[i]) rDFS2(i);
    }


    ll tar=(num[n-1]%MOD+MOD)%MOD;
    ll tar2=(num2[n-1]%MOD2+MOD2)%MOD2;
    rng(i,0,m-1){
        ll u=es[i][0],v=es[i][1],c=es[i][2];
        if(cand[i]==1){
            if(((num[u]*rnum[v])%MOD+MOD)%MOD==tar && ((num2[u]*rnum2[v])%MOD2+MOD2)%MOD2==tar2) cout<<"Yes\n";
            else cout<<"No\n";
        }
        else if(cand[i]==2){
            if(((rnum[u]*num[v])%MOD+MOD)%MOD==tar && ((rnum2[u]*num2[v])%MOD2+MOD2)%MOD2==tar2) cout<<"Yes\n";
            else cout<<"No\n";
        }
        else cout<<"No\n";
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

