
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

int datas[N];
ll DP[N][2]; // DP[i][0] {b,b,b}, DP[i][1] {a,a,b}

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-1) DP[i][0]=DP[i][1]=0;
    DP[0][0]=3;
    ll a=-1, b=0; // a is -1. actually
    rng(i,1,n){
        if(a==-1){
            DP[i][0]=0;
            DP[i][1]=3*DP[i-1][0]%MOD;
        }
        else{
            if(datas[i-1]==a^b){
                DP[i][1] = (DP[i-1][0]*3+DP[i-1][1]*2)%MOD;
                DP[i][0] = (DP[i-1][1])%MOD;
            }
            else{
                DP[i][1] = (DP[i-1][0]*3)%MOD;
                DP[i][0] = (DP[i-1][1])%MOD;
            }
        }
    }
    cout<<((DP[n][0]+DP[n][1])%MOD+MOD)%MOD<<'\n';
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

