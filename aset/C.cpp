
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

pii dir[4];
ll datas[1001][1001];
bool visited[1001][1001];
int n,m;

ll DFS(int i, int j){
    visited[i][j]=1;
    ll res=datas[i][j];
    rng(k,0,3){
        int ni=i+dir[k].fi;
        int nj=j+dir[k].se;
        if(0<=ni && ni<n && 0<=nj && nj<m && !visited[ni][nj] && datas[ni][nj]>0) res+=DFS(ni,nj);
    }
    return res;
}


void Solve(){
    cin>>n>>m;
    rng(i,0,n-1) rng(j,0,m-1) cin>>datas[i][j];
    rng(i,0,n-1) fill(visited[i],visited[i]+m,0);
    ll mx=0;
    rng(i,0,n-1){
        rng(j,0,m-1){
            if(!visited[i][j] && datas[i][j]>0) mx=max(mx,DFS(i,j));
        }
    }
    cout<<mx<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin>>t;
    dir[0]={0,1};
    dir[1]={0,-1};
    dir[2]={1,0};
    dir[3]={-1,0};
    while(t--){
        Solve();
    }
    return 0;
}

