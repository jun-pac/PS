
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

int ans[N];
ll n;

void DFS(int l, int r, ll k){
    int cur=n-(r-l+1);
    ll len=r-l+1;
    if(r-l+1>=60){
        ans[l]=cur;
        DFS(l+1,r,k);
    }
    else if(len==1){
        ans[l]=cur;
    }
    else if((1LL<<(len-2))>=k){
        ans[l]=cur;
        DFS(l+1,r,k);
    }
    else{
        ans[r]=cur;
        DFS(l,r-1,k-(1LL<<(len-2)));
    }
}

void Solve(){
    ll k;
    cin>>n>>k;
    // 최대 2^(n-1)개임
    // k>2^(n-1)이면 -1출력
    if(n<60 && (1LL<<(n-1))<k){
        cout<<-1<<'\n';
        return;
    }
    DFS(0,n-1,k);
    rng(i,0,n-1) cout<<ans[i]+1<<' ';
    cout<<'\n';
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

