
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
#define INF 1000000007 
__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

bool rvis[N], cvis[N];
ll DP[N];

void Solve(){
    int n,k;
    cin>>n>>k;
    fill(rvis,rvis+n,0);
    fill(cvis,cvis+n,0);
    rng(i,0,k-1){
        int a,b;
        cin>>a>>b;
        a--, b--;
        rvis[a]=1;
        cvis[b]=1;
        rvis[b]=1;
        cvis[a]=1;
    }
    int rl=0, cl=0;
    rng(i,0,n-1) if(rvis[i]==0) rl++;
    rng(i,0,n-1) if(cvis[i]==0) cl++;
    if(rl==0){
        cout<<1<<'\n';
        return;
    }
    assert(rl==cl);
    DP[0]=1;
    rng(i,1,rl-1){
        DP[i]=DP[i-1];
        DP[i]=(DP[i]+(2*i)*(i==1?1:DP[i-2]))%MOD;
    }
    cout<<(DP[rl-1]+MOD)%MOD<<'\n';
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

