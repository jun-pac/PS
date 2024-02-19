
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

#define N 1030
#define MOD 998244353
#define INF 10000000000007 

vc<pll> edges[N]; // {next, len}
ll slow[N]; // slowness factor of bike i (which is from i th city)
ll min_time[N][N]; // min_time[i][j]는 i에 도달했고, 그때까지 slow[j]가 min인

void dijkstra(int s){
    priority_queue<pair<ll,pii>> pq; // {-time, {idx, mn_bicycle}}
	pq.push({0,{s,s}});
    while(!pq.empty()){
		ll tt=-pq.top().fi;
        ll idx=pq.top().se.fi;
        ll mnbi=pq.top().se.se;
		pq.pop();
		if(min_time[idx][mnbi]!=INF) continue;
		min_time[idx][mnbi]=tt;
		for(int i=0; i<edges[idx].size(); i++){
			ll next=edges[idx][i].fi;
            ll dist=edges[idx][i].se;
            ll newslow=(slow[next]<slow[mnbi]?next : mnbi);
			if(min_time[next][newslow]==INF) pq.push({-(tt+slow[mnbi]*dist),{next,newslow}});
		}
	}
}

void Solve(){
    int n,m,a,b,w;
    cin>>n>>m;
    rng(i,0,n-1) edges[i].clear();
    rng(i,0,m-1){
        cin>>a>>b>>w;
        a--, b--;
        edges[a].pb({b,w});
        edges[b].pb({a,w});
    }
    rng(i,0,n-1) cin>>slow[i];
    rng(i,0,n-1) fill(min_time[i], min_time[i]+n, INF);
    dijkstra(0);
    ll mn=INF;
    rng(j,0,n-1) mn=min(mn,min_time[n-1][j]);
    cout<<mn<<'\n';
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

