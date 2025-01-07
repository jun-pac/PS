
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
string mp[12];
bool visited[12][12];
int n,m;

int DFS(int i, int j, int k){
    //cout<<"? "<<i<<' '<<j<<' '<<k<<'\n';
    if(k==0){
        return 1;
    }
    int res=0;
    visited[i][j]=1;
    rng(d,0,3){
        int ni=i+dir[d].fi, nj=j+dir[d].se;
        if(0<=ni && ni<n && 0<=nj && nj<m && !visited[ni][nj] && mp[ni][nj]=='.'){
            res+=DFS(ni,nj,k-1);
        }
    }
    visited[i][j]=0;
    return res;
}

void Solve(){
    dir[0]={-1,0};
    dir[1]={1,0};
    dir[2]={0,1};
    dir[3]={0,-1};
    int k;
    cin>>n>>m>>k;
    rng(i,0,n-1) cin>>mp[i];
    // k번의 그 무언가를
    int res=0;
    rng(i,0,n-1){
        rng(j,0,m-1){
            if(mp[i][j]=='.') res+=DFS(i,j,k);
        }
    }          
    cout<<res<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

