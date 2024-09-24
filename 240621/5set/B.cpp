
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
    ll n,m;
    cin>>n>>m;
    // [max(0,n-m), n+m] �� OR���� ���ϸ� �ȴ���
    ll l=max(0LL, n-m);
    ll r=n+m;
    ll mxbit=0;
    ll temp=r;
    while(temp!=0){
        temp/=2;
        mxbit++;
    }
    ll res=0;
    rng(i,0,mxbit){
        ll cur=(1LL<<i);
        if(cur&r){
            res=res|cur;
        }
        else{
            ll last=r/(2*cur)*(2*cur)-1;
            assert(last<=r);
            if(l<=last) res=res|cur;
        }
    }
    cout<<res<<'\n';
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

