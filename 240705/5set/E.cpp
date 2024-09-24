
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
#define MAX_DIGIT 62

// Remember (ak)*(bk)^(-1) === a*b^(-1) === (ak%P)*(bk%P)^(-1) (mod P)
long long ari_inv(long long num){
    // Calculate num^(MOD-2)
    long long res=1, mult=num;
    for(int i=0; i<MAX_DIGIT; i++){
        if((MOD-2)&(1LL<<i)){
            res=(res*mult)%MOD;
        }
        mult=(mult*mult)%MOD;
    }
    return res;
}
__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

ll datas[N], sum[N];

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-1) sum[i]=((i==0?0:sum[i-1])+datas[i])%MOD;
    ll linsum=0;
    rng(i,0,n-2){
        ll k=datas[i];
        ll l=sum[n-1]-sum[i];
        linsum=(linsum+(k*l)%MOD*ari_inv(2)%MOD)%MOD;
    }
    ll res=0;
    res=(linsum*linsum)%MOD;
    rng(i,0,n-2){
        ll k=datas[i];
        ll l=sum[n-1]-sum[i];
        ll temp=(k*l)%MOD*ari_inv(2)%MOD;
        ll sq=(k*l%MOD*ari_inv(2)+k*(k-1)%MOD*(l*(l-1)%MOD)%MOD*ari_inv(4)%MOD+k*l%MOD*(k+l-2)%MOD*ari_inv(3)%MOD)%MOD;
        res=(res-temp*temp%MOD+sq)%MOD;
    }
    cout<<(res%MOD+MOD)%MOD<<'\n';
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

