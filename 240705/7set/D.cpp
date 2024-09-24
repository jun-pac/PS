
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

#define N 1000030
#define MOD 998244353
#define INF 1000000007 
__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

int build[N], melt[N];
pii db[N];
vc<pii> usef;
ll ingot[N];
int DP[N];
int n,m;
int mx;

ll get_num(ll x){
    // ingot의 양
    // 따로 풀어야 하는 문제임 어차피
    if(x<=mx) return DP[x];
    // usef[0]으로 지울 수 있을 때까지 지우는 전략.
    int res=cediv(x-usef[0].se,usef[0].fi);
    assert(0<=x-res*usef[0].fi && x-res*usef[0].fi<=mx);
    return res+DP[x-res*usef[0].fi];
}

void Solve(){
    cin>>n>>m;

    rng(i,0,n-1) cin>>build[i];
    rng(i,0,n-1) mx=max(mx,build[i]);
    rng(i,0,n-1) cin>>melt[i];
    rng(i,0,n-1) db[i]={build[i]-melt[i],build[i]};
    sort(db,db+n);
    int last=db[0].se;
    usef.pb(db[0]);
    rng(i,1,n-1){
        if(last>=db[i].se){
            last=db[i].se;
            usef.pb(db[i]);
        }
    }
    // 어차피 10^6이하만 남는 건 fact
    DP[0]=0;
    rng(i,1,mx){
        int l=0, r=(int)usef.size()-1;
        // build가 i보다 작아야 하고, 그 중에서 가장 앞에있는 애
        if(i<usef[r].se) DP[i]=0;
        else{
            while(l<r){
                int mid=(l+r)>>1;
                if(usef[mid].se<=i) r=mid;
                else l=mid+1;
            }
            DP[i]=DP[i-usef[l].fi]+1;
        }        
    }
    rng(i,0,m-1) cin>>ingot[i];
    ll res=0;
    rng(i,0,m-1)res+=get_num(ingot[i]);
    cout<<res*2<<'\n';
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

