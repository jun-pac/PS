
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

// criterion k를 정해서 종말지점에 max가 되도록.
// 볼록성이 있는가?

#define N_ 300030
ll datas[N_], sum[N_];
ll lmx[N_], rmx[N_];
void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-1) sum[i]=(i==0?0:sum[i-1])+datas[i];
    rng(i,0,n-1) lmx[i]=max((i==0?0LL:lmx[i-1]),sum[i]);
    gnr(i,n-1,0) rmx[i]=max((i==n-1?0LL:rmx[i+1]),sum[i]);
    ll res=1000000007, mx=0;
    rng(i,0,n-1){
        if(lmx[i]-sum[i]>mx){
            mx=lmx[i]-sum[i];
            res=lmx[i];
        }
    }
    cout<<res<<'\n';
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

