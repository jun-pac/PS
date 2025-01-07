
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

pair<double,double> datas[13];
vc<pair<int, double>> edges[13];
double DP[13][1<<12]; // [last_idx][visited] // must be initialized with INF
// DP[last_idx][visited] indicates that "Minimum TSP excluding the set {visited}, which ended with last_idx"
int n;

// Re-visit already visited vertices are prohibited.
double TSP_DFS(int idx, int visit){ // idx is already included in visit, and DP[idx][visit] is minimum cost to traverse vertices excluding visit.
    if(visit==(1<<(2*n))-1) return DP[idx][visit]=0;
    if(DP[idx][visit]!=INF) return DP[idx][visit];
    bool only=0;
    int only_idx=0;
    if(idx!=2*n){
        only_idx=(idx/2)*4+1-idx;
        if(!(visit&(1<<only_idx))) only=1; 
    }
    if(only){
        for(auto temp : edges[idx]){
            int next=temp.first;
            double dist=temp.second;
            if(next!=only_idx) continue;
            DP[idx][visit]=min(DP[idx][visit],TSP_DFS(next,visit|(1<<next))+dist);
        }
        return DP[idx][visit];
    }
    else{
        for(auto temp : edges[idx]){
            int next=temp.first;
            double dist=temp.second;
            if(visit&(1<<next)) continue;
            DP[idx][visit]=min(DP[idx][visit],TSP_DFS(next,visit|(1<<next))+dist);
        }
        return DP[idx][visit];
    }
}

double distc(pair<double, double> a, pair<double, double> b){
    return sqrt((a.fi-b.fi)*(a.fi-b.fi)+(a.se-b.se)*(a.se-b.se));
}
void Solve(){
    double s,t;
    cin>>n>>s>>t;
    //cout<<"n: "<<n<<'\n';
    s=1/s;
    t=1/t;
    rng(i,0,n-1){
        cin>>datas[2*i].fi>>datas[2*i].se;
        cin>>datas[2*i+1].fi>>datas[2*i+1].se;
        edges[2*i].pb({2*i+1,t*distc(datas[2*i],datas[2*i+1])});
        edges[2*i+1].pb({2*i,t*distc(datas[2*i],datas[2*i+1])});
    }
    // TSP idea
    rng(i,0,2*n-1){
        rng(j,0,2*n-1){
            if(i/2==j/2) continue;
            edges[i].pb({j,distc(datas[i],datas[j])*s});
        }
    }
    // from the beginning
    for(int i=0; i<2*n; i++){
        pair<double,double> a={0,0};
        edges[2*n].pb({i,s*distc(datas[i],a)});
    }
    rng(i,0,2*n) fill(DP[i],DP[i]+(1<<(2*n)),INF);
    cout<<fixed;
    cout.precision(12);
    cout<<TSP_DFS(2*n,0)<<'\n';
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

