
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

ll a[N], b[N];

void Solve(){
    int n,m; // <=2e5
    cin>>n>>m;
    rng(i,0,n-1) cin>>a[i];
    rng(i,0,m-1) cin>>b[i];
    int mxk=min(min(n,m),(n+m)/3);
    sort(a,a+n);
    sort(b,b+m);
    vc<ll> aval, bval;
    rng(i,0,(n/2)-1){
        aval.pb(a[n-1-i]-a[i]);
    }
    rng(i,0,(m/2)-1){
        bval.pb(b[m-1-i]-b[i]);
    }
    // DP를 써서 뭔가 중간결과물을 만드는건가
    // 이전 스텝에서 많이 바뀌지는 않을 것 같다. violation이 있을 때 하나를 물리고, 원하는 해를 하나 잡는
    ll sum=0;
    int aidx=0, bidx=0;
    cout<<mxk<<'\n';
    rng(i,1,mxk){
        if(aidx>=n/2){
            sum+=bval[bidx++];
        }
        else if(bidx>=m/2){
            sum+=aval[aidx++];
        }
        else{
            if(aval[aidx]>bval[bidx]) sum+=aval[aidx++];
            else sum+=bval[bidx++];
        }
        while(2*aidx+bidx > n){
            sum-=aval[--aidx];
            sum+=bval[bidx++];
        }
        while(2*bidx+aidx > m){
            sum-=bval[--bidx];
            sum+=aval[aidx++];
        }
        cout<<sum<<' ';
    }
    cout<<'\n';
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

