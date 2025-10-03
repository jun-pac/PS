
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
random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

int datas[N];
ll DP[3030][3030];
ll DPsum[3030][3030]; // from the smallest 

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    DP[0][datas[0]]=1;
    rng(i,1,n) DPsum[0][i]=DPsum[0][i-1]+DP[0][datas[0]];

    rng(i,1,n-1){
        // left to right influence
        int mx=min(datas[i-1], datas[i]-1);
        rng(j,1,mx){
            DP[i][j]=DPsum[i-1][j];
        }
        int lastpos=i;
        while(lastpos>=0 && datas[lastpos]>=datas[i]) lastpos--;
        DP[i][datas[i]]=DPsum[i-1][n]; // all is possible
        

        rng(j,1,n) DPsum[i][j]=(DPsum[i][j-1]+DP[i][j])%MOD;
    }

    // cout<<(DP[n-1]%MOD+MOD)%MOD<<'\n';
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

