
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
//__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

string a[500], b[500], c[500];
int an[500], bn[500], cn[500];
int DP[501][501][501]; // [i][j][k]

void Solve(){
    int n,p,q;
    cin>>n>>p>>q;
    rng(i,0,n-1) cin>>a[i];
    rng(i,0,p-1) cin>>b[i];
    rng(i,0,q-1) cin>>c[i];
    rng(i,0,n-1) an[i]=(a[i][0]-'A')*200+(a[i][1]-'0');
    rng(i,0,p-1) bn[i]=(b[i][0]-'A')*200+(b[i][1]-'0');
    rng(i,0,q-1) cn[i]=(c[i][0]-'A')*200+(c[i][1]-'0');
    rng(i,0,p){
        rng(j,0,q){
            if(i==0 && j==0){
                rng(k,0,n) DP[i][j][k]=0;
                continue;
            }
            DP[i][j][0]=0;
            rng(k,1,n){
                int mx=DP[i][j][k-1];
                if(i!=0) mx=max(mx,DP[i-1][j][k]);
                if(j!=0) mx=max(mx,DP[i][j-1][k]);
                if(i!=0 && an[k-1]==bn[i-1]) mx=max(mx,DP[i-1][j][k-1]+1);
                if(j!=0 && an[k-1]==cn[j-1]) mx=max(mx,DP[i][j-1][k-1]+1);
                DP[i][j][k]=mx;
                //cout<<i<<' '<<j<<' '<<k<<' '<<DP[i][j][k]<<'\n';
            }
        }
    }
    cout<<DP[p][q][n]<<'\n';

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

