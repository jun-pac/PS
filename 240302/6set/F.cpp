
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

int mp[1001][1001];
int min_dist[1001][1001];

void Solve(){
    int n,m;
    cin>>n>>m;
    rng(i,0,n-1){
        rng(j,0,m-1) cin>>mp[i][j];
    }
    rng(i,0,n-1) fill(min_dist[i],min_dist[i]+m,-1);

    queue<pair<pii,int>> q; // {pos}, dist
    q.push({{0,0},0});
    while(!q.empty()){
        auto cur=q.front();
        q.pop();
        int i=cur.fi.fi, j=cur.fi.se;
        int d=cur.se;
        if(min_dist[i][j]!=-1) continue;
        min_dist[i][j]=cur.se;
        if(mp[(i+1)%n][j]==0 && mp[(i+2)%n][j]==0){
            if(min_dist[(i+2)%n][j]==-1) q.push({{(i+2)%n,j},d+1});
        }
        if(j!=m-1 && mp[(i+1)%n][j+1]==0 && min_dist[(i+1)%n][j+1]==-1) q.push({{(i+1)%n,j+1},d+1});
    }
    int res=INF;
    rng(i,0,n-1){
        if(min_dist[i][m-1]==-1) continue;
        res=min(res,min_dist[i][m-1]+(((i-min_dist[i][m-1])%n+n)%n+1)%n);
    }
    cout<<(res==INF?-1:res)<<'\n';

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

