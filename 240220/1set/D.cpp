
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

ll cnt[N];
ll n,b,x;

inline ll f(ll c, ll k){
    return (c%k)*((c/k+1)*(c-c/k-1))+(k-c%k)*((c/k)*(c-c/k));
}

inline ll calc_k(ll k){
    ll nump=0;
    rng(i,0,n-1){
        nump+=f(cnt[i],k);
    }
    assert(nump%2==0);
    return nump/2*b-(k-1)*x;
}

void Solve(){
    cin>>n>>b>>x;
    rng(i,0,n-1) cin>>cnt[i];

    ll s=1, e=N;
    while(3<=e-s){
        ll l=(s+s+e)/3, r=(s+e+e)/3;
        if(calc_k(l)<=calc_k(r)) s=l;
        else e=r;
    }
    ll mx=0;
    for(ll i=s; i<=e; i++){
        ll temp=calc_k(i);
        if(mx<temp) mx=temp;
    }
    cout<<mx<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // rng(i,1,20){
    //     cout<<"C "<<i<<" : ";
    //     rng(k,1,10) cout<<f(i,k)<<' ';
    //     cout<<'\n';
    // }
    int t=1;
    cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

