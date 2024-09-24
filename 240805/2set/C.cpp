
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
#define INF 1000000007 
__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

pll datas[N]; // val,num
ll nums[N];
ll numsum[N];
ll tot;

void Solve(){
    ll n,m;
    cin>>n>>m;
    rng(i,0,n-1) cin>>datas[i].fi;
    rng(i,0,n-1) cin>>datas[i].se;
    sort(datas,datas+n);
    ll mx=0;
    rng(i,0,n-1){
        mx=max(mx,min(datas[i].se,m/datas[i].fi)*datas[i].fi);
        if(i==n-1 || datas[i+1].fi!=datas[i].fi+1) continue;
        ll a=datas[i].se;
        ll b=datas[i+1].se;
        ll p=datas[i].fi;
        ll l=1, r=a+b;
        //cout<<"check double "<<a<<' '<<b<<' '<<p<<' '<<mx<<'\n';
        while(l<r){
            ll mid=(l+r)>>1;
            ll s=max(0LL,mid-a), e=min(mid,b);
            if(p*mid+s<=m) mx=max(mx,min(p*mid+e,m));
            if(mx==m) break;
            if(p*mid+e<m) l=mid+1;
            else r=mid;
        }
        if(l==r){
            ll s=max(0LL,l-a), e=min(l,b);
            if(p*l+s<=m) mx=max(mx,min(p*l+e,m));
        }
        //cout<<"MX : "<<mx<<'\n';
    }
    cout<<mx<<'\n';
    
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

