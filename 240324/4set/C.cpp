
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

vc<pii> dir;
vc<int> edges[400040];
string arrow[2];
bool visited[400040];


void Solve(){
    int n;
    cin>>n;
    cin>>arrow[0];
    cin>>arrow[1];
    rng(i,0,2*n-1) edges[i].clear();
    rng(i,0,1){
        rng(j,0,n-1){
            rng(k,0,3){
                int ni=i+dir[k].fi, nj=j+dir[k].se;
                if(0<=ni && ni<2 && 0<=nj && nj<n){
                    nj=nj+(arrow[ni][nj]=='<'?-1:1);
                    edges[i*n+j].pb(ni*n+nj);
                }
            }
        }
    }
    queue<int> q;
    q.push(0);
    fill(visited,visited+2*n,0);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        if(visited[cur]) continue;
        visited[cur]=1;
        if(cur==2*n-1) break;
        for(auto next : edges[cur]){
            if(!visited[next]) q.push(next);
        }
    }
    cout<<(visited[2*n-1]?"YES\n":"NO\n");
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin>>t;
    dir.pb({-1,0});
    dir.pb({1,0});
    dir.pb({0,1});
    dir.pb({0,-1});
    while(t--){
        Solve();
    }
    return 0;
}

