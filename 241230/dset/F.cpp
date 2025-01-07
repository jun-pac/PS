
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
// random_device rd; 
// mt19937 gen(rd());
// uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

string s,t;

int DP[N][41]; // min number. {20을 중심으로 [-k,k]만 관심영역}

void Solve(){
    int k;
    cin>>k>>s>>t;
    int n=s.size();
    int m=t.size();
    if(abs(n-m)>k){
        cout<<"No\n";
    }
    else{
        rng(i,0,n-1) fill(DP[i],DP[i]+41,INF);
        rng(i,0,n-1){
            rng(j,max(0,i-k),min(m-1,i+k)){
                if(s[i]==t[j]){
                    if(i==j && i==0) DP[i][j-i+20]=0;
                    else if(i==0 || j==0) DP[i][j-i+20]=max(i,j);
                    else DP[i][j-i+20]=DP[i-1][j-i+20];
                }
                else{
                    if(i==j && i==0) DP[i][j-i+20]=1;
                    else if(i==0) DP[i][j-i+20]=min(j+1, DP[i][j-1-i+20]+1);
                    else if(j==0) DP[i][j-i+20]=min(i+1, DP[i-1][j-i+1+20]+1);
                    else DP[i][j-i+20]=min(min(DP[i-1][j-i+1+20],DP[i][j-1-i+20]), DP[i-1][j-i+20])+1;
                }
                // cout<<"DP "<<i<<' '<<j<<' '<<DP[i][j-i+20]<<'\n';
            }
        }
        if(DP[n-1][m-n+20]<=k) cout<<"Yes\n";
        else cout<<"No\n";
        // cout<<DP[n-1][m-n+20]<<'\n';
    }
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

