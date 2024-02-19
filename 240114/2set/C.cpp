
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

vc<int> edges[N];
int color[N];
pii rcol[N];
set<pii> DP[N]; // {color, idx}꼴로 넣는다.
int DFS_res;
int n;

bool DFS(int idx, int p){
    bool res=1;
    DP[idx].insert({color[idx],idx});
    for(auto next : edges[idx]){
        if(next!=p){
            if(!DFS(next, idx)) res=0;
            if(DP[idx].size()<DP[next].size()) swap(DP[idx],DP[next]);            
        }
    }   
    if(!res) return false;
    for(auto next : edges[idx]){
        if(next!=p){
            for(auto [c,i] : DP[next]){
                auto it = DP[idx].upper_bound(make_pair(c,-1));
                if(it!=DP[idx].end()) cout<<"cur next ele "<<idx+1<<' '<<next+1<<' '<<(*it).fi<<' '<<(*it).se<<'\n';
                if(it!=DP[idx].end() && (*it).fi==c) return false;
                DP[idx].insert({c,i});
            }
        }
    }
    cout<<"idx "<<idx+1<<'\n';
    for(auto [a,b] : DP[idx]){
        cout<<"color idx : "<<a+1<<' '<<b+1<<'\n';
    }
    if(DP[idx].size()==n){
        DFS_res=idx;
        return false;
    }
    return true;
}

void Solve(){
    int a,b;
    cin>>n;
    rng(i,0,2*n-1) edges[i].clear();
    rng(i,0,n-1) rcol[i].fi=-1;
    rng(i,0,2*n-1){
        cin>>a;
        color[i]=a-1;
        if(rcol[color[i]].fi==-1) rcol[color[i]].fi=i;
        else rcol[color[i]].se=i;
    }
    rng(i,0,2*n-2){
        cin>>a>>b;
        a--, b--;
        edges[a].pb(b);
        edges[b].pb(a);
    }

    int s=0;
    rng(i,0,n-1) cout<<rcol[i].fi+1<<' '; cout<<'\n';
    rng(i,0,n-1) cout<<rcol[i].se+1<<' '; cout<<'\n';
    rng(i,0,2*n-1) if(edges[i].size()==1) s=i;

    cout<<"start "<<s+1<<'\n';
    rng(i,0,2*n-1) DP[i].clear();
    DFS_res=-1;
    DFS(s,-1);
    if(DFS_res!=-1){
        cout<<"res1 ; "<<DFS_res<<'\n';
        for(auto [a,b] : DP[DFS_res]){
            cout<<b+1<<' ';
        }
        cout<<'\n';
    }
    else{
        rng(i,0,2*n-1) DP[i].clear();
        DFS_res=-1;
        cout<<"second try : "<<rcol[color[s]].fi+rcol[color[s]].se-s+1<<'\n';
        DFS(rcol[color[s]].fi+rcol[color[s]].se-s,-1);
        if(DFS_res!=-1){
            cout<<"res2 ; "<<DFS_res<<'\n';
            for(auto [a,b] : DP[DFS_res]){
                cout<<b+1<<' ';
            }
            cout<<'\n';
        }
        else cout<<-1<<'\n';
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

