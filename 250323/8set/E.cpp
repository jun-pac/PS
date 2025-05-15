
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
random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

vc<int> edges[N], r_edges[N]; // 200000
ll x;
long long min_dist[2][N];

void dijkstra(int s){
    priority_queue<pair<long long,pii>> pq;
    rng(i,0,1) fill(min_dist[i],min_dist[i]+N,-1);

	pq.push({0,{0,s}});
    while(!pq.empty()){
		long long dist=-pq.top().fi;
        int dir=pq.top().se.fi, idx=pq.top().se.se;
		pq.pop();
		if(min_dist[dir][idx]!=-1) continue;
		min_dist[dir][idx]=dist;
        if(dir==0){
            for(int i=0; i<edges[idx].size(); i++){
                long long next=edges[idx][i], n_dist=dist+1;
                if(min_dist[0][next]==-1) pq.push({-n_dist,{0,next}});
            }    
            for(int i=0; i<r_edges[idx].size(); i++){
                long long next=r_edges[idx][i], n_dist=dist+x+1;
                if(min_dist[1][next]==-1) pq.push({-n_dist,{1,next}});
            }   
            if(min_dist[1][idx]==-1) pq.push({-(dist+x),{1,idx}});
        }
        else{
            for(int i=0; i<r_edges[idx].size(); i++){
                long long next=r_edges[idx][i], n_dist=dist+1;
                if(min_dist[1][next]==-1) pq.push({-n_dist,{1,next}});
            }    
            for(int i=0; i<edges[idx].size(); i++){
                long long next=edges[idx][i], n_dist=dist+x+1;
                if(min_dist[0][next]==-1) pq.push({-n_dist,{0,next}});
            }   
            if(min_dist[0][idx]==-1) pq.push({-(dist+x),{0,idx}});
        }
	}
}


void Solve(){
    int n,m;
    cin>>n>>m>>x;
    rng(i,0,m-1){
        int a,b;
        cin>>a>>b;
        a--, b--;
        edges[a].pb(b);
        r_edges[b].pb(a);
    }
    dijkstra(0);
    cout<<min(min_dist[0][n-1],min_dist[1][n-1])<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

