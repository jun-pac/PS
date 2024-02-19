
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
priority_queue<pair<pll,int>> hpq, wpq;
bool visited[N];

void prep(int n){
    while(!hpq.empty()) hpq.pop();
    while(!wpq.empty()) wpq.pop();
    rng(i,0,n-1){
        hpq.push({{datas[i].fi,datas[i].se},i});
        wpq.push({{datas[i].se,datas[i].fi},i});
    }
    fill(visited,visited+n,0);
}


bool check(ll h, ll w){
    while(!hpq.empty() && visited[hpq.top().se]) hpq.pop();
    while(!wpq.empty() && visited[wpq.top().se]) wpq.pop();
    if(hpq.empty()) return 1;
    if(wpq.empty()) return 1; 
    if(hpq.top().fi.fi==h && hpq.top().fi.se==w) return 1;
    if(wpq.top().fi.se==h && wpq.top().fi.fi==w) return 1;
    //cout<<h<<' '<<w<<' '<<hpq.top().fi.fi<<' '<<hpq.top().fi.se<<' '<<hpq.top().fi.se<<' '<<hpq.top().fi.fi<<'\n';
    if(hpq.top().fi.fi==h){
        auto temp=hpq.top();
        hpq.pop();
        if(w==temp.fi.se) return 1;
        visited[temp.se]=1;
        return check(h,w-temp.fi.se);
    }
    else if(wpq.top().fi.fi==w){
        auto temp=wpq.top();
        wpq.pop();
        if(h==temp.fi.se) return 1;
        visited[temp.se]=1;
        return check(h-temp.fi.se,w);
    }
    return 0;
}

void Solve(){
    int n;
    cin>>n;
    ll area=0, mxx=0, mxy=0;
    vc<pll> ans;
    rng(i,0,n-1) cin>>datas[i].fi>>datas[i].se;
    rng(i,0,n-1) area+=datas[i].fi*datas[i].se;
    rng(i,0,n-1) mxx=max(mxx,datas[i].fi);
    rng(i,0,n-1) mxy=max(mxy,datas[i].se);
    prep(n);
    //cout<<"GO "<<mxx<<' '<<area/mxx<<'\n';
    if(area%mxx==0 && check(mxx, area/mxx)) ans.pb({mxx,area/mxx});
    prep(n);
    if(area%mxy==0 && mxx*mxy != area && check(area/mxy,mxy)) ans.pb({area/mxy, mxy});
    cout<<ans.size()<<'\n';
    rng(i,0,(int)ans.size()-1){
        cout<<ans[i].fi<<' '<<ans[i].se<<'\n';
    }
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

