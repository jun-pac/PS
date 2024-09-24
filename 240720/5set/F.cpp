
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
__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))
#define epsilon 0.0000000001
pair<double,double> pos[20]; 

double dist[12][12]; // {next, dist}
double DP[12][1<<12]; // [last_idx][visited]
int n;

double TSP_DFS(int idx, int visit){
    if(visit==(1<<n)-1) return DP[idx][visit]=0;
    DP[idx][visit]=INF;
    rng(next,0,n-1){
        if(visit&(1<<next)) continue;
        DP[idx][visit]=min(DP[idx][visit],TSP_DFS(next,visit|(1<<next))+dist[idx][next]);
    }
    return DP[idx][visit];
}

void Solve(){
    cin>>n;
    rng(i,0,n-1) cin>>pos[i].fi>>pos[i].se;
    double mn=INF;
    // 일단 원래 grid에서
    rng(i,0,n-1){
        rng(j,i+1,n-1){
            double dd=abs(pos[i].fi-pos[j].fi)+abs(pos[i].se-pos[j].se);
            dist[i][j]=dd;
            dist[j][i]=dd;
        }
    }
    rng(i,0,n-1) mn=min(mn,TSP_DFS(i,(1<<i)));

    rng(i,0,n-1){
        rng(j,i+1,n-1){
            double x1, y1, x2, y2, xi, yi, xj, yj;
            x1=pos[i].fi, y1=pos[i].se;
            x2=pos[j].fi, y2=pos[j].se;
            double pd=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
            if(abs(x1-x2)<epsilon || abs(y1-y2)<epsilon) continue;
            rng(ii,0,n-1){
                xi=pos[ii].fi, yi=pos[ii].se;
                rng(jj,ii+1,n-1){
                    xj=pos[jj].fi, yj=pos[jj].se;
                    double dd=(abs((xi-xj)*(x1-x2)+(yi-yj)*(y1-y2)))/pd+(abs((xi-xj)*(y1-y2)+(yi-yj)*(x2-x1)))/pd;
                    dist[ii][jj]=dd;
                    dist[jj][ii]=dd;
                }
            }
            rng(k,0,n-1) mn=min(mn,TSP_DFS(k,(1<<k)));
        }
    }
    cout<<fixed;
    cout.precision(12);
    cout<<mn<<'\n';
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

