
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
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

#define N 100030
#define MOD 998244353
#define INF 1000000007 

string s;
int sz[N];
vector<int> edges[N]; 
vector<int> r_edges[N];
int scc_sz[N];
int scc[N];
int order[N];
bool visited[N];
int cnt, scc_cnt; // Number of SCC's
int n; // Number of actual nodes in graph

void DFS(int idx){
    visited[idx]=true;
    for(int i=0; i<edges[idx].size(); i++) if(!visited[edges[idx][i]]) DFS(edges[idx][i]);
    order[cnt]=idx; cnt++;
}

void r_DFS(int idx){
    visited[idx]=true;
    scc[idx]=cnt;
    for(int i=0; i<r_edges[idx].size(); i++) if(!visited[r_edges[idx][i]]) r_DFS(r_edges[idx][i]);
}

// Kosaraju's algorithm. Set n, edges, r_edges before call this function.
void get_scc(){
    fill(visited, visited+n, false), cnt=0;
    for(int i=0; i<n; i++) if(!visited[i]) DFS(i);
    fill(visited, visited+n, false), cnt=0;
    for(int i=n-1; i>=0; i--) if(!visited[order[i]]) {r_DFS(order[i]); cnt++;}
    scc_cnt=cnt;
}

vc<int> res;

int sz_DFS(int idx){
    if(visited[idx]) return sz[idx];
    visited[idx]=1;
    int res=(s[idx]=='1');
    for(auto next : r_edges[idx]){
        res+=sz_DFS(next);
    }
    for(auto next : edges[idx]){
        if(scc_sz[scc[next]]!=1) sz[next]+=res;
    }
    return sz[idx]=res;
}

void Solve(){
    int a;
    cin>>n;
    rng(i,0,n-1) edges[i].clear();
    rng(i,0,n-1) r_edges[i].clear();
    fill(sz,sz+n,0);
    fill(scc_sz, scc_sz+n, 0);
    res.clear();

    cin>>s;
    rng(i,0,n-1){
        cin>>a;
        a--;
        edges[i].pb(a);
        r_edges[a].pb(i);
    }

    get_scc();
    rng(i,0,n-1) scc_sz[scc[i]]++;

    fill(visited,visited+n,0);
    rng(i,0,n-1){
        if(scc_sz[scc[i]]==1 && !visited[i]) sz_DFS(i);
    }
    rng(i,0,n-1){
        if(scc_sz[scc[i]]==1 && sz[i]%2==1){
            res.pb(i);
        }
    }
    
    // cycle에 대해서는 off의 아무 점이나... 흠
    rng(i,0,n-1){
        if(scc_sz[scc[i]]!=1){
            if(sz[i]%2==1) s[i]='0'+'1'-s[i];
        }
    }
    // rng(i,0,n-1) cout<<sz[i]<<' '; cout<<'\n';
    // rng(i,0,(int)res.size()-1) cout<<res[i]+1<<' '; cout<<'\n';

    // 본격적으로 cycle에서 결정하는 것
    fill(visited,visited+n,0);
    rng(i,0,n-1){
        if(scc_sz[scc[i]]!=1 && !visited[i]){
            int cnt_odd=0, cnt_even=0, cnt_one=0;
            int cur=i;
            visited[cur]=1;
            vc<int> temp_odd, temp_even;

            if(s[cur]=='1') cnt_one++;
            if(cnt_one%2==1) temp_even.pb(cur);
            else temp_odd.pb(cur);
            cur=edges[cur][0];
            while(cur!=i){
                visited[cur]=1;
                if(s[cur]=='1') cnt_one++;
                if(cnt_one%2==1){
                    temp_even.pb(cur);
                }
                else{
                    temp_odd.pb(cur);
                }
                //assert(scc_sz[scc[cur]]!=1 && edges[cur].size()==1);
                cur=edges[cur][0];
            }
            if(cnt_one%2!=0){
                cout<<-1<<'\n';
                return;
            }
            if(temp_odd.size()<temp_even.size()){
                for(auto k : temp_odd) res.pb(k);
            }
            else{
                for(auto k : temp_even) res.pb(k);
            }
        }
    }
    cout<<res.size()<<'\n';
    rng(i,0,(int)res.size()-1){
        cout<<res[i]+1<<' ';
    }
    cout<<'\n';
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

