
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


ll INF=100000000000007;
ll hs[1001][1001];
ll rowc[1001], colc[1001]; // 1Áõ°¡ cost
ll DP[1001][2];

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1){
        rng(j,0,n-1) cin>>hs[i][j];
    }

    rng(i,0,n-1) cin>>rowc[i];
    rng(i,0,n-1) cin>>colc[i];

    ll res=0;
    DP[0][0]=0;
    DP[0][1]=rowc[0];
    rng(i,1,n-1){
        bool f00=0, f01=0, f10=0;
        rng(j,0,n-1){
            if(hs[i][j]==hs[i-1][j]) f00=1;
            if(hs[i][j]-1==hs[i-1][j]) f01=1;
            if(hs[i][j]==hs[i-1][j]-1) f10=1;
        }
        DP[i][0]=INF, DP[i][1]=INF;

        if(!f10) DP[i][1]=DP[i-1][0]+rowc[i];
        if(!f01) DP[i][0]=DP[i-1][1];
        if(!f00) DP[i][0]=min(DP[i][0],DP[i-1][0]);
        if(!f00) DP[i][1]=min(DP[i][1],DP[i-1][1]+rowc[i]);
        DP[i][0]=min(DP[i][0],INF);
        DP[i][0]=min(DP[i][0],INF);
    }

    res=min(DP[n-1][0],DP[n-1][1]);
    if(res>=INF){
        cout<<-1<<'\n';
        return;
    }


    rng(i,0,n-1){
        rng(j,i+1,n-1) swap(hs[i][j],hs[j][i]);
    }
    DP[0][0]=0;
    DP[0][1]=colc[0];
    rng(i,1,n-1){
        bool f00=0, f01=0, f10=0;
        rng(j,0,n-1){
            if(hs[i][j]==hs[i-1][j]) f00=1;
            if(hs[i][j]-1==hs[i-1][j]) f01=1;
            if(hs[i][j]==hs[i-1][j]-1) f10=1;
        }
        DP[i][0]=INF, DP[i][1]=INF;

        if(!f10) DP[i][1]=DP[i-1][0]+colc[i];
        if(!f01) DP[i][0]=DP[i-1][1];
        if(!f00) DP[i][0]=min(DP[i][0],DP[i-1][0]);
        if(!f00) DP[i][1]=min(DP[i][1],DP[i-1][1]+colc[i]);
        DP[i][0]=min(DP[i][0],INF);
        DP[i][0]=min(DP[i][0],INF);
    }

    res+=min(DP[n-1][0],DP[n-1][1]);
    if(res>=INF){
        cout<<-1<<'\n';
        return;
    }
    cout<<res<<'\n';
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

