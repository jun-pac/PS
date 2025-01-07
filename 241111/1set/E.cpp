
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

pll aa[1000], bb[1000]; // 각각 capa, cost
ll w;
int n;

ll get_cost(int idx, ll mn){
    ll mul=aa[idx].fi*bb[idx].fi;
    ll num=mn/mul; // 이건 그냥 싼 걸로 하면 됨.
    // 나머지는 최대 100번의 연산으로 찾는다.
    ll mncost=3*min(aa[idx].se*bb[idx].fi,aa[idx].fi*bb[idx].se);
    num=max(num-2,0LL);

    rng(i,0,3*bb[idx].fi-1){
        //aa를 i개를 쓰면 bb는 몇 개를 써야하는가
        ll cur=aa[idx].se*i+bb[idx].se*(cediv(max(0LL,mn-num*mul-aa[idx].fi*i),bb[idx].fi));
        mncost=min(mncost,cur);
    }
    return mncost+num*min(aa[idx].se*bb[idx].fi,aa[idx].fi*bb[idx].se);
}

bool check(ll mn){
    // mn이상의 생산량을 확보하기 위해서 최소의 비용
    ll sum=0;
    rng(i,0,n-1){
        sum+=get_cost(i,mn);
    }
    return w>=sum;
}

void Solve(){
    cin>>n>>w;
    rng(i,0,n-1) cin>>aa[i].fi>>aa[i].se>>bb[i].fi>>bb[i].se;
    ll l=0, r=INF; // INF이상은 불가
    while(l<r){
        ll mid=(l+r+1)>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l<<'\n';
    //cout<<check(4)<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

