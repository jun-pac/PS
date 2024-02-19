
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

ll datas[N];
ll n;

ll val(ll idx, ll k){
    // k번의 연산을 하고 난 후의 idx번째
    //cout<<"visit "<<idx<<' '<<k<<endl;
    if(k==0) return idx+1;
    // if(idx>=datas[n-1]+1-n){
    //     return idx+1+k*n;
    // }
    ll l=0, r=n+idx;
    // 기본적으로 idx'은 idx보다 큰 값이네
    // idx앞에 얼마나 제거가 돼있는지를 판단하고, 
    while(l<r){
        ll mid=(l+r)>>1;
        // mid였다면 얼마나 제거가 돼있겠는가?
        // datas에 딱 겹치면 애매... 그 앞으로 나오도록 강제해야함
        int pos=upper_bound(datas,datas+n,mid)-datas-1;
        if(mid-pos-1>=idx) r=mid;
        else l=mid+1;
    }
    return val(l,k-1);
}

void Solve(){
    int k;
    cin>>n>>k;
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-1) datas[i]--;
    cout<<val(0,k)<<'\n';
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

