
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
//__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

#define N 300030
#define MOD 998244353
#define INF 1000000007 

ll powt[20];

bool check(ll num){
    int n=0;
    while(n+1<19 && num>=powt[n+1]) n++;
    //cout<<"DP "<<num<<' '<<n<<'\n';
    // powt[n]<=num
    bool flag=1;
    rng(i,0,n) if((num/powt[i])%10!=(num/powt[n-i])%10) flag=0;
    return flag;
}

void Solve(){
    rng(i,0,18) powt[i]=(i==0?1:powt[i-1]*10);

    ll n;
    cin>>n;
    ll l=1, r=1000000; // l^3이 n이하인 최대의 l
    while(l<r){
        ll mid=(l+r+1)/2;
        if(mid*mid*mid<=n) l=mid;
        else r=mid-1;
    }
    for(ll i=l; i>=1; i--){
        if(check(i*i*i)){
            cout<<i*i*i<<'\n';
            return;
        }
    }
    cout<<"f\n";
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

