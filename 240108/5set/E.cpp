
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
#define INF 1000000007 
#define MOD 1000000007 

int datas[N];
ll DP[100][100]; // [i][j] meams s[0:i] achieved [0:j]th subsequencs

void Solve(){
    int n,m,k;
    cin>>n>>m>>k;
    rng(i,0,n-1){
        cin>>datas[i];
    }
    if(m>100){
        return;
    }   
    rng(i,0,m){
        if(i==0){
            DP[0][0]=1;
            continue;
        }
        DP[i][0]=(k-1)*DP[i-1][0]%MOD;
        rng(j,1,min(n,i)){
            DP[i][j]=(j!=n ? ((k-1)*DP[i-1][j]+DP[i-1][j-1])%MOD : (k*DP[i-1][j]+DP[i-1][j-1])%MOD) ;
        }
    }
    rng(i,0,m){
        rng(j,0,min(n,i)){
            cout<<(DP[i][j]+MOD)%MOD<<' ';

        }
        cout<<endl;
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

