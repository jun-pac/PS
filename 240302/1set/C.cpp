
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

#define N 120
#define MOD 998244353
#define INF 1000000007 
__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

long long fact[N], f_inv[N];
ll DP[N],tot[N]; //먼저 시작하는 아이가 이기는 경우의 수. n이 짝수인 경우에만 의미있음.

void fill_fact(){
    fact[0]=1;
    for(int i=1; i<N; i++) fact[i]=fact[i-1]*i%MOD;
    fill(f_inv,f_inv+N,1);
    for(int k=0; k<30; k++){
        for(int i=0; i<N; i++){
            f_inv[i]=f_inv[i]*f_inv[i]%MOD;
            if((MOD-2)&(1<<(29-k))) f_inv[i]=f_inv[i]*fact[i]%MOD;
        }
    }
}

long long nCr(int n, int r){
    return ((fact[n]*f_inv[r])%MOD)*f_inv[n-r]%MOD;
}


void Solve(){
    int n;
    cin>>n;
    rng(i,1,n/2){
        tot[2*i]=nCr(i*2,i);
    }
    DP[2]=1; // draw가 1, 지는 경우는 0
    rng(i,4,n){
        if(i%2!=0) continue; 
        DP[i]=tot[i]*f_inv[2]%MOD; // 이기는 경우는 i를 내가 가지는 경우, i를 못가졌지만 i-1을 내가 가지고 DP[i-2]에서 지는 경우.
        DP[i]=(DP[i]+(tot[i-2]-1-DP[i-2]))%MOD; // 내가 지는 경우로 가야함.
    }
    cout<<(DP[n]+MOD)%MOD<<' '<<((tot[n]-1-DP[n])%MOD+MOD)%MOD<<' '<<1<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin>>t;
    fill_fact();
    while(t--){
        Solve();
    }
    return 0;
}

