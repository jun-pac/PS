
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

#define MAX_DIGIT 62

long long ari_inv(long long num){
    long long res=1, mult=num;
    for(int i=0; i<MAX_DIGIT; i++){
        if((MOD-2)&(1LL<<i)){
            res=(res*mult)%MOD;
        }
        mult=(mult*mult)%MOD;
    }
    return res;
}

inline ll ppow(ll p, ll num){
    // p^num % MOD
    ll tempn=num%(MOD-1), res=1, mult=p;
    for(int i=0; i<MAX_DIGIT; i++){
        if(tempn&(1LL<<i)){
            res=(res*mult)%MOD;
        }
        mult=(mult*mult)%MOD;
    }
    return res;
}

ll DP[1000][1000]; // DP[n][k] means distribute k th rank among n rows
ll pexp[1000];

void Solve(){
    int n;
    ll p;
    cin>>n>>p;
    rng(i,0,n-1){
        pexp[i]=(i==0?1:pexp[i-1]*p)%MOD;
        pexp[i]+=MOD;
        pexp[i]%=MOD;
    }
    DP[0][0]=1;
    rng(i,1,n-1){
        DP[i][0]=1;
        rng(j,1,i){
            ll res=0;
            rng(k,0,i-j){
                res=(res+DP[i-k-1][j-1]*pexp[i-j-k])%MOD;
            }
            DP[i][j]=(res+MOD)%MOD;
        }
    }   
    rng(i,1,n-1){
        cout<<"n["<<i<<"] : ";
        rng(j,0,n-1){
            cout<<DP[i][j]<<' ';
        }
        cout<<endl;
    }
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

