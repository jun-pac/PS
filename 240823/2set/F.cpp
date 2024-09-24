
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

ll a[N], b[N];

void Solve(){
    ll n,k;
    cin>>n>>k;
    rng(i,0,n-1) cin>>a[i];
    rng(i,0,n-1) cin>>b[i];
    // k가 굉장히 크다. 
    // 근데 a라는 건 한 번 사용하는 순간 작
    // 하나를 선택하는 choice는 deterministic하네
    priority_queue<pii> pq; // {2*val, idx}
    rng(i,0,n-1){
        if(a[i]>b[i]) pq.push({a[i]*2,i});
        else if(2*a[i]>b[i]) pq.push({a[i]*2,i});
        else pq.push({b[i],i}); 
    }
    // a[i]는 실시간으로 계속 update해주는 거죠
     
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

