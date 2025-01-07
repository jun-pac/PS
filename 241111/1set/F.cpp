
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
ll INF =10000000000007; 

ll n,k,x;
ll datas[1000];
vc<pll> mnt[101];

ll sum[1000];

void Solve(){
    cin>>n>>k>>x; 
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-1) sum[i]=(i==0?0:sum[i-1])+datas[i];
    mnt[0].pb({0,datas[0]}); // {cost, time }

    rng(i,1,n-1){
        vc<pll> DP;
        rng(j,max(0LL,i-k+1),i){
            if(j==0){
                ll t=datas[i];
                ll cost=t*(i-j+1)-(sum[i]-(j==0?0:sum[j-1]));
                DP.pb({cost, datas[i]});
            }
            else{
                // use DP[j-1][jj] for transition
                for(auto temp: mnt[j-1]){ // cost, last_time
                    ll t=max(temp.se+x,datas[i]);
                    ll cost=t*(i-j+1)-(sum[i]-(j==0?0:sum[j-1]));
                    DP.pb({cost+temp.fi, t});
                }
            }
        }
        sort(all(DP));
        vc<pll> nDP;
        nDP.pb(DP[0]);
        pll last=DP[0];
        for(int tt=1; tt<DP.size(); tt++){
            if(DP[tt].se<last.se){
                last=DP[tt];
                nDP.pb(last);
            }
        }
        mnt[i]=nDP;
    }
    ll ans=INF;
    for(auto temp:mnt[n-1]) ans=min(ans,temp.fi);
    cout<<ans<<'\n';
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

