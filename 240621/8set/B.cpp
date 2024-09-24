
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
__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))


void Solve(){
    ll n,a,b;
    cin>>n>>a>>b;
    ll mx=n*a;
    if(b>=a){
        if(b-a>=0 && b-a<=n){
            ll k=b-a;
            mx=max(mx,b*k-(k*(k-1))/2+a*(n-k));
        }
        if(b-a+1>=0 && b-a+1<=n){
            ll k=b-a+1;
            mx=max(mx,b*k-(k*(k-1))/2+a*(n-k));
        }
        if(b-a>=n){
            ll k=n;
            mx=max(mx,b*k-(k*(k-1))/2+a*(n-k));
        }
        cout<<mx<<'\n';
    }
    else{
        cout<<mx<<'\n';
    }
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

