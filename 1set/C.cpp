
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


void Solve(){
    int r,b;
    cin>>r>>b;
    if(r%2==1 || (r==0 && b%2==1)){
        cout<<"No\n";
        return;
    }
    vc<pii> mv;
    if(b==0){
        rng(i,0,(r-2)/2-1) mv.pb({0,1});
        mv.pb({1,0});
        rng(i,0,(r-2)/2-1) mv.pb({0,-1});
        mv.pb({-1,0});
    }
    else if(r==0){
        rng(i,0,(b-2)/2-1) mv.pb({1,1});
        mv.pb({1,-1});
        rng(i,0,(b-2)/2-1) mv.pb({-1,-1});
        mv.pb({-1,1});
    }
    else if(b%2==0){
        if(r<=b){
            rng(i,0,r-1) mv.pb({0,1});
            rng(i,r,(r+b)/2-1) mv.pb({1,1});
            rng(i,(r+b)/2,r+b/2-1) mv.pb({1,-1});
            rng(i,0,b/2-1) mv.pb({-1,-1});
        }
        else{
            rng(i,0,(r+b)/2-1) mv.pb({0,1});
            rng(i,0,b/2-1) mv.pb({1,-1});
            rng(i,(r+b)/2,r-1) mv.pb({0,-1});
            rng(i,0,b/2-1) mv.pb({-1,-1});
        }
    }
    else{
        if(r<b){
            rng(i,0,r-2) mv.pb({0,1});
            mv.pb({1,0});
            rng(i,r,(r-1+b)/2-1) mv.pb({1,1});
            rng(i,(r-1+b)/2,r-1+(1+b)/2-1) mv.pb({1,-1});
            rng(i,r-1+(1+b)/2,r+b-1) mv.pb({-1,-1});
        }
        else{
            rng(i,0,(r-1+b)/2-1) mv.pb({0,1});
            mv.pb({1,0});
            rng(i,0,r-1-(r-1+b)/2-1) mv.pb({0,-1});
            rng(i,0,b-(b+1)/2-1) mv.pb({1,-1});
            rng(i,b-(b+1)/2,b-1) mv.pb({-1,-1});
        }
    }

    int x=1000000, y=1000000;
    // int x=0, y=0;
    int rcnt=0;
    int bcnt=0;
    cout<<"Yes\n";
    rng(i,0,(int) mv.size()-1){
        if(mv[i].fi==0 || mv[i].se==0){
            rcnt++;
            cout<<"R "<<x<<' '<<y<<'\n';
        }
        else{
            bcnt++;
            cout<<"B "<<x<<' '<<y<<'\n';
        }
        x+=mv[i].fi;
        y+=mv[i].se;
    }
    assert(rcnt==r && bcnt==b);
    // cout<<'\n';
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

