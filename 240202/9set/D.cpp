
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
#define INF 10000000000000007 
#define MX 200000000000007

vc<array<ll,3>> edges[N]; // [a] -> {a,c,r}; 
vc<pll> posnode; // {nodeidx, cost}만 저장
int n;
ll mx_left[N]; 

void dijkstra(int s, ll init){
    priority_queue<pll> pq;
    fill(mx_left,mx_left+n,-1); // cost가 최소가 되는 경로를 따라왔을 때 최단경로일 필요가 없다.
	pq.push({init,s});
    while(!pq.empty()){
		ll left=pq.top().fi, idx=pq.top().se;
		pq.pop();
		if(mx_left[idx]!=-1) continue;
        //cout<<"visit "<<idx<<' '<<left<<'\n';
		mx_left[idx]=left;
		for(int i=0; i<edges[idx].size(); i++){
            if(left<edges[idx][i][1]) continue;
			ll next=edges[idx][i][0], n_left=left-edges[idx][i][1]+edges[idx][i][2];
            //assert(n_left>=0);
			if(mx_left[next]==-1) pq.push({n_left,next});
		}
	}
}



void Solve(){
    ll m,a,b,c,rew;
    cin>>n>>m;
    bool lastflag=0;
    rng(i,0,m-1){
        cin>>a>>b>>c>>rew;
        a--, b--;
        if(rew>c){
            posnode.pb({a,c});
            posnode.pb({b,c}); 
        }
        else{
            edges[a].pb({b,c,rew});
            edges[b].pb({a,c,rew});
        }
    }
    // dijkstra
    ll l=0, r=MX;
    while(l<r){
        ll mid=(l+r)/2;
        dijkstra(0,mid);
        bool flag=0;
        if(mx_left[n-1]!=-1) flag=1;
        //if(flag) cout<<"test "<<mid<<" mx_left[n-1]!=-1\n";
        if(!flag){
            rng(i,0,(int)posnode.size()-1){
                if(mx_left[posnode[i].fi]>=posnode[i].se){
                    flag=1;
                    //cout<<"test "<<mid<<" posnode "<<posnode[i].fi<<' '<<mx_left[posnode[i].fi]<<' '<<posnode[i].se<<"\n";
                    break;
                }
            } 
        }
        if(flag) r=mid;
        else l=mid+1;
    } 
    cout<<l<<'\n';
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

