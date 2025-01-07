
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

#define N 5001
#define MOD 998244353
#define INF 1000000007 


double p[N];
double DP[N][N];
double onep[N];
double DP2[N];
// DP2[i]: Expected number of pack required to obtain i rare cards
// contains more than i cards. Maybe more than X
// transition?
// DP2[i] = 1 + sum{DP[i]*g[0]+DP[i-1]*g[1]+DP[i-2]*g[2]+ ... + DP[i-1]*g[n]}
// 이게 DP[i]에는 i보다 더 많은 원소에 도달한 경우가 포함된 것 아닌지
// 아니 정확하게 X인가
// 나머지는 다 정확하게 i개이고, DP[X]는 X개 이상의 뭔가임

void Solve(){
    ll n,x;
    cin>>n>>x;
    rng(i,0,n-1) cin>>p[i];
    rng(i,0,n-1) p[i]/=100;
    
    DP[0][1]=p[0];
    DP[0][0]=1-p[0];
    rng(i,1,n-1){
        DP[i][0]=DP[i-1][0]*(1-p[i]);
        rng(j,1,i+1){
            DP[i][j]=DP[i-1][j]*(1-p[i])+DP[i-1][j-1]*p[i];
        }
    }
    double res=0;
    rng(i,0,n) onep[i]=DP[n-1][i];


    cout.precision(12);
    cout<<fixed; 
    cout<<res<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

