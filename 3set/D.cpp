
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
pii sda[N];
set<pii> st;

void Solve(){
    int n;
    cin>>n;
    st.clear();
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-1) sda[i]={datas[i],-i};
    sort(sda,sda+n);
    reverse(sda,sda+n);

    int mx=-10000;
    //st.insert({-sda[0].se,sda[0].fi});
    //cout<<"val:"<<sda[0].fi<<'\n';
    rng(i,0,n-1){
        int idx=-sda[i].se;
        int val=sda[i].fi;
        //cout<<"val:"<<val<<'\n';
        auto nn=st.upper_bound({idx,val});
        if(nn!=st.end() && next(nn)!=st.end()){
            auto nnn=next(nn);
            mx=max(mx,val+(nn->se)+(nnn->se)-((nnn->fi)-idx));
        }
        if(nn==st.begin()){
            st.insert({idx,val});
            continue;
        }
        auto pp=prev(nn);
        if(nn!=st.end()){
            mx=max(mx,val+(nn->se)+(pp->se)-((nn->fi)-(pp->fi)));
        }
        if(pp!=st.begin()){
            auto ppp=prev(pp);
            mx=max(mx,val+(pp->se)+(ppp->se)-(idx-(ppp->fi)));
        }
        st.insert({idx,val});
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

