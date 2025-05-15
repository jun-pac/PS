
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
random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

#define N_PRIME 1000010

bool is_prime[N_PRIME];
vector<int> primes;
int largest_prime[N_PRIME];

void build_prime(int n){
    // n<N_PRIME
    fill(is_prime+2,is_prime+n+1,true);
    for(int i=2; i<=n; i++){
        if(!is_prime[i]) continue;
        for(int j=2; i*j<=n; j++) is_prime[i*j]=false;
    }
    for(int i=2; i<=n; i++) if(is_prime[i]) primes.push_back(i);
    int r=2;
    rng(i,2,n){
        if(is_prime[i]) r=i;
        largest_prime[i]=r;
    }
}


void Solve(){
    // int n=100;
    // rng(i,4,n){
    //     cout<<i<<' '<<largest_prime[i/2]<<'\n';
    // }
    // int cnt=0;
    // rng(i,4,100000){
    //     if(largest_prime[i/2] < (i/3)-1) cnt++;
    // }
    // cout<<cnt<<'\n';
    int n;
    cin>>n;
    if(n<=3){
        rng(i,1,n) cout<<i<<' ';
        cout<<'\n';
    }
    else{
        int r=largest_prime[n/2];
        cout<<r<<' ';
        rng(i,1,r-1) cout<<i<<' '<<2*r-i<<' ';
        rng(i,2*r,n) cout<<i<<' ';
        cout<<'\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    build_prime(100001);
    int t=1;
    cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

