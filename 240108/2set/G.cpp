
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

#define N 1400
#define MOD 998244353
#define INF 1000000007 

int to_idx(string s){
    int n=s.size();
    int res=0;
    rng(i,0,n-1){
        if(s[n-1-i]=='1') res+=(1<<i);
    }
    return res;
}

string s;
string ps[N], ns[N]; // °¢°¢ positive, neg.
int ds[N];
vector<pii> edges[N]; // {idx, dist}
int min_dist[N];
int n; 

void dijkstra(int s){
    priority_queue<pii> pq;
    fill(min_dist,min_dist+(1<<n),-1);
	pq.push({0,s});
    while(!pq.empty()){
		int dist=-pq.top().first, idx=pq.top().second;
		pq.pop();
		if(min_dist[idx]!=-1) continue;
		min_dist[idx]=dist;
		for(int i=0; i<edges[idx].size(); i++){
			int next=edges[idx][i].first, n_dist=dist+edges[idx][i].second;
			if(min_dist[next]==-1) pq.push({-n_dist,next});
		}
	}
}

void Solve(){
    int m;
    cin>>n>>m;
    cin>>s;
    rng(i,0,m-1){
        cin>>ds[i];
        cin>>ps[i];
        cin>>ns[i];
        //cout<<ds[i]<<' '<<ps[i]<<' '<<ns[i]<<'\n';
    }
    rng(i,0,(1<<n)-1) edges[i].clear(); 
    rng(i,0,(1<<n)-1){
        rng(j,0,m-1){
            int tar=i;
            rng(k,0,n-1){
                if(ps[j][n-1-k]=='1' && (tar&(1<<k))) tar-=(1<<k);
            }
            rng(k,0,n-1){
                if(ns[j][n-1-k]=='1' && !(tar&(1<<k))) tar+=(1<<k);
            }
            edges[i].pb({tar,ds[j]});
        }
    }
    dijkstra(to_idx(s));
    // cout<<"init : "<<to_idx(s)<<'\n';
    cout<<min_dist[0]<<'\n';
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

