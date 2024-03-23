
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
#define INF 1000000007 
ll MOD;
ll DP[2][802];
ll sum[2][802];
ll offset=401;

void Solve(){
    ll n,k;
    cin>>n>>k>>MOD;
    //cout<<n<<' '<<k<<' '<<MOD<<'\n';
    rng(i,0,k){
        //cout<<"D "<<i<<' '<<j<<endl;
        DP[0][i+offset]=1;
    }
    rng(i,-k,k) sum[0][i+offset]=sum[0][i+offset-1]+DP[0][i];

    rng(u,1,n-2){
        rng(i,0,k){
            
                DP[u&1][i][j]=(sum[(u-1)&1][k][i]-(i-j-1<0?0:sum[(u-1)&1][i-j-1][i]))%MOD;
                sum[u&1][i][j]=(i==0?0:sum[u&1][i-1][j])+DP[u&1][i][j];
        }
    }
    ll res=0;
    rng(i,0,k){
        rng(j,0,k){
            if(i>=j) res=(res+DP[(n-2)&1][i][j])%MOD;
        }
    }
    cout<<(res+MOD)%MOD<<'\n';
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

