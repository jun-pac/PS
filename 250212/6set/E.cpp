
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

ll price[N];
ll nums[N];


void Solve(){
    ll n,m;
    cin>>n>>m;
    rng(i,0,n-1) cin>>price[i];
    sort(price,price+n);
    double mp=((double)m)*((double)price[0]); 
    ll l=0, r=2*((ll)sqrt(mp))+10000000; // k^2 p_i를 기준으로 생각하는 것. 하나를 추가로 구매하는 데 mid이하면 다 샀다고 치자.
    // 이거 marginal임.
    while(l<r){
        ll mid=(l+r+1)/2;
        ll cost=0;
        rng(i,0,n-1){
            ll num=(mid/price[i]+1)/2;
            ll temp=num*num*price[i];
            cost=cost+temp;
            if(cost>m) break;
        }
        if(cost>m) r=mid-1;
        else l=mid;
    }
    ll res=0, cost=0;
    rng(i,0,n-1){
        ll num=(l/price[i]+1)/2;
        ll temp=num*num*price[i];
        cost=cost+temp;
        res+=num;
        nums[i]=num;
    }
    assert(cost<=m);
    priority_queue<ll> pq;
    rng(i,0,n-1){
        pq.push(-((2*nums[i]+1)*price[i]));
    }
    while(!pq.empty()){
        if(cost-pq.top() <= m){
            cost-=pq.top();
            pq.pop();
            res++;
        }
        else break;
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

