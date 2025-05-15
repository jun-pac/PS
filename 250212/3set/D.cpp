
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

ll datas[N];

void Solve(){
    ll n,dist,tar;
    cin>>n>>dist>>tar;
    // initial crow position: 0
    rng(i,0,n-1) cin>>datas[i];
    // greedy solution.
    dist*=2;
    tar*=2;
    rng(i,0,n-1) datas[i]*=2;

    ll curt=datas[0], curx=dist; // After datas[0] time, it teleports to the position dist.
    int idx=1;
    while(idx<n){
        ll l=datas[idx]-curt;
        ll r=datas[idx]+curt;
        if(l<=curx && curx<=r){
            curx=curx+dist;
        }
        else if(r<=curx && curx<=r+dist){
            curx=r+dist;
        }
        else if(curx<=l){
            // curx can mv toward right dir in 1 m/s
            // l can do that
            if((l+curx)/2>=tar){
                cout<<(l+curx)/2-curx+curt<<'\n';
                return;
            }
            curt+=(l-curx)/2;
            curx=(l+curx)/2+dist;
            // curt and curx has same parity
        }
        if(curx>=tar){
            cout<<curt<<'\n';
            return;
        }
        idx++;
    }
    cout<<curt+(tar-curx)<<"\n";
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

