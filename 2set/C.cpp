
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define pb push_back
template<class t> using vc=vector<t>;
typedef long long ll;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

#define N 1000
#define MOD 998244353
#define INF 1000000007 
random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); 

vc<int> edges[N];
int pre[N];
bool visited[N];
int datas[N][N];

bool DFS(int idx){
    // Bipartite matching
    if(visited[idx]) return false;
    visited[idx]=true;
    for(int i=0; i<edges[idx].size(); i++){
        int next=edges[idx][i];
        if(pre[next]==-1 || (!visited[pre[next]] && DFS(pre[next]))){
            pre[next]=idx;
            return true;
        }
    }
    return false;
}



int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    rng(i,0,k-1) edges[i].clear();
    rng(i,0,n-1){
        rng(j,0,k-1){
            cin>>datas[i][j];
            if(datas[i][j]==1) edges[j].pb(i);
        }
    }
    fill(pre,pre+n,-1);
    int res=0;
    int cnt=0;
    for(int i=k-1;i>=0;i--){
        fill(visited,visited+k,0);
        if(i>cnt && DFS(i)){
            res++;
            cnt++;
        }
        else cnt=max(cnt-1,0);
        //cout<<i+1<<' '<<res<<'\n';
    }
    cout<<res<<'\n';
    return 0;
}


