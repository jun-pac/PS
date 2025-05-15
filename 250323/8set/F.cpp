
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

ll u[N], d[N];
ll n,x;

bool check(ll h){
    ll l,r;
    // u[0] d[0], h
    ll delta=u[0]+d[0]-h;
    l=max(d[0]-delta,0LL);
    r=h-max(u[0]-delta,0LL);
    rng(i,1,n-1){
        ll sl=max(l-x,0LL);
        ll sr=min(r+x,h);
        delta=u[i]+d[i]-h;
        l=max(sl, max(d[i]-delta,0LL));
        r=min(sr, h-max(u[i]-delta,0LL));
        if(l>r){
            return 0;
        }
    }
    return 1;
}

void Solve(){
    cin>>n>>x;
    rng(i,0,n-1) cin>>u[i]>>d[i];

    ll mn=u[0]+d[0];
    rng(i,0,n-1) mn=min(mn,u[i]+d[i]);
    // mn이하로 깎는다
    // 옆과 X이하의 높이차가 되기 위해서는 얼마를 더 깎아야 할 수 있음
    ll l=0,r=mn;
    while(l<r){
        ll mid=(l+r+1)>>1;
        // cout<<"MID "<<mid<<' '<<check(mid)<<'\n';
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    ll sum=0;
    rng(i,0,n-1) sum+=u[i]+d[i];
    cout<<sum-l*n<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

