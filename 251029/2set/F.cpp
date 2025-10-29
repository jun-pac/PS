
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


ll a[N], c[N];
ll h,n;

bool enough_score(ll turn){
    ll res=0;
    rng(i,0,n-1){
        res+=a[i]*(1+turn/c[i]);
        if(res>=h) return 1;
    }
    return 0;
}

void Solve(){
    cin>>h>>n;
    rng(i,0,n-1) cin>>a[i];
    rng(i,0,n-1) cin>>c[i];
    ll tot=40000000000;
    ll l=0, r=tot;
    while(l<r){
        ll mid=(l+r)>>1;
        if(enough_score(mid)) r=mid;
        else l=mid+1;
    }
    cout<<l+1<<'\n';
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

