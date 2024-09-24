

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

#define N 3030
#define MOD 998244353
#define INF 1000000007 
//__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

pll water[N];
pair<int,pll> pipe[N];
vc<int> edges[N];
bool visited[N];
int dist[N];

ll CCW(pll p1, pll p2, pll p3){
    ll val=(p3.se-p2.se)*(p2.fi-p1.fi)-(p3.fi-p2.fi)*(p2.se-p1.se);
    return (val>0?1:(val<0?-1:0));
}

void Solve(){
    int w,p;
    cin>>w>>p;
    rng(i,0,w-1){
        cin>>water[i].fi>>water[i].se;
    }
    rng(i,0,p-1){
        cin>>pipe[i].fi>>pipe[i].se.fi>>pipe[i].se.se;
        pipe[i].fi--;
    }
    rng(i,0,p-1){
        rng(j,i+1,p-1){
            if(pipe[i].fi==pipe[j].fi) continue;
            // if(pipe[i].se.fi==water[pipe[j].fi].fi && pipe[i].se.se==water[pipe[j].fi].se) continue;
            // if(pipe[j].se.fi==water[pipe[i].fi].fi && pipe[j].se.se==water[pipe[i].fi].se) continue;
            if(CCW(water[pipe[i].fi],pipe[i].se,pipe[j].se)*CCW(water[pipe[i].fi],pipe[i].se,water[pipe[j].fi])<=0 &&\
             CCW(water[pipe[j].fi],pipe[j].se,pipe[i].se)*CCW(water[pipe[j].fi],pipe[j].se,water[pipe[i].fi])<=0){
                if(CCW(water[pipe[i].fi],pipe[i].se,water[pipe[j].fi])==0 && CCW(water[pipe[j].fi],pipe[j].se,water[pipe[i].fi])==0 && pipe[i].se.fi==pipe[j].se.fi && pipe[i].se.se==pipe[j].se.se){
                    edges[i].pb(j);
                    edges[j].pb(i);
                }
                else if(CCW(water[pipe[i].fi],pipe[i].se,water[pipe[j].fi])==0) continue;
                else if(CCW(water[pipe[j].fi],pipe[j].se,water[pipe[i].fi])==0) continue;
                else{
                    edges[i].pb(j);
                    edges[j].pb(i);
                }
                // intersect
                //cout<<"inter "<<pipe[i].fi<<' '<<pipe[i].se.fi<<' '<<pipe[i].se.se<<' '<<pipe[j].fi<<' '<<pipe[j].se.fi<<' '<<pipe[j].se.se<<endl;
                
            }
        }
    }
    fill(visited,visited+p,0);
    // 0 이라는 점에서 BFS를 해서 색칠한다.
    rng(i,0,p-1){
        if(!visited[i]){
            queue<pii> q;
            q.push({i,0});
            while(!q.empty()){
                auto temp=q.front();
                q.pop();
                if(visited[temp.fi]) continue;
                visited[temp.fi]=1;
                dist[temp.fi]=temp.se;
                for(auto next : edges[temp.fi]) if(!visited[next]) q.push({next,temp.se+1});
            }
        }
    }
    bool flag=1;
    rng(i,0,p-1){
        for(int j:edges[i]){
            if(dist[i]%2==dist[j]%2) flag=0;
        }
    }
    cout<<(flag?"possible\n":"impossible\n");
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


