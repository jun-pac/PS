
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
#define N_PRIME 1000005

#define INF 1000000007 
__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

bool is_prime[N];
vector<int> primes;
bool visited[1500][1500];
int dur[4000];
int ans[1000001];
int n;


void Solve(){
    cin>>n;
    int l=1,r=1500;
    while(l<r){
        int mid=(l+r)>>1;
        if((mid*(mid-1))/2+mid>=n-1){
            r=mid;
        }
        else l=mid+1;
    }
    // 소수 l개를 쓴다.
    int m=l;
    int idx=0;
    if(m%2==0){

    }
    else{
        int i=0;
        while(i<=(m+1)/2-1){
            rng(j,0,m-1){
                
            }
        }
    }

}

void build_prime(int n){
    // n<N_PRIME
    fill(is_prime+2,is_prime+n+1,true);
    for(int i=2; i<=n; i++){
        if(!is_prime[i]) continue;
        for(int j=2; i*j<=n; j++) is_prime[i*j]=false;
    }
    for(int i=2; i<=n; i++) if(is_prime[i]) primes.push_back(i);
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin>>t;
    build_prime(30000); // 3245
    // cout<<primes.size()<<'\n';
    // rng(i,0,10) cout<<primes[i]<<' ';
    // cout<<'\n';

    while(t--){
        Solve();
    }
    return 0;
}

