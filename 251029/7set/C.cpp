
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

string s;
bool DP[2];

void Solve(){
    int n;
    cin>>n;
    cin>>s;
    DP[0]=1, DP[1]=1;
    int idx=0;

    int last0, last1;

    while(idx<n && s[idx]=='1') idx++;
    last1=idx;

    while(idx<n && s[idx]=='0') idx++;
    last0=idx;

    if(last1!=0 && last0-last1==1) DP[0]=0;
    

    // DP[0] left, dp[1] right
    while(idx<n){
        while(idx<n && s[idx]=='1') idx++;
        if(idx==n){
            DP[1] = 0;
            break;
        }
        if(idx-last0>=2) DP[1]=0; // 1...1

        last1=idx;

        while(idx<n && s[idx]=='0') idx++;
        if(idx - last1 == 1){
            // 1..1 0 1..
            bool p0=DP[0];
            DP[0]=(DP[1] && last1-last0==1);
            DP[1]=(p0);
        }
        else{
            bool temp=(DP[1] && last1-last0==1)||(DP[0]);
            DP[0]=DP[1]=temp;
        }
        last0=idx;
    }   
    if(DP[0]||DP[1]) cout<<"YES\n";
    else cout<<"NO\n";
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

