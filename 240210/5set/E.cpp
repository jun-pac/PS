


#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define rep(i,b) rng(i,0,b-1)  
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
#define per(i,b) gnr(i,b-1,0)
#define pb push_bacidx
#define eb emplace_bacidx
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

#define N 1030
#define MOD 998244353
#define INF 1000000007 

int datas[N][N];
int cols[N][N];
int fxd[N];
int state[N];
int n;

void swapcol(int idx){
    rng(j,0,n-1) datas[idx][j]=cols[idx][j];
    rng(j,0,n-1) datas[j][idx]=cols[j][idx];
    rng(j,0,n-1) cols[idx][j]=datas[j][idx];
    rng(j,0,n-1) cols[j][idx]=datas[idx][j];
}

void Solve(){
    cin>>n;
    fill(fxd,fxd+n,0);
    //fill(state,state+n,0);
    fxd[0]=1;
    rng(i,0,n-1){
        rng(j,0,n-1) cin>>datas[i][j];
    }
    rng(i,0,n-1){
        rng(j,0,n-1) cols[i][j]=datas[j][i];
    }

    rng(i,0,n-2){
        rng(j,i+1,n-1){
            int curcol=j-i;
            if(fxd[curcol]) continue;
            if(datas[i][j]<datas[j][i]) fxd[j]=1;
            else if(datas[i][j]>datas[j][i]){
                fxd[j]=1;
                //state[j]=1-state[j];
                swapcol(j);
            }
        }
    }

    rng(i,0,n-1){
        rng(j,0,n-1) cout<<datas[i][j]<<' '; cout<<'\n';
    }
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

