
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

string s;
ll cost[N], costa[N], costb[N];

void Solve(){
    int n;
    cin>>n;
    cin>>s;
    rng(i,0,n-1) cin>>cost[i];
    rng(i,0,n-1) costa[i]=(i==0?0:costa[i-1])+(((s[i]=='1')^(i%2))?0:cost[i]);
    rng(i,0,n-1) costb[i]=(i==0?0:costb[i-1])+(((s[i]=='1')^(i%2))?cost[i]:0);
    ll mn=costa[0]+costb[n-1]-costb[0];
    rng(i,0,n-2){
        mn=min(mn,costa[i]+costb[n-1]-costb[i]);
        mn=min(mn,costb[i]+costa[n-1]-costa[i]);
    }
    cout<<mn<<'\n';
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

