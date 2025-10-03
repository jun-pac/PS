
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

pll flo[N]; // pet, cnt

void Solve(){
    ll n,m;
    cin>>n>>m;
    rng(i,0,n-1) cin>>flo[i].fi;
    rng(i,0,n-1) cin>>flo[i].se;
    sort(flo,flo+n);
    ll mx=0;
    rng(i,0,n-1){
        // using one flower
        ll num=min(flo[i].se, m/flo[i].fi);
        mx=max(mx,num*flo[i].fi);
    }
    rng(i,0,n-2){
        if(flo[i].fi+1!=flo[i+1].fi) continue;
        ll num=min(flo[i].se, m/flo[i].fi);

        ll diff=m-num*flo[i].fi;
        if(diff<flo[i+1].fi) mx=max(mx,num*flo[i].fi + min(diff,min(num,flo[i+1].se)));
        else{
            // cout<<"df "<<i<<' '<<flo[i].fi<<' '<<flo[i].se<<' '<<m<<' '<<num<<' '<<diff<<'\n';
            ll num2=min(flo[i+1].se, diff/flo[i+1].fi);
            diff=diff-num2*flo[i+1].fi;
            ll leftnum2=flo[i+1].se-num2;
            mx=max(mx, num*flo[i].fi + num2*flo[i+1].fi + min(diff,min(num,leftnum2)));
        }
    }
    cout<<mx<<'\n';

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

