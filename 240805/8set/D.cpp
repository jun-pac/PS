
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
//__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

ll n;
ll r;
ll p;
vector<ll> dp;

ll top_down(int cur){
    //cout<<"Called: "<<cur<<'\n';
    if(cur==1) return dp[1] = 0;
    if(dp[cur] != -1) return dp[cur];
    dp[cur] = LLONG_MAX;
    for(int i=1;i<=sqrt(cur)+1;i++){
        //cout<<"Loop Called i"<<i<<'\n';
        dp[cur] = min(dp[cur], top_down((cur+i)/(i+1))+r+p*i);
    }
    for(int i=1;i<=sqrt(cur)+1;i++){
        //cout<<"Loop Called i"<<i<<'\n';
        dp[cur] = min(dp[cur], top_down(i) + p * (((cur+i-1))/i-1) + r);
    }
    return dp[cur];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n>>r>>p;
    dp.resize(n+1, -1);
    dp[0] = 0;
    top_down(n);
    for(int i=1;i<=n;i++){
        //cout<<dp[i]<<'\n';
    }
    cout<<dp[n];
    return 0;
}

