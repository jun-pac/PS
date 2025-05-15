
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
ll sum[N];
ll cnt[N];
map<ll,ll> lcnt;

void Solve(){
    ll n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    ll res=0;
    rng(k,1,9){
        // k이하는 +, k+1이상은 -
        // 단 k는 반드시 포함해야 함.
        fill(cnt,cnt+2*n+2,0);
        lcnt.clear();
        ll cur=0;
        ll mulsum=0;
        cnt[n]++;
        rng(i,0,n-1){
            if(datas[i]<=k) cur++;
            else cur--;
            cnt[cur+n]++;
            sum[i]=cur;
        }
        lcnt.clear();
        rng(i,0,n-1){
            ll val=(i==0?0:sum[i-1])+n;
            mulsum-=cnt[val]*lcnt[val];
            cnt[val]--;
            lcnt[val]++;
            // cout<<"de "<<val<<' '<<cnt[val]<<' '<<lcnt[val]<<'\n';
            mulsum+=cnt[val]*lcnt[val];
            if(datas[i]==k){
                // l<=i, r>=i 이면서 sum[r]==(l==0?0:sum[l-1])이면 됨.
                res+=mulsum;
                mulsum=0;
                lcnt.clear();
            }
        }
    }   
    // cout<<n<<' '<<res<<'\n';
    cout<<(n*(n+1))/2-res<<'\n';
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

