
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
#define INF 1000000000000007 
ll datas[399][300];
ll DP[201][201]; // [i][j]
ll temp[201][201]; // [j][num_left]; // 현재의 num left한 횟수임.
void Solve(){
    ll n,m,lambda;
    cin>>n>>m>>lambda;
    rng(i,0,n-1){
        rng(j,0,m-1) cin>>datas[i][j];
    }
    
    rng(j,0,m-1){
        DP[0][j]=INF;
        rng(k,0,m-1){
            if(j!=0) temp[j][k]=datas[0][(j+k)%m]+temp[j-1][k];
            else temp[j][k]=datas[0][(j+k)%m];
            DP[0][j]=min(DP[0][j],temp[j][k]+k*lambda);
        }
    }
    rng(i,1,n-1){
        rng(j,0,m-1){
            DP[i][j]=INF;
            rng(k,0,m-1){
                // datas[i][(j+k)%m]의 값을 읽는다.
                if(j!=0) temp[j][k]=datas[i][(j+k)%m]+min(DP[i-1][j],temp[j-1][k]);
                else temp[j][k]=datas[i][(j+k)%m]+DP[i-1][j];
                DP[i][j]=min(DP[i][j],temp[j][k]+k*lambda);
            }
        }

    }
    cout<<DP[n-1][m-1]<<'\n';
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

