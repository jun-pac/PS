
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
#define MOD 1000000007

ll DP[5001][101];
ll temp[101];
ll sum[5501];

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

void Solve(){
    ll n,l,k;
    cin>>n>>l>>k;
    // assert(k==0);
    DP[0][0]=1;
    rng(j,1,n-1) DP[0][j]=0;
    rng(i,1,l-1){ // cause we have l keys;
        rng(j,0,n-1) temp[j]=DP[i-1][(j-1+n)%n]+(j==0?1:0);
        // rng(j,0,n-1) cout<<temp[j]<<' ';
        // cout<<'\n';
        rng(j,0,i+1+n-1) sum[j]=((j==0?0:sum[j-1])+temp[j%n])%MOD;
        // cout<<"sum ";
        // rng(j,0,i+1+n+1) cout<<sum[j]<<' ';
        // cout<<'\n';
        rng(j,i+1,i+1+n-1) DP[i][j%n]=(sum[j]-sum[j-(i+1)])%MOD*ari_inv(i+1)%MOD;
    }

    rng(i,0,n-1) cout<<(DP[l-1][i]+MOD)%MOD<<' ';
    cout<<'\n';
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

