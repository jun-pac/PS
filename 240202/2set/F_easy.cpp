
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

int datas[N];
int pos[N];
ll DP[505][505], mulDP[505][505];
bool visited[505][505];

ll get_DP(ll l, ll r){
    if(l>=r) return 1;
    if(visited[l][r]) return DP[l][r];
    ll mn=datas[l], mn_pos=l;
    rng(i,l,r) if(datas[i]<mn) mn=datas[i],mn_pos=i;
    ll l_mul=0, r_mul=0;
    if(mulDP[l+1][mn_pos-1+1]!=-1) l_mul=mulDP[l+1][mn_pos-1+1]-MOD;
    else{
        rng(i,l,mn_pos){
            l_mul=(l_mul+get_DP(i,mn_pos-1)*get_DP(l,i-1))%MOD;
        }
        mulDP[l+1][mn_pos-1+1]=l_mul+MOD;
    }
    if(mulDP[mn_pos+1+1][r+1]!=-1) r_mul=mulDP[mn_pos+1+1][r+1]-MOD;
    else{
        rng(i,mn_pos,r){
            r_mul=(r_mul+get_DP(mn_pos+1,i)*get_DP(i+1,r))%MOD;
        }
        mulDP[mn_pos+1+1][r+1]=r_mul+MOD;
    }
    return DP[l][r]=l_mul*r_mul%MOD;
}

void Solve(){
    int n,m;
    cin>>n>>m;
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-1) fill(visited[i],visited[i]+n,0);
    rng(i,0,n+1) fill(mulDP[i],mulDP[i]+n+2,-1);
    cout<<(get_DP(0,n-1)+MOD)%MOD<<'\n';
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

