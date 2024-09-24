
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
__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

#define N 300030
#define MOD 998244353
#define INF 1000000007 

ll datas[N];

void Solve(){
    ll n,k;
    cin>>n>>k;
    rng(i,0,n-1) cin>>datas[i];
    sort(datas,datas+n);
    ll res=0, cnt=0;
    rng(i,0,n-1){
        ll left=k-cnt;
        //cout<<"ce "<<(i+1-min((ll)i,left))<<'\n';
        //cout<<"che "<<cnt<<' '<<datas[i]*n-(i+1-min((ll)i,left))+1<<'\n';
        if(i==n-1 || datas[i+1]!=datas[i]) res=max(res,datas[i]*n-(i+1-min((ll)i,left))+1);
        if(i!=n-1) cnt+=(datas[i+1]-datas[i])*(i+1);
        if(cnt>k){
            cnt=cnt-(datas[i+1]-datas[i])*(i+1);
            ll left=k-cnt;
            ll mn=datas[i]+left/(i+1);
            //cout<<"ok "<<mn*n-((i+1)-left%(i+1))+1<<'\n';
            res=max(res,mn*n-((i+1)-left%(i+1))+1);
            cnt=k+1;
            break;
        }
    }
    if(cnt<=k){
        ll left=k-cnt;
        ll mn=datas[n-1]+left/n;
        //cout<<"this? "<<(mn)*n-(n-left%n)+1<<'\n';
        res=max(res,mn*n-(n-left%n)+1);
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

