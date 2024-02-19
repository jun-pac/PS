
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

#define N 300030
#define MOD 998244353
#define INF 1000000007 

int as[N];
int bs[N];

void Solve(){
    int n,k,d;
    cin>>n>>k>>d;
    rng(i,0,n-1) cin>>as[i];
    rng(i,0,k-1) cin>>bs[i];
    
    int mx=0;
    rng(i,0,min(2*n+2,d-1)){
        // i번 더하고, 1번 점수 얻고, 나머지작업
        int curcnt=0;
        rng(j,0,n-1) if(j+1==as[j]) curcnt++;
        //cout<<"te "<<i<<' '<<curcnt<<'\n';
        mx=max(mx,curcnt+(d-1-i)/2);
        rng(j,0,bs[i%k]-1){
            as[j]++;
        }
    }
    cout<<mx<<'\n';
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

