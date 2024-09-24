
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

#define N_PRIME 1000010

bool is_prime[N_PRIME];

void build_prime(int n){
    // n<N_PRIME
    fill(is_prime+2,is_prime+n+1,true);
    for(int i=2; i<=n; i++){
        if(!is_prime[i]) continue;
        for(int j=2; i*j<=n; j++) is_prime[i*j]=false;
    }
}


void Solve(){
    ll n;
    ll res=0;
    cin>>n;
    for(ll j=2;j<=n;j++){
        // j가 나누는 애임
        if(is_prime[j]){
            for(ll k=1; k*j<=n; k++){
                ll num=min(n,k*j+j-1)-k*j+1;
                //cout<<j<<' '<<k<<' '<<num<<' '<<((-k)%j+j)%j<<' '<<(((-k)%j+j)%j)*num<<'\n';
                res=res+(((-k)%j+j)%j)*num;
                res%=INF;
            }
        }
        if(j==4){
            for(ll k=1; k*j<=n; k++){
                ll num=min(n,k*j+j-1)-k*j+1;
                res=res+(((2*k)%j+j)%j)*num;
                res%=INF;
            }
        }
    }
    cout<<(res+INF)%INF<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int res=0;


    int t=1;
    cin>>t;
    build_prime(1000001);
    while(t--){
        Solve();
    }
    return 0;
}

