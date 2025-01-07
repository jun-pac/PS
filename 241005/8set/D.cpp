
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
random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

ll datas[N], sum[N];

bool check(ll n, ll h){
    ll sss=0;
    rng(i,0,n-1){
        if(sss+datas[i]<h) return 0;
        sss=sss+datas[i]-h;
    }
    return 1;
}

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    ll mx=datas[0];
    rng(i,0,n-1) mx=max(mx,datas[i]);
    // 먼저 최대의 minimum
    ll l=1, r=mx;
    while(l<r){
        ll mid=(l+r+1)>>1;
        if(check(n,mid)) l=mid;
        else r=mid-1;
    }
    // l이 최대의 min임. 그때의 mx는?
    mx=l;
    rng(i,0,n-1) sum[i]=(i==0?0:sum[i-1])+datas[i];
    rng(i,0,n-1) mx=max(mx,cediv((sum[n-1]-(i==0?0:sum[i-1])),(n-i)));

    cout<<mx-l<<'\n';
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

