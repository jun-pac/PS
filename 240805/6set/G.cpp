
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
//__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

#define N 600030
#define MOD 998244353
#define INF 100000000007 

vc<pii> edges[N]; // {b,c}
array<ll,3> es[N]; // {u->v,cost} // 똑같은 u,v를 연결하는데 더 작은 cost가 있을 수 있음.
map<pll,ll> inv_es; // {u,v}를 넣으면 es의 idx를 리턴하는 // 똑같은 {u,v}가 있으면 더 작은 cost만 살림
ll mn=INF;
ll dist[N]; // 들어온 edges를 기준으로, 당연히 edge idx임 // 이건 심지어 양방향을 따로 잡아야 함.
set<array<ll,3>> forbid;
int m;

void dijkstra(int v, int w){
    priority_queue<pll> pq; // {-cost, eidx}
    // v의 경우 v로 통하는 모든 edge를 다 넣어주는거지
    //dist[v]=0;
    if(w==v) mn=0;
    for(auto next : edges[v]){
        pq.push({-next.se,inv_es[{v,next.fi}]});
    }
    while(!pq.empty()){
        ll eidx=pq.top().se;
        ll d=-pq.top().fi;
        pq.pop();
        if(dist[eidx]!=INF) continue;
        dist[eidx]=d;
        ll a=es[eidx][0], b=es[eidx][1]; // 지금 현재위치는 b이고, a라는 점에서 들어온 것.
        if(b==w) mn=min(mn,d);
        for(auto next : edges[b]){
            ll nv=next.fi;
            ll cost=next.se;
            if(forbid.find({a,b,nv})!=forbid.end()) continue;
            int neidx=inv_es[{b,nv}];
            if(dist[neidx]==INF) pq.push({-(d+cost),neidx});
        }
    }
}

void Solve(){
    int n,k;
    cin>>m>>n>>k;
    int v,w; // start dest
    cin>>v>>w; // 0-based
    rng(i,0,m-1){
        int a,b,c;
        cin>>a>>b>>c;
        edges[a].pb({b,c});
        es[i+1]={a,b,c};
        if(inv_es[{a,b}]==0) inv_es[{a,b}]=i+1;
        else if(c<es[inv_es[{a,b}]][2]) inv_es[{a,b}]=i+1;
    }    
    rng(i,0,k-1){
        int a,b,c;
        cin>>a>>b>>c;
        forbid.insert({a,b,c});
    }
    fill(dist,dist+m+2,INF);
    mn=INF;
    dijkstra(v,w);
    cout<<(mn==INF?-1:mn)<<'\n';
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

