
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
#define INF 1000000000000007 
random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

vc<pll> edges[N]; // idx, weight
bool ish[N];
long long min_dist[N], amin[N], bmin[N];

void dijkstra(int s, int nn){
    priority_queue<pair<long long,long long>> pq;
    fill(min_dist,min_dist+nn,-1);
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
    int n,m,h;
    cin>>n>>m>>h;
    rng(i,0,2*n-1) edges[i].clear();
    fill(ish,ish+n,0);
    rng(i,0,h-1){
        int x;
        cin>>x;
        ish[x-1]=1;
    }
    rng(i,0,m-1){
        int a,b,w;
        cin>>a>>b>>w;
        a--, b--;
        edges[a].pb({b,w});
        edges[b].pb({a,w});
        edges[a+n].pb({b+n,w/2});
        edges[b+n].pb({a+n,w/2});
    }
    rng(i,0,n-1) if(ish[i]) edges[i].pb({i+n,0});

    dijkstra(0, 2*n);
    rng(i,0,2*n-1) amin[i]=min_dist[i];
    dijkstra(n-1, 2*n);
    rng(i,0,2*n-1) bmin[i]=min_dist[i];


    
    ll mn=INF;
    rng(i,0,2*n-1){
        if(amin[i]==-1) amin[i]=INF;
        if(bmin[i]==-1) bmin[i]=INF;
    }
    // rng(i,0,n-1) cout<<min(amin[i],amin[i+n])<<' ';
    // cout<<"\n";
    rng(i,0,n-1){
        mn=min(mn,max(min(amin[i],amin[i+n]),min(bmin[i],bmin[i+n])));
    }
    
    cout<<(mn==INF?-1:mn)<<'\n';
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

