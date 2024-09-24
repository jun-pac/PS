
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

#define N 10030
#define MOD 998244353
#define INF 1000000007 
//__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))


pll datas[N];
int idx=1;
map<ll,ll> mp;
ll r_mp[N];
vc<int> edges[N];
vector<int> rev_edges[N]; // To find maximum independent set.
int pre[N];
bool visited[N];
ll ans[N];

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



void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1){
        ll a,b;
        cin>>a>>b;
        datas[i]={a,b};
        if(mp[a+b]==0){
            r_mp[idx]=a+b;
            mp[a+b]=idx;
            edges[i].pb(idx);
            idx++;
        }
        else{
            edges[i].pb(mp[a+b]);
        }
        if(mp[a*b]==0){
            r_mp[idx]=a*b;
            mp[a*b]=idx;
            edges[i].pb(idx);
            idx++;
        }
        else{
            edges[i].pb(mp[a*b]);
        }
        if(mp[a-b]==0){
            r_mp[idx]=a-b;
            mp[a-b]=idx;
            edges[i].pb(idx);
            idx++;
        }
        else{
            edges[i].pb(mp[a-b]);
        }
    }
    rng(i,0,n-1){
        for(auto next : edges[i]) rev_edges[next].pb(i);
    }
    int cnt=0;
    fill(pre,pre+idx+1,-1);
    rng(i,0,n-1){
        fill(visited,visited+n,0);
        if(DFS(i)) cnt++;
    }
    if(cnt!=n) cout<<"impossible\n";
    else{
        int k=0;
        rng(next,1,idx-1){
            if(pre[next]!=-1){
                ans[pre[next]]=r_mp[next];
                k++;
            }
        }
        assert(k==n);
        rng(i,0,n-1){
            if(ans[i]==datas[i].fi+datas[i].se){
                cout<<datas[i].fi<<" + "<<datas[i].se<<" = "<<ans[i]<<'\n';
            }
            else if(ans[i]==datas[i].fi*datas[i].se){
                cout<<datas[i].fi<<" * "<<datas[i].se<<" = "<<ans[i]<<'\n';
            }
            else if(ans[i]==datas[i].fi-datas[i].se){
                cout<<datas[i].fi<<" - "<<datas[i].se<<" = "<<ans[i]<<'\n';
            }
            else{
                assert(false);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

