
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
//__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

int n;

void Solve(){

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);\
    cin>>n;
    ll J;
    vector<ll> others(n-1);
    for(int i=0;i<n;i++){
        if(i==0){
            cin>>J;
        }else{
            cin>>others[i-1];
        }
    }
    sort(others.rbegin(), others.rend());
    ll ans = LLONG_MAX;
    ll cnt = 1;
    for(ll i=2;i<n;(i<<=1)){
        ll alpha = others[0] - others[1];

        ll beta = others[0] - (others[i-1] + alpha);
        ll gamma = others[0] + beta;
        
        ll targ = J - cnt + 1;
        ans = min(ans, max((ll)0, (targ - gamma)) * 2 + alpha + 2 * beta + cnt-1);

        cnt++;
    }
    cout<<ans;
    return 0;
}

