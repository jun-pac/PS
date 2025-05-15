
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

int c[101][101];

pair<int, pii> order[101];
int parent[101];
int find_root(int idx){
    if(idx==parent[idx]) return idx;
    return parent[idx]=find_root(parent[idx]);
}

vector<pair<long long,long long>> edges[N]; // {idx, dist}
long long min_dist[100][100];

void dijkstra(int s){
    priority_queue<pair<long long,long long>> pq;
	pq.push({0,s});
    while(!pq.empty()){
		long long dist=-pq.top().first, idx=pq.top().second;
		pq.pop();
		if(min_dist[s][idx]!=-1) continue;
		min_dist[s][idx]=dist;
		for(int i=0; i<edges[idx].size(); i++){
			long long next=edges[idx][i].first, n_dist=dist+edges[idx][i].second;
			if(min_dist[s][next]==-1) pq.push({-n_dist,next});
		}
	}
}


void Solve(){
    int n,k;
    cin>>n>>k;
    rng(i,0,n-1){
        rng(j,0,n-1) cin>>c[i][j];
    }
    rng(i,0,n-1){
        rng(j,0,n-1) edges[i].pb({j,c[i][j]});
    }
    rng(i,0,n-1) fill(min_dist[i],min_dist[i]+n,-1);
    rng(i,0,n-1) dijkstra(i);

    rng(i,0,n-1) parent[i]=i;
    int q;
    cin>>q;
    rng(t,0,q-1){
        int a,b;
        cin>>a>>b;
        a--, b--;
        int cnt=0;
        rng(i,0,k-1){
            rng(j,i+1,k-1) order[cnt++]={c[i][j],{i,j}};
            order[cnt++]={c[i][a],{i,a}};
            order[cnt++]={c[i][b],{i,b}};
        }
        sort(order,order+cnt);
        ll sum=0;
        rng(num,0,cnt-1){
            int i=order[num].se.fi;
            int j=order[num].se.se;
            if(find_root(i)!=find_root(j)){
                parent[find_root(i)]=find_root(j);
                sum+=order[num].fi;
            }
        }
        cout<<sum<<'\n';

        rng(i,0,k-1) parent[i]=i;
        parent[a]=a;
        parent[b]=b;
    }
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

