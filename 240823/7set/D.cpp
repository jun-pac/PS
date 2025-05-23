
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

#define N 400030
#define MOD 998244353
#define INF 1000000007 

ll datas[N];
ll sum[N];
// 나머지별로 뭔가를
vc<int> res[1000001]; // M에 대해서 같은 나머지를 가지는 것 끼리 모으는 작업이죠.

void Solve(){
    ll n,m;
    cin>>n>>m;
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-1) datas[i+n]=datas[i];
    rng(i,0,2*n-1) sum[i]=(i==0?0:sum[i-1])+datas[i];
    rng(i,0,2*n-1) res[sum[i]%m].pb(i);
    ll ans=0;
    rng(i,0,n-1){
        ll val=(i==0?0:sum[i-1])%m;
        ans+=lower_bound(res[val].begin(),res[val].end(),i+n-1)-lower_bound(res[val].begin(),res[val].end(),i);
    }
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

