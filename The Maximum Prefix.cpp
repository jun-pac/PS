
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
typedef long long ll;
using pii=pair<int,int>;
using ull=unsigned long long;

#define N 5005
#define INF 1000000007
#define MOD 1000000007
#define MAX_DIGIT 62

ll DP[N][N]; // DP[i][j] = Expected value of S_{1,n} given S_{i+1,n}==j
ll h[N];
ll p[N];

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

void Solve(){
    int n;
    cin>>n;
    rng(i,1,n){
        ll x,y;
        cin>>x>>y;
        p[i]=x*ari_inv(y)%MOD;
    }
    rng(i,0,n) cin>>h[i];
    rng(j,0,n) DP[0][j]=h[j];
    rng(i,1,n){
        rng(j,0,n-i){
            DP[i][j]=p[i]*DP[i-1][j+1]+(1-p[i]+MOD)*DP[i-1][max(0,j-1)];
            DP[i][j]%=MOD;
        }  
        cout<<(DP[i][0]+MOD)%MOD<<' ';
    }
    cout<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) Solve();   
}

