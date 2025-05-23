
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
// random_device rd; 
// mt19937 gen(rd());
// uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

ll b[N], w[N];
ll bsum[N], wsum[N];


void Solve(){
    int bn, wn;
    cin>>bn>>wn;
    // b>=w
    rng(i,0,bn-1) cin>>b[i];
    rng(i,0,wn-1) cin>>w[i];
    sort(b,b+bn);
    sort(w,w+wn);
    reverse(b,b+bn);
    reverse(w,w+wn);
    rng(i,0,bn-1) bsum[i]=(i==0?0:bsum[i-1])+b[i];
    rng(i,0,wn-1) wsum[i]=(i==0?0:wsum[i-1])+w[i];
    
    int bcnt=0;
    rng(i,0,bn-1){
        if(b[i]>=0) bcnt++;
    }
    int wcnt=0;
    rng(i,0,wn-1){
        if(w[i]>=0) wcnt++;
    }

    ll mx=0;
    rng(i,0,min(bn,wn)){
        ll res=(i==0?0:wsum[i-1]);
        if(i<=bcnt) res+=(bcnt==0?0:bsum[bcnt-1]);
        else res+=(i==0?0:bsum[i-1]);
        mx=max(mx,res);
    }

    cout<<mx<<'\n';

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

