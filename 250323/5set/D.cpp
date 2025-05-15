
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
// random_device rd; 
// mt19937 gen(rd());
// uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

vc<int> edges[N];
ll DP[N]; // start from idx
int depth[N];
pii didx[N];
ll dsum[N];


void DFS_depth(int idx, int p, int d){
    depth[idx]=d;
    for(auto next : edges[idx]){
        if(next!=p){
            DFS_depth(next,idx,d+1);
        }
    }
}

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) edges[i].clear();
    rng(i,1,n-1){
        int p;
        cin>>p;
        p--;
        edges[p].pb(i);
        edges[i].pb(p);
    }
    DFS_depth(0,-1,0);
    rng(i,0,n-1) didx[i]={depth[i],i};
    sort(didx,didx+n);
    fill(dsum,dsum+n+1,0);
    int lastd=n-1;

    gnr(i,n-1,1){
        int idx=didx[i].se;
        int curd=didx[i].fi;
        ll childsum=0;
        for(auto next: edges[idx]){
            if(depth[next]==curd+1){
                childsum=(childsum+DP[next])%MOD;
            }
        }
        // sum=(sum+1+dsum[curd+1]-childsum)%MOD;
        DP[idx]=(1+dsum[curd+1]-childsum)%MOD;

        if( didx[i].fi!=didx[i-1].fi){
            rng(j,i,lastd){
                dsum[curd]=(dsum[curd]+DP[didx[j].se])%MOD;
            }
            lastd=i-1;
        }
    }
    ll sum=1;
    for(auto next: edges[0]){
        sum=(sum+DP[next])%MOD;
    }
    
    cout<<((sum%MOD+MOD)%MOD)<<'\n';

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

