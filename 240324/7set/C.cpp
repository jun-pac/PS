
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

ll DP[N];

void Solve(){
    ll n, invn, total=0;
    cin>>n;
    invn=ari_inv(n);
    for(ll i=0; i<=n-1; i++){
        total=(total+i*ari_inv(n-i))%MOD;
    }
    DP[n]=0;    
    DP[n-1]=(n*n-n)%MOD*(ari_inv(2*n-1))%MOD;
    for(ll i=n-2; i>=0; i--){
        ll term0=i;
        ll term1=(n-i)*(2*i+1)%MOD*invn%MOD*DP[i+1]%MOD;
        ll term2=(n-i)*(n-i-1)%MOD*invn%MOD*DP[i+2]%MOD;
        DP[i]=(term0+term1+term2)*n%MOD*ari_inv((n*n-i*i)%MOD)%MOD;
    }
    cout<<(DP[0]+MOD)%MOD<<' '<<((total-DP[0])%MOD+MOD)%MOD<<'\n';
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

