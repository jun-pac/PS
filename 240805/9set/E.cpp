
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

#define N 300030
#define MOD 998244353
#define INF 1000000007 

int n,m,nn;
int datas[15][15];
int odatas[15][15];
int xorsn[15], xorsm[15];
vector<pair<int,int>> edges[15]; // {next, dist}
int DP[15][1<<15]; // [last_idx][visited] // must be initialized with INF
// DP[last_idx][visited] indicates that "Minimum TSP excluding the set {visited}, which ended with last_idx"

// Re-visit already visited vertices are prohibited.
int TSP_DFS(int idx, int visit){ // idx is already included in visit, and DP[idx][visit] is minimum cost to traverse vertices excluding visit.
    if(visit==(1<<nn)-1) return DP[idx][visit]=0;
    if(DP[idx][visit]!=INF) return DP[idx][visit];
    for(auto temp : edges[idx]){
        int next=temp.first;
        int dist=temp.second;
        if(visit&(1<<next)) continue;
        DP[idx][visit]=min(DP[idx][visit],TSP_DFS(next,visit|(1<<next))+dist);
    }
    return DP[idx][visit];
}


int min_dist(){
    int res=0;
    rng(i,0,n-1) edges[i].clear();
    rng(i,0,n-1){
        rng(j,i+1,n-1){
            int temp=0;
            rng(k,0,m-1){
                temp+=abs(datas[i][k]-datas[j][k]);
            }
            //cout<<"i j temp "<<i<<' '<<j<<' '<<temp<<'\n';
            edges[i].push_back({j,temp});
            edges[j].push_back({i,temp});
        }
    }
    nn=n;
    int mn=INF;
    rng(i,0,n-1) fill(DP[i],DP[i]+(1<<n),INF);
    rng(i,0,n-1) mn=min(mn,TSP_DFS(i,(1<<i)));
    res=mn;
    //cout<<"mn1 : "<<mn<<'\n';

    rng(i,0,m-1) edges[i].clear();
    rng(i,0,m-1){
        rng(j,i+1,m-1){
            int temp=0;
            rng(k,0,n-1){
                temp+=abs(datas[k][i]-datas[k][j]);
            }
            edges[i].push_back({j,temp});
            edges[j].push_back({i,temp});
        }
    }
    nn=m;
    mn=INF;
    rng(i,0,m-1) fill(DP[i],DP[i]+(1<<m),INF);
    rng(i,0,m-1) mn=min(mn,TSP_DFS(i,(1<<i)));
    //cout<<"mn2 : "<<mn<<'\n'; 
    res+=mn;
    //cout<<"res "<<res<<'\n';
    return res;
}
void Solve(){
    cin>>n>>m;
    rng(i,0,n-1) rng(j,0,m-1) cin>>odatas[i][j];
    rng(i,0,n-1) rng(j,0,m-1) datas[i][j]=odatas[i][j];
    int mn=min_dist();
    //cout<<"this mn : "<<mn<<'\n';
    
    rng(j,0,m-1){
        int x=0;
        rng(i,0,n-1) x=x^odatas[i][j];
        xorsm[j]=x;
    }
    rng(i,0,n-1){
        rng(j,0,m-1) datas[i][j]=xorsm[j];
        rng(ii,0,n-1){
            if(ii==i) continue;
            rng(j,0,m-1){
                datas[ii][j]=odatas[ii][j];
            }
        }
        mn=min(mn,min_dist());
    }
    rng(i,0,n-1){
        int x=0;
        rng(j,0,m-1) x=x^odatas[i][j];
        xorsn[i]=x;
    }
    rng(j,0,m-1){
        rng(i,0,n-1) datas[i][j]=xorsn[i];
        rng(jj,0,m-1){
            if(jj==j) continue;
            rng(i,0,n-1){
                datas[i][jj]=odatas[i][jj];
            }
        }
        mn=min(mn,min_dist());
    }    

    int xx=0;
    rng(i,0,n-1) xx^=xorsn[i];
    rng(i,0,n-1){
        rng(j,0,m-1){
            datas[i][j]=xx;
            rng(ii,0,n-1){
                rng(jj,0,m-1){
                    if(ii==i && jj==j) continue;
                    else if(ii==i) datas[ii][jj]=xorsm[jj];
                    else if(jj==j) datas[ii][jj]=xorsn[ii];
                    else datas[ii][jj]=odatas[ii][jj];
                }
            }
            mn=min(mn,min_dist());
        }
    }
    cout<<mn<<'\n';
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

