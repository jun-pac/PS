
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

#define N 100030
#define MOD 998244353
ll INF=100000000007;

vc<pll> edges[N]; // next, dist // flight는 굳이 안 만든다.
ll ans[N];
ll min_dist[N];
ll DP[N];
bool visited[N];
// 문제는 flight edge가 너무 많다는 것.
// 우리가 k를 늘릴 때는 min_dist[k][i] = min_j{(i-j)^2 + min_dist[k-1][i]}인데? 여기서 또 propagation을 해야 하는 것 아닌가

void dijkstra(int n){
    priority_queue<pll> pq;
    rng(i,0,n-1) pq.push({-min_dist[i],i});
    fill(min_dist,min_dist+N,-1);
    while(!pq.empty()){
		ll dist=-pq.top().first, idx=pq.top().second;
		pq.pop();
		if(min_dist[idx]!=-1) continue;
		min_dist[idx]=dist;
		for(int i=0; i<edges[idx].size(); i++){
			ll next=edges[idx][i].first, n_dist=dist+edges[idx][i].second;
			if(min_dist[next]==-1) pq.push({-n_dist,next});
		}
	}
}



void CHT(ll n){
    stack<pll> st;
    st.push({0,INF});
    for(ll i=1; i<n; i++){
        while(!st.empty()){
            ll u=st.top().fi;
            st.pop();
            ll numer=(i*i-u*u+min_dist[i]-min_dist[u]);
            ll denom=(2*(i-u));
            ll r=(numer<0?-1:0)+numer/denom;
            if(!(!st.empty() && r<=st.top().se)){
                st.push({u,r});
                break;
            }
        }
        st.push({i,INF});
    }
    vc<pll> temp;
    while(!st.empty()){
        if(st.top().se>=0) temp.pb(st.top());
        st.pop();
    }
    reverse(all(temp));
    ll last=0;
    rng(i,0,(int)temp.size()-1){
        while(last<=min(n-1,temp[i].se)){
            //cout<<"update "<<last+1<<' '<<temp[i].fi<<'\n';
            DP[last]=min_dist[temp[i].fi]+(last-temp[i].fi)*(last-temp[i].fi);
            last++;
        }
        if(last==n) break;
    }
    rng(i,0,n-1) min_dist[i]=DP[i];
}

void Solve(){
    ll n,m,k,a,b,c;
    cin>>n>>m>>k;
    rng(i,0,m-1){
        cin>>a>>b>>c;
        a--, b--;
        edges[a].pb({b,c});
        edges[b].pb({a,c});
    }
    fill(min_dist,min_dist+n,INF);
    min_dist[0]=0;
    dijkstra(n);
    //cout<<"DIJ "; rng(i,0,n-1) cout<<min_dist[i]<<' '; cout<<'\n';
    rng(i,0,k-1){
        CHT(n);
        //cout<<"CHT "; rng(i,0,n-1) cout<<min_dist[i]<<' '; cout<<'\n';
        dijkstra(n);
        //cout<<"DIJ "; rng(i,0,n-1) cout<<min_dist[i]<<' '; cout<<'\n';
    }
    rng(i,0,n-1) cout<<min_dist[i]<<' '; cout<<'\n';
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

