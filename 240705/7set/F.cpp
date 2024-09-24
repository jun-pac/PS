
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

ll DP[11][N], sum[11][N];

void Solve(){
    int n,k;
    cin>>n>>k;
    // k인 버전에서 k-1인 버전만 빼면 되는 거 아님?
    DP[0][0]=1;
    sum[0][0]=1;
    rng(i,1,n-1){
        if(i==1 || i==n-1){
            DP[0][i]=(sum[0][i-1]+1)%MOD;
        }
        else{
            DP[0][i]=(sum[0][i-1]+1-DP[0][i-2])%MOD;
        }
        sum[0][i]=(sum[0][i-1]+DP[0][i])%MOD;
    }
    ll res=DP[0][n-1];
    //cout<<"res "<<res<<'\n';
    
    fill(DP[0],DP[0]+n,0);
    fill(sum[0],sum[0]+n,0);
    DP[1][0]=1;
    sum[1][0]=1; // 나머지 DP[j][0]는 모두 0임.
    rng(i,1,n-1){
        DP[1][i]=1;
        sum[1][i]=(sum[1][i-1]+1)%MOD;
        rng(j,2,min(i+1,k-1)){
            if(i==1 || i==n-1){
                DP[j][i]=(sum[j-1][i-1])%MOD;
            }
            else{
                DP[j][i]=(sum[j-1][i-1]-DP[j-1][i-2])%MOD;
            }
            sum[j][i]=(sum[j][i-1]+DP[j][i])%MOD;
        }
    }
    //rng(j,1,k-1) cout<<j<<' '<<DP[j][n-1]<<'\n';
    rng(j,1,k-1) res=(res-DP[j][n-1])%MOD;
    cout<<(res+MOD)%MOD<<'\n';
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

