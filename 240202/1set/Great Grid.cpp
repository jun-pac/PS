
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

#define N 4040
#define MOD 998244353
#define INF 1000000007 

bool visited[N]; // 
bool state[N]; // 0~n-1은 가로로 뻗어있는 선을 의미 n~n+m은 세로로 뻗어있는 선을 의미
vc<pii> edges[N]; // second가 1이면 다르게 된다는 것

bool DFS(int idx, int st){
    //cout<<idx<<' '<<st<<'\n';
    if(visited[idx]){
        return state[idx]==st;
    }
    visited[idx]=1;
    state[idx]=st;
    for(auto next : edges[idx]){
        if(!DFS(next.fi,st^next.se)) return false;
    }
    return true;
}

void Solve(){
    int n,m,k;
    cin>>n>>m>>k;
    rng(i,0,n+m-1) edges[i].clear();
    rng(i,0,k-1){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        a--, b--, c--, d--;
        assert(a<c);
        assert(a<n && c<n);
        if(b<d){
            edges[a].pb({b+n,1});
            edges[b+n].pb({a,1});
        }
        else{
            edges[a].pb({b-1+n,0});
            edges[b-1+n].pb({a,0});
        }
    }

    // rng(i,0,n+m-1){
    //     cout<<(i<n?"row ":"col ")<<i+1<<" : ";
    //     rng(j,0,(int) edges[i].size()-1){
    //         cout<<"("<<edges[i][j].fi+1<<' '<<edges[i][j].se<<") ";
    //     }
    //     cout<<endl;
    // }
    fill(visited,visited+n+m,0);
    bool flag=1;
    rng(i,0,n+m-1){
        if(!visited[i]){
            //cout<<"?"<<i+1<<'\n';
            if(!DFS(i,1)){
                cout<<"NO\n";
                return;
            }
        }
    }
    cout<<"YES\n";
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

