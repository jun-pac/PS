
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
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

#define N 200030
#define MOD 998244353
#define INF 1000000007 

ll DP[N][10];

void Solve(){
    int n;
    cin>>n;
    int x;
    rng(i,0,n-1){
        cin>>x;
        if(x%2==1){
            DP[i+1][0]=DP[i][0]+1;
            DP[i+1][1]=DP[i][1];
            DP[i+1][2]=DP[i][2];
            DP[i+1][3]=DP[i][3]+DP[i][1];
            DP[i+1][4]=DP[i][4]+DP[i][0];
            DP[i+1][5]=DP[i][5];
            DP[i+1][6]=DP[i][6];
            DP[i+1][7]=DP[i][7]+DP[i][2]+DP[i][6];
            DP[i+1][8]=DP[i][8]+DP[i][3]+DP[i][7];
            DP[i+1][9]=DP[i][9];
        }
        else{
            DP[i+1][0]=DP[i][0];
            DP[i+1][1]=DP[i][1]+1;
            DP[i+1][2]=DP[i][2]+DP[i][0];
            DP[i+1][3]=DP[i][3];
            DP[i+1][4]=DP[i][4];
            DP[i+1][5]=DP[i][5]+DP[i][1];
            DP[i+1][6]=DP[i][6]+DP[i][4]+DP[i][8];
            DP[i+1][7]=DP[i][7];
            DP[i+1][8]=DP[i][8];
            DP[i+1][9]=DP[i][9]*2+DP[i][5];
        }
        rng(j,0,9) DP[i+1][j]%=MOD;
    }
    cout<<((DP[n][6]+DP[n][7]+DP[n][8]+DP[n][9])%MOD+MOD)%MOD<<'\n';

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

