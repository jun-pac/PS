
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

int datas[N];

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    sort(datas,datas+n);
    ll last=0;
    ll res=0;
    for(ll i=0; i<n; i++){
        if(datas[i]!=datas[last]){
            // [last, i-1]
            if(i>=last+3){
                ll k=i-last;
                res+=((k)*(k-1)*(k-2))/6;
            }
            if(i>=last+2){
                ll k=i-last;
                res+=(last)*((k)*(k-1))/2;
            }
            last=i;
        }
    }
    if(n>=last+3){
        ll k=n-last;
        res+=((k)*(k-1)*(k-2))/6;
    }
    if(n>=last+2){
        ll k=n-last;
        res+=(last)*((k)*(k-1))/2;
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

