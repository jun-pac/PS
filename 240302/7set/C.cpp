
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

#define N 400030
#define MOD 998244353
#define INF 1000000007 
__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

vc<ll> datas[N];
ll cost[N];
vc<pll> edges[2*N];
ll min_dist[2*N];
pll temp[N];


void dijkstra(int s, int tot){
    priority_queue<pair<long long,long long>> pq;
    fill(min_dist,min_dist+tot,-1);
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


void Solve(){
    int n,m;
    cin>>n>>m;
    rng(i,0,n-1) datas[i].clear();
    rng(i,0,n+n*m-1) edges[i].clear();
    rng(i,0,n-1) cin>>cost[i];
    rng(i,0,n-1){
        ll val;
        rng(j,0,m-1){
            cin>>val;
            datas[i].pb(val);
        }
    }   
    int cnt=0;
    rng(j,0,m-1){
        rng(i,0,n-1) temp[i]={datas[i][j],i};
        sort(temp,temp+n);
        rng(i,0,n-1){
            edges[temp[i].se].pb({n+cnt,0});
            edges[n+cnt].pb({temp[i].se,cost[temp[i].se]});
            if(i!=n-1){
                edges[n+cnt].pb({n+cnt+1,0});
                edges[n+cnt+1].pb({n+cnt,temp[i+1].fi-temp[i].fi});
            }
            cnt++;
        }
    }
    dijkstra(0,n+n*m);
    cout<<min_dist[n-1]<<'\n';
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

