
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

ll datas[101][101];
pii dir[4];

void Solve(){
    int n,m;
    cin>>n>>m;
    rng(i,0,n-1){
        rng(j,0,m-1) cin>>datas[i][j];
    }
    rng(i,0,n-1){
        rng(j,0,m-1){
            ll mx=0;
            rng(k,0,3){
                int ni, nj;
                ni=i+dir[k].fi;
                nj=j+dir[k].se;
                //cout<<i<<' '<<j<<' '<<ni<<' '<<nj<<'\n';
                if(!(0<=ni && ni<=n-1 && 0<=nj && nj<=m-1)) continue;
                mx=max(mx,datas[ni][nj]);
            }
            //cout<<"mx "<<mx<<'\n';
            datas[i][j]=min(datas[i][j],mx);
        }
    }
    rng(i,0,n-1){
        rng(j,0,m-1) cout<<datas[i][j]<<' ';
        cout<<'\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin>>t;
    dir[0]={0,1};
    dir[1]={-1,0};
    dir[2]={1,0};
    dir[3]={0,-1};
    while(t--){
        Solve();
    }
    return 0;
}

