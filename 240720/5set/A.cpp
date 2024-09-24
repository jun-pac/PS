
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

ll datas[N];
vc<ll> mod3[3];
ll n,s; // socket이 기본값, n이 charger의 개수
int cnt[3];

bool check(int idx){
    // [0, ... ,idx]를 사용
    fill(cnt,cnt+3,0);
    ll val=0;
    rng(i,0,idx){
        cnt[datas[i]%3]++;
        val+=(datas[i]%3==0?datas[i]/3:datas[i]/3+1);
    }
    if(cnt[1]>=cnt[2]) val-=(cnt[2]+(cnt[1]-cnt[2])/2);
    else val-=cnt[1];
    return val<=s-2;
}

void Solve(){
    cin>>n>>s;
    rng(i,0,n-1)cin>>datas[i];
    sort(datas,datas+n);
    if(n==1||s==1){
        cout<<1<<'\n';
        return;
    }
    int l=0, r=n-3;
    while(l<r){
        int mid=(l+r+1)>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    if(check(l)) cout<<l+3<<'\n';
    else cout<<2<<'\n';
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

