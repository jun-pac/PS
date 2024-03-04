
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

const ll INF=1000700007000000000;

vc<pair<int,array<ll,4>>> r_edges[N]; // 애초에 이것만 필요
ll mx_time[N];

void dijkstra(int s, int n){
    priority_queue<pair<long long,long long>> pq;
    fill(mx_time,mx_time+n,-1);
	pq.push({INF,s});
    while(!pq.empty()){
		ll cur=pq.top().first;
        ll idx=pq.top().second;
		pq.pop();
		if(mx_time[idx]!=-1) continue;
		mx_time[idx]=cur;
		for(int i=0; i<r_edges[idx].size(); i++){
			long long next=r_edges[idx][i].first;
            ll l=r_edges[idx][i].se[0], d=r_edges[idx][i].se[1], k=r_edges[idx][i].se[2], c=r_edges[idx][i].se[3];
            if(mx_time[next]!=-1 || cur-c<l) continue;
            ll n_time;
            if(cur-c>=l+(k-1)*d) n_time=l+(k-1)*d;
            else n_time=(cur-c-l)/d*d+l;            
			pq.push({n_time,next});
		}
	}
}


void Solve(){
    int n, m;
    cin>>n>>m;
    rng(i,0,m-1){
        ll l,d,k,c,a,b;
        cin>>l>>d>>k>>c>>a>>b;
        a--, b--;
        r_edges[b].pb({a,{l,d,k,c}});
    }
    dijkstra(n-1,n);
    rng(i,0,n-2){
        if(mx_time[i]==-1) cout<<"Unreachable\n";
        else cout<<mx_time[i]<<'\n';
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

