
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

ll gcd(ll x, ll y){
    if(x<y) swap(x,y);
    if(y==0) return x;
    if(x%y==0) return y;
    return gcd(y,x%y);
}

void Solve(){
    ll n,m,k;
    cin>>n>>m>>k;
    ll nn=n/gcd(n,m);
    ll mm=m/gcd(n,m);
    
    ll res=(k%(nn+mm-2)==0?nn+mm-2:k%(nn+mm-2)); // residual
    //cout<<"res "<<res<<' '<<nn<<' '<<mm<<'\n';
    ll l=1, r=nn*mm-1;
    while(l<r){
        ll mid=(l+r)/2;
        if(mid/nn+mid/mm>=res) r=mid;
        else l=mid+1;
    }
    ll mul=((k%(nn+mm-2)==0?-1:0)+k/(nn+mm-2))*(nn*mm)+l;
    cout<<mul*gcd(n,m);
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
