
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

vc<pii> es; // only additional
ll DP[N];

void Solve(){
    int n,m,k;
    cin>>n>>m>>k;
    rng(i,0,m-1){
        int a,b;
        cin>>a>>b;
        a--, b--;
        es.pb({a,b});
    }
    fill(DP,DP+n,0);
    DP[0]=1;
    rng(i,0,k-1){
        vc<pll> ads;
        rng(j,0,m-1){
            int a=((es[j].fi-i)%n+n)%n, b=((es[j].se-i-1)%n+n)%n;
            ads.pb({b,DP[a]});
        }
        rng(j,0,m-1) DP[ads[j].fi]=(DP[ads[j].fi]+ads[j].se)%MOD;
    }
    ll sum=0;
    rng(i,0,n-1) sum=(sum+DP[i])%MOD;
    cout<<(sum%MOD+MOD)%MOD<<'\n';
    
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

