
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

#define N 1000030
#define MOD 998244353
#define INF 1000000000000007 


vc<int> edgea[1001], edgeb[1001];
pii esa[1001], esb[1001];
int visited[N];
// 그냥 {va, vb} dijkstra인듯
long long min_dist[N];
int n, ma, mb;

void dijkstra(pii s){
    priority_queue<pair<long long,pii>> pq;
    fill(min_dist,min_dist+n*n,INF);
	pq.push({0,s});
    while(!pq.empty()){
		long long dist=-pq.top().first;
        pii temp=pq.top().second;
        int a=temp.fi, b=temp.se;
        int idx=a*n+b;
		pq.pop();
		if(min_dist[idx]!=INF) continue;
        // cout<<"debug "<<a+1<<' '<<b+1<<' '<<dist<<'\n';
		min_dist[idx]=dist;
		for(int i=0; i<edgea[a].size(); i++){
            for(int j=0; j<edgeb[b].size(); j++){
                pii next={edgea[a][i], edgeb[b][j]};
                long long n_dist=dist+abs(next.fi-next.se);
			    if(min_dist[next.fi*n+next.se]==INF) pq.push({-n_dist,next}); 
            }
		}
	}
}

void Solve(){
    int s1, s2;
    cin>>n>>s1>>s2;
    s1--, s2--;
    rng(i,0,n-1) edgea[i].clear();
    rng(i,0,n-1) edgeb[i].clear();
    cin>>ma;
    rng(i,0,ma-1){
        int u,v;
        cin>>u>>v;
        u--, v--;
        edgea[u].pb(v);
        edgea[v].pb(u);
    }
    cin>>mb;
    rng(i,0,mb-1){
        int u,v;
        cin>>u>>v;
        u--, v--;
        edgeb[u].pb(v);
        edgeb[v].pb(u);
    }

    dijkstra({s1, s2});
    ll mn=INF;
    rng(a,0,n-1){
        for(int i=0; i<edgea[a].size(); i++){
            for(int j=0; j<edgeb[a].size(); j++){
                if(edgea[a][i]==edgeb[a][j]){
                    // cout<<"what "<<a+1<<' '<<edgea[a][i]+1<<' '<<dist[a*n+a]<<' '<<dist[edgea[a][i]*n+edgea[a][i]]<<'\n';
                    mn=min(mn,min_dist[a*n+a]);
                }
            }
        }
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

