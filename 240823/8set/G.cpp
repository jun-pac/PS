
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
#define INF 1000000000000007 

vc<pair<ll,pll>> edges[N]; // {prev, {bus_time, walk_time}} // walk>bus guaranteed
ll dist[N];

void Solve(){   
    int n,m;
    cin>>n>>m;
    ll t1, t2, t_f; // [call start, call end] t_final
    cin>>t_f>>t1>>t2;
    t1=t_f-t1;
    t2=t_f-t2;
    swap(t1,t2);

    rng(i,0,n-1) edges[i].clear();
    rng(i,0,m-1){
        ll u,v,c1,c2;
        cin>>u>>v>>c1>>c2;
        u--, v--;
        edges[u].pb({v,{c1,c2}});
        edges[v].pb({u,{c1,c2}});
    }
    int s=n-1, t=0; // 역방향으로 해석해도 아무런 문제가 없음
    // Greedy함은 언제나 성립하는거죠. 그래도 늦게라도 있는 게 낫다
    //cout<<t1<<' '<<t2<<' '<<t_f<<'\n';
    fill(dist,dist+n,INF);
    priority_queue<pll> pq; // -dist, idx
    pq.push({0,s});
    while(!pq.empty()){
        auto temp=pq.top();
        pq.pop();
        int idx=temp.se;
        ll d=-temp.fi;
        if(dist[idx]!=INF) continue;
        dist[idx]=d;
        //cout<<"min dist "<<idx+1<<' '<<d<<'\n';
        if(dist[idx]>t_f) break; 
        
        for(auto aaa : edges[idx]){
            int next=aaa.fi;
            ll nd=d+aaa.se.fi;
            if(dist[next]!=INF) continue;
            if(d>=t2 || nd<=t1) pq.push({-nd,next});
            else{
                pq.push({-min(d+aaa.se.se,t2+aaa.se.fi),next});
            }
        }
    }
    //cout<<"dist t "<<dist[t]<<'\n';
    if(dist[t]>t_f) cout<<-1<<'\n';
    else cout<<t_f-dist[t]<<'\n';
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

