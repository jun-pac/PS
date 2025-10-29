
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


vc<pii> new_pos(int x, int y, int a, int b){
    vc<pii> res;
    res.pb({x+a,y+b});
    res.pb({x+a,y-b});
    res.pb({x-a,y+b});
    res.pb({x-a,y-b});
    res.pb({x+b,y+a});
    res.pb({x-b,y+a});
    res.pb({x+b,y-a});
    res.pb({x-b,y-a});
    return res;
}



map<pair<pii,int>,int> visited;
int ans;
int n,a,b,c,d;

void DFS(int x, int y, int p){
    // cout<<"DFS "<<x<<' '<<y<<' '<<p<<'\n';
    vc<pii> st1;
    p=p%2;
    if(p%2==0) st1=new_pos(x,y,a,b);
    else st1=new_pos(x,y,c,d);
    // rng(i,0,7) cout<<st1[i].fi+1<<' '<<st1[i].se+1<<'\n';

    for(pii temp: st1){
        if(0<=temp.fi && temp.fi<n && 0<=temp.se && temp.se<n && !visited[{temp,p}]){
            // cout<<temp.fi<<' '<<temp.se<<'\n';
            if(visited[{temp,1-p}]==0) ans++;
            visited[{temp,p}]=1;
            
            DFS(temp.fi,temp.se,p+1);
        }
    }
}

void Solve(){
    cin>>n>>a>>b>>c>>d;
    ans=1;
    visited[{{0,0},1}]=1;
    DFS(0,0,0);
    if(!visited[{{0,0},0}]){
        visited[{{0,0},0}]=1;
        DFS(0,0,1);
    }
    cout<<ans<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

