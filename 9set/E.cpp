
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

#define N 500030
#define MOD 998244353
#define INF 1000000007 
random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

ll datas[N];
int num1[N], num2[N];

ll DP[N][3][3];

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1){
        ll x;
        cin>>x;
        datas[i]=x%3;
    }
    rng(i,0,2) rng(j,0,2) DP[0][i][j]=0;
    if(datas[0]%3==1) DP[0][1][0]=1;
    else if(datas[0]%3==2) DP[0][0][1]=1;
    else DP[0][0][0]=1;

    rng(k,1,n-1){
        if(datas[k]%3==1){
            DP[k][1][0]=1;
            rng(i,0,2) rng(j,0,2){
                DP[k][i][j]+=DP[k-1][(i+2)%3][j];
            }
        }
        else if(datas[k]%3==2){
            DP[k][0][1]=1;
            rng(i,0,2) rng(j,0,2){
                DP[k][i][j]+=DP[k-1][i][(j+2)%3];
            }
        }
        else{
            DP[k][0][0]=1;
            rng(i,0,2) rng(j,0,2){
                DP[k][i][j]+=DP[k-1][i][j];
            }
        }
    }

    ll res=0;
    rng(i,0,n-1){
        res+=DP[i][0][0]+DP[i][1][0]+DP[i][0][1];
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

