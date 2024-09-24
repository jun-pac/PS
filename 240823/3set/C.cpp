
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

pll datas[N];

void Solve(){
    ll n,k;
    cin>>n>>k;
    rng(i,0,n-1) cin>>datas[i].fi;
    rng(i,0,n-1) cin>>datas[i].se;
    sort(datas,datas+n);
    int last_can=-1;
    gnr(i,n-1,0){
        if(datas[i].se==1){
            last_can=i;
            break;
        }
    }
    if(last_can==-1){
        // 아무것도 없다
        cout<<datas[(n-2)/2].fi+datas[n-1].fi<<'\n';
        return;
    }
    ll l=0, r=datas[n-1].fi;
    ll mx;
    while(l<r){
        ll mid=(l+r+1)/2; // mid로 만드는 게 가능한지
        vc<ll> slo;
        ll cnt=0;
        bool flag=1;
        rng(i,0,n-1){
            if(datas[i].se==0 && datas[i].fi<mid) cnt++;
            if(datas[i].se==1 && datas[i].fi<mid) slo.push_back(mid-datas[i].fi);
        }
        sort(all(slo));
        if(cnt>(n-2)/2) flag=0;
        else if(cnt+slo.size()<=(n-2)/2) flag=1;
        else{
            ll sum=0;
            ll num=cnt+(ll)slo.size()-(n-2)/2;
            rng(i,0,num-1) sum+=slo[i];
            if(sum>k) flag=0;
            else flag=1;
        }
        if(flag) l=mid;
        else r=mid-1;
    }
    mx=datas[n-1].fi+l;

    // 제일 큰 것을 크게
    //cout<<"last can "<<last_can<<'\n';
    datas[last_can].fi+=k;
    //cout<<"mod "<<datas[last_can].fi<<'\n';
    sort(datas,datas+n);
    //cout<<"? "<<datas[(n-2)/2].fi<<' '<<datas[n-1].fi<<'\n';
    mx=max(mx,datas[(n-2)/2].fi+datas[n-1].fi);
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

